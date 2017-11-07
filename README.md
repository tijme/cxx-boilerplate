<h1 align="center">CXX Boilerplate</h1>
<p align="center">A simple yet comprehensive cross-platform c++ boilerplate to jumpstart your project.</p>

## Project Structure

* ``bin/`` An empty folder where your executable will end up after compilation.
* ``lib/`` A folder containing third party libraries in the form of git submodules.
    * ``cxxopts/`` A git submodule for parsing command line arguments.
* ``obj/`` An empty folder where your objects will end up after compilation.
* ``src/`` A folder for your project's source files (they will be included by the makefile recursively).
    * ``helpers/`` A folder for static classes.
        * ``Config.{h,cpp}`` A default static class for project information and parsing CLI args.
    * ``main.cpp`` The main c++ file that contains the ``main()`` method.

## Getting Started

**1. Getting the project**

Clone the repository recursively (so that you have all the submodules) using GIT.

``git clone --recursive git@github.com:tijme/cxx-boilerplate.git``

**2. Update the configuration**

In the ``src/helpers/Config.cpp`` file you need to update the description, author and project banner. You can use [this](http://patorjk.com/software/taag/#p=display&f=ANSI%20Shadow&t=PROJECT) tool to generate a banner.

**3. Update the makefile**

To update the name of the project and the generated binary you need to make changes in the `Makefile`. You can update the `PROJECT` variable to your project name. The binary will be generated using a lowercase version of this value.

Besides that you can update the `COMPILER` variable if you want to use a different compiler.

**4. Versioning**

By default [semantic](http://semver.org) versioning is used. You can update the version using the `.semver` file.

## Compilation &amp; Execution

**Compile The Project**

`$ make`

**Exeucte The Binary**

`$ ./bin/project`

**Clean Temporary Files**

`$ make clean`
