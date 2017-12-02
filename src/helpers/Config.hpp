#include <string>
#include <cxxopts.hpp>

namespace helpers {

    class Config {
    public:
        static const std::string version;
        static const std::string name;
        static const std::string description;
        static const std::string author;

        static bool optDebug;
        static bool optDaemon;

        static void printBanner();
        static cxxopts::Options initializeArgs(int argc, char *argv[]);
    };

}
