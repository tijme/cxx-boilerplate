#include <cstdlib>
#include <iostream>
#include <cxxopts.hpp>

#include "helpers/Config.hpp"

int main(int argc, char *argv[]) {
    helpers::Config::printBanner();
    helpers::Config::initializeArgs(argc, argv);
    
    return EXIT_SUCCESS;
}
