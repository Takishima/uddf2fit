#include "uddf2fit/uddf_parser.hpp"
#include <pugixml.hpp>
#include <charconv>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace uddf2fit {

namespace {

// Helper to parse a double from a string
auto parse_double(const char* str) -> std::optional<double> {
    if (!str || !*str) return std::nullopt;
    double value;
    auto [ptr, ec] = std::from_chars(str, str + std::strlen(str), value);
    if (ec == std::errc{}) {
        return value;
    }
    // Fallback to strtod for scientific notation
    char* end;
    value = std::strtod(str, &end);
    if (end != str) {
        return value;
    }
    return std::nullopt;
}

// Parse gas definitions from <gasdefinitions> element
void parse_gas_definitions(pugi::xml_node gas_defs, UddfDocument& doc) {
    for (auto mix : gas_defs.children("mix")) {
        UddfGasMix gas;
        gas.id = mix.attribute("id").as_string();

        if (auto name_node = mix.child("name")) {
            gas.name = name_node.text().as_string();
        }

        if (auto o2_node = mix.child("o2")) {
            if (auto val = parse_double(o2_node.text().as_string())) {
                gas.o2_fraction = *val;
            }
        }

        if (auto he_node = mix.child("he")) {
            if (auto val = parse_double(he_node.text().as_string())) {
                gas.he_fraction = *val;
            }
        }

        if (auto n2_node = mix.child("n2")) {
            if (auto val = parse_double(n2_node.text().as_string())) {
                gas.n2_fraction = *val;
            }
        }

        // Calculate N2 if not specified
        if (gas.n2_fraction == 0.0 && gas.o2_fraction > 0.0) {
            gas.n2_fraction = 1.0 - gas.o2_fraction - gas.he_fraction;
        }

        doc.gases.push_back(std::move(gas));
    }
}

// Parse location from <geography> element
auto parse_location(pugi::xml_node geo) -> Location {
    Location loc;

    if (auto lat_node = geo.child("latitude")) {
        loc.latitude = parse_double(lat_node.text().as_string());
    }
    if (auto lon_node = geo.child("longitude")) {
        loc.longitude = parse_double(lon_node.text().as_string());
    }
    if (auto alt_node = geo.child("altitude")) {
        loc.altitude = parse_double(alt_node.text().as_string());
    }

    return loc;
}

// Parse dive sites from <divesite> element
void parse_dive_sites(pugi::xml_node divesite, UddfDocument& doc) {
    for (auto site : divesite.children("site")) {
        DiveSite ds;
        ds.id = site.attribute("id").as_string();

        if (auto name_node = site.child("name")) {
            ds.name = name_node.text().as_string();
        }

        if (auto geo = site.child("geography")) {
            ds.location = parse_location(geo);
        }

        doc.dive_sites.push_back(std::move(ds));
    }
}

// Parse a single waypoint
auto parse_waypoint(pugi::xml_node wp) -> Waypoint {
    Waypoint waypoint;

    if (auto dt_node = wp.child("divetime")) {
        if (auto val = parse_double(dt_node.text().as_string())) {
            waypoint.divetime = *val;
        }
    }

    if (auto depth_node = wp.child("depth")) {
        if (auto val = parse_double(depth_node.text().as_string())) {
            waypoint.depth = *val;
        }
    }

    if (auto temp_node = wp.child("temperature")) {
        waypoint.temperature = parse_double(temp_node.text().as_string());
    }

    if (auto press_node = wp.child("tankpressure")) {
        waypoint.tank_pressure = parse_double(press_node.text().as_string());
    }

    if (auto alarm_node = wp.child("alarm")) {
        waypoint.alarm = alarm_node.text().as_string();
    }

    if (auto switch_node = wp.child("switchmix")) {
        waypoint.gas_switch_ref = switch_node.attribute("ref").as_string();
    }

    return waypoint;
}

// Parse information before dive
auto parse_info_before(pugi::xml_node info) -> InformationBeforeDive {
    InformationBeforeDive result;

    if (auto dt_node = info.child("datetime")) {
        result.datetime = dt_node.text().as_string();
    }

    if (auto site_link = info.child("link")) {
        result.divesite_ref = site_link.attribute("ref").as_string();
    }

    if (auto si_node = info.child("surfaceintervalbeforedive")) {
        if (auto passedtime = si_node.child("passedtime")) {
            result.surface_interval = parse_double(passedtime.text().as_string());
        }
    }

    if (auto air_temp = info.child("airtemperature")) {
        result.air_temperature = parse_double(air_temp.text().as_string());
    }

    return result;
}

// Parse information after dive
auto parse_info_after(pugi::xml_node info) -> InformationAfterDive {
    InformationAfterDive result;

    if (auto depth_node = info.child("greatestdepth")) {
        result.greatest_depth = parse_double(depth_node.text().as_string());
    }

    if (auto avg_node = info.child("averagedepth")) {
        result.average_depth = parse_double(avg_node.text().as_string());
    }

    if (auto dur_node = info.child("diveduration")) {
        result.dive_duration = parse_double(dur_node.text().as_string());
    }

    if (auto temp_node = info.child("lowesttemperature")) {
        result.lowest_temperature = parse_double(temp_node.text().as_string());
    }

    if (auto notes_node = info.child("notes")) {
        if (auto para = notes_node.child("para")) {
            result.notes = para.text().as_string();
        } else {
            result.notes = notes_node.text().as_string();
        }
    }

    return result;
}

// Parse equipment used in a dive
void parse_equipment(pugi::xml_node info_before, Dive& dive) {
    if (auto equip = info_before.child("equipmentused")) {
        for (auto scuba_set : equip.children("leadquantity")) {
            // Skip lead quantity entries
        }

        // Look for tank data in equipment configuration
        if (auto divebase = equip.child("divebase")) {
            for (auto tank_node : divebase.children("tankdata")) {
                EquipmentUsed eq;

                if (auto link = tank_node.child("link")) {
                    eq.gas_ref = link.attribute("ref").as_string();
                }

                if (auto vol = tank_node.child("tankvolume")) {
                    if (auto val = parse_double(vol.text().as_string())) {
                        eq.tank_volume = *val;
                    }
                }

                if (auto ps = tank_node.child("tankpressurebegin")) {
                    if (auto val = parse_double(ps.text().as_string())) {
                        eq.tank_pressure_start = *val;
                    }
                }

                if (auto pe = tank_node.child("tankpressureend")) {
                    if (auto val = parse_double(pe.text().as_string())) {
                        eq.tank_pressure_end = *val;
                    }
                }

                dive.equipment.push_back(std::move(eq));
            }
        }
    }
}

// Parse a single dive
auto parse_dive(pugi::xml_node dive_node) -> Dive {
    Dive dive;
    dive.id = dive_node.attribute("id").as_string();

    // Parse information before dive
    if (auto info = dive_node.child("informationbeforedive")) {
        dive.info_before = parse_info_before(info);
        parse_equipment(info, dive);
    }

    // Parse samples (waypoints)
    if (auto samples = dive_node.child("samples")) {
        for (auto wp : samples.children("waypoint")) {
            dive.waypoints.push_back(parse_waypoint(wp));
        }
    }

    // Parse information after dive
    if (auto info = dive_node.child("informationafterdive")) {
        dive.info_after = parse_info_after(info);
    }

    return dive;
}

// Parse profile data containing repetition groups and dives
void parse_profile_data(pugi::xml_node profile, UddfDocument& doc) {
    for (auto rg : profile.children("repetitiongroup")) {
        RepetitionGroup group;
        group.id = rg.attribute("id").as_string();

        for (auto dive : rg.children("dive")) {
            group.dives.push_back(parse_dive(dive));
        }

        doc.repetition_groups.push_back(std::move(group));
    }
}

} // namespace

