#include <cstdlib>
#include <iostream>
#include <cxxopts.hpp>

#include "helpers/Config.cpp"

int main(int argc, char *argv[]) {
    Helpers::Config::printBanner();
    Helpers::Config::initializeArgs(argc, argv);
    
    return EXIT_SUCCESS;
}