#include <string>
#include <iostream>
#include "Config.h"
#include <cxxopts.hpp>

/**
 * Define version
 */
#if defined(PROJECT_VERSION)  
const std::string Helpers::Config::version = PROJECT_VERSION;
#else
throw new std::exception("The -DPROJECT_VERSION flag was not set.");
#endif

/**
 * Define name
 */
#if defined(PROJECT_NAME)  
const std::string Helpers::Config::name = PROJECT_NAME;
#else
throw new std::exception("The -DPROJECT_NAME flag was not set.");
#endif

/**
 * Define description
 */
const std::string Helpers::Config::description = "A small description of your project (a one line explanation).";

/**
 * Define authors
 */
const std::string Helpers::Config::authors = "Project Author <author@example.ltd>";

/**
 * Define default options
 */
bool Helpers::Config::optDaemon = false;
bool Helpers::Config::optDebug = false;

/**
 * Print a banner 
 */
void Helpers::Config::printBanner() {
    std::cout << "██████╗ ██████╗  ██████╗      ██╗███████╗ ██████╗████████╗" << std::endl;
    std::cout << "██╔══██╗██╔══██╗██╔═══██╗     ██║██╔════╝██╔════╝╚══██╔══╝" << std::endl;
    std::cout << "██████╔╝██████╔╝██║   ██║     ██║█████╗  ██║        ██║   " << std::endl;
    std::cout << "██╔═══╝ ██╔══██╗██║   ██║██   ██║██╔══╝  ██║        ██║   " << std::endl;
    std::cout << "██║     ██║  ██║╚██████╔╝╚█████╔╝███████╗╚██████╗   ██║   " << std::endl;
    std::cout << "╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚════╝ ╚══════╝ ╚═════╝   ╚═╝   " << std::endl;

    std::cout << "Version " << Helpers::Config::version << " - Copyright 2017 " << Helpers::Config::authors << std::endl;
    std::cout << std::endl;
}

/**
 * Initialize all arguments
 */
cxxopts::Options Helpers::Config::initializeArgs(int argc, char *argv[]) {
    cxxopts::Options options(Helpers::Config::name, Helpers::Config::description + std::string("\n"));

    options.add_options()
        ("h,help",          "Print this help message and exit.")
        ("d,daemon",        "Launch as a daemon (in the background).")
        ("debug",           "Enable debugging mode.")
    ;

    try {
        options.parse(argc, argv);
    } catch (const cxxopts::OptionException& e) {
        std::cerr << "Error while parsing options! " << std::endl;
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Show help message if needed
    if (options.count("help")) {
        std::cout << options.help({""}) << std::endl;
        exit(EXIT_SUCCESS);
    }

    // Set all options
    Helpers::Config::optDebug = !!options.count("debug");
    Helpers::Config::optDaemon = !!options.count("daemon");

    return options;
}