auto UddfParser::parse(const std::filesystem::path& filename)
    -> std::optional<UddfDocument> {

    pugi::xml_document xml_doc;
    pugi::xml_parse_result result = xml_doc.load_file(filename.c_str());

    if (!result) {
        error_message_ = "Failed to parse XML: ";
        error_message_ += result.description();
        error_message_ += " at offset ";
        error_message_ += std::to_string(result.offset);
        return std::nullopt;
    }

    // Find the root uddf element
    pugi::xml_node uddf = xml_doc.child("uddf");
    if (!uddf) {
        // Try with namespace prefix
        for (auto child : xml_doc.children()) {
            std::string name = child.name();
            if (name == "uddf" || name.ends_with(":uddf")) {
                uddf = child;
                break;
            }
        }
    }

    if (!uddf) {
        error_message_ = "No <uddf> root element found";
        return std::nullopt;
    }

    UddfDocument doc;
    doc.version = uddf.attribute("version").as_string();

    // Parse gas definitions
    if (auto gas_defs = uddf.child("gasdefinitions")) {
        parse_gas_definitions(gas_defs, doc);
    }

    // Parse dive sites
    if (auto divesite = uddf.child("divesite")) {
        parse_dive_sites(divesite, doc);
    }

    // Parse profile data (contains the actual dives)
    if (auto profile = uddf.child("profiledata")) {
        parse_profile_data(profile, doc);
    }

    return doc;
}

auto UddfParser::parse_string(const std::string& content)
    -> std::optional<UddfDocument> {

    pugi::xml_document xml_doc;
    pugi::xml_parse_result result = xml_doc.load_string(content.c_str());

    if (!result) {
        error_message_ = "Failed to parse XML: ";
        error_message_ += result.description();
        return std::nullopt;
    }

    pugi::xml_node uddf = xml_doc.child("uddf");
    if (!uddf) {
        for (auto child : xml_doc.children()) {
            std::string name = child.name();
            if (name == "uddf" || name.ends_with(":uddf")) {
                uddf = child;
                break;
            }
        }
    }

    if (!uddf) {
        error_message_ = "No <uddf> root element found";
        return std::nullopt;
    }

    UddfDocument doc;
    doc.version = uddf.attribute("version").as_string();

    if (auto gas_defs = uddf.child("gasdefinitions")) {
        parse_gas_definitions(gas_defs, doc);
    }

    if (auto divesite = uddf.child("divesite")) {
        parse_dive_sites(divesite, doc);
    }

    if (auto profile = uddf.child("profiledata")) {
        parse_profile_data(profile, doc);
    }

    return doc;
}

} // namespace uddf2fit
