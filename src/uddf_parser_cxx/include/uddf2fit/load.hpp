#ifndef LOAD_HPP
#define LOAD_HPP

#include <filesystem>
#include <memory>

#include "uddf_3.2.3.hxx"

namespace uddf2fit {
     auto load_uddf(std::filesystem::path filename) -> std::unique_ptr<streit::uddf>;
}

#endif // LOAD_HPP
