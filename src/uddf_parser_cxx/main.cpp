#include <iostream>

#include "load.hpp"

int main(int argc, char *argv[]) {
    auto uddf = uddf2fit::load_uddf(argv[1]);
    if(!uddf) {
        std::cerr << "Failed to load UDDF file: " << argv[1] << std::endl;
        return 1;
    }
    
    std::cout << "Diver: " << uddf->gasdefinitions() << std::endl;
    std::cout << "Samples:\n";
    std::cout << uddf->profiledata()->repetitiongroup().front().dive().front().samples();
    return 0;
}
