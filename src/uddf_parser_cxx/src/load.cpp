#include "load.hpp"

#include <iostream>
#include <string>

#include "uddf_3.2.3.hxx"

namespace uddf2fit {
     auto load_uddf(std::filesystem::path filename) -> std::unique_ptr<streit::uddf> {
    try {
        xml_schema::properties props;
        // props.no_namespace_schema_location("/home/damien/code/cxx/uddf2fit/src/uddf_3.2.3.xsd");
        return streit::uddf_(filename.string(), xml_schema::flags::dont_validate, props);
        // return streit::uddf_(filename.string(), 0, props);
    } catch (const xml_schema::exception &e) {
        std::cerr << "ERROR: " << e << std::endl;
        std::cerr << "ERROR: while parsing " << filename << std::endl;
        return nullptr;
    }
        return nullptr;
}
} // namespace uddf2fit
