#############################################
# CMake: Cross-Platform Makefile Generator
#   3 different directories involved: 
#       The source dir  
#       the build dir   // object file & executable
#       the install dir
###############################################
cmake_minimum_required(VERSION 2.8)

# project: Set a name for the entire project.
# project(<projectname> [languageName1 languageName2 ... ] )
# This also sets the variables <projectName>_BINARY_DIR and <projectName>_SOURCE_DIR   
# By default C and CXX are enabled. 
project(Square)

# include_directories: Add include directories to the build.
#   include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)
#   Add the given directories to those the compiler uses to search for include files. 
include_directories(${CMAKE_SOURCE_DIR}/include)

add_definitions("-std=c++0x")

# add_executable: Add an executable to the project using the specified source files.
add_executable(square square.cpp)

# Specify a list of libraries to be linked into the specified target. 
#   If any library name matches that of a target in the current project a 
#   dependency will automatically be added in the build system to 
#   make sure the library being linked is up-to-date before the target links.
target_link_libraries(square m)




