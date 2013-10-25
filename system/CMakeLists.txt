#############################################
# CMake: Cross-Platform Makefile Generator
#   3 different directories involved: 
#       The source dir  
#       the build dir   // object file & executable
#       the install dir
###############################################
cmake_minimum_required(VERSION 2.8, FATAL_ERROR)

# project: Set a name for the entire project.
# project(<projectname> [languageName1 languageName2 ... ] )
# This also sets the variables <projectName>_BINARY_DIR and <projectName>_SOURCE_DIR   
# By default C and CXX are enabled. 
project(system)

# the executable will be generate in project directory 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${system_BINARY_DIR})

# add /src subdirectory
add_subdirectory(src)
