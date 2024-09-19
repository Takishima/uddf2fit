#include "uddf2fit/uddf2fit.hpp"

#include <filesystem>
#include <iostream>
#include <unordered_map>

#include "uddf2fit/load.hpp"
#include <mixType.hxx>
#include <siteType.hxx>

auto main(int argc, char *argv[]) -> int {
    if (argc < 2) {
        std::cerr << "Missing argument(s): uddf_file output_dir\n";
        return 1;
    } else if (argc < 3) {
        std::cerr << "Missing argument: output_dir\n";
        return 1;
    }

    std::filesystem::path uddf_file(std::string{argv[1]});
    std::filesystem::path output_dir(std::string{argv[2]});

    if (std::filesystem::is_directory(uddf_file)) {
        std::cerr << "UDDF input file *must* be a file: " << uddf_file << '\n';
        return 1;
    } else if (!std::filesystem::exists(uddf_file)) {
        std::cerr << "UDDF input file does not exist: " << uddf_file << '\n';
        return 1;
    }

    auto uddf_data = uddf2fit::load_uddf(uddf_file);

    std::unordered_map<std::string, const streit::siteType *> dive_sites;
    std::cout << "Number of dive sites: " << uddf_data->divesite()->site().size() << std::endl;
    for (const auto &dive_site : uddf_data->divesite()->site()) {
        dive_sites.emplace(std::string{dive_site.id()}, &dive_site);
    }

    std::cout << "Gas definitions: " << uddf_data->divesite()->site().size() << std::endl;
    std::unordered_map<std::string, const streit::mixType *> gas_definitions;
    for (const auto &gas : uddf_data->gasdefinitions()->mix()) {
        gas_definitions.emplace(std::string{gas.id()}, &gas);
    }

    struct Dive {
        std::string id;
        const streit::siteType *site;
    };

    std::vector<Dive> dives;
    for (const auto &repetition_group : uddf_data->profiledata()->repetitiongroup()) {
        for (const auto &dive : repetition_group.dive()) {
            if (auto it = dive_sites.find(dive.informationbeforedive().link().front().ref());
                it != dive_sites.end()) {
                dives.emplace_back(Dive{.id = std::string{dive.id()}, .site = it->second});
                // std::cerr << "Added dive: " << dives.back().id << ", " << *dives.back().site <<
                // '\n';
            } else {
                std::cerr << "Unable to parse site ID from: " << dive.informationbeforedive()
                          << '\n';
            }
        }
    }

    if (std::filesystem::is_regular_file(output_dir)) {
        std::cerr << "Output directory cannot be a file: " << output_dir << '\n';
        return 1;
    } else if (!std::filesystem::exists(output_dir)) {
        std::filesystem::create_directories(output_dir);
    }

    return 0;
}
