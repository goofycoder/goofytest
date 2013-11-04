cmake_minimum_required(VERSION 2.8, FATAL_ERROR)

add_definitions("-std=c++0x")

# include_directories: Add include directories to the build.
#   include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)
#   Add the given directories to those the compiler uses to search for include files. 
include_directories(${system_SOURCE_DIR}/include)

set(source_files 
    raii_example.cpp
    exception_example.cpp
    rlimit.cpp
    hash_example.cpp
    test_driver.cpp
)

set (Boost_MULTITHREADED TRUE)

if (USE_STATIC_BOOST)
    set (Boost_USE_STATIC_LIBS TRUE)
endif ()

find_package(Threads)

# add_executable: Add an executable to the project using the specified source files.
add_executable(test_driver ${source_files})

# Specify a list of libraries to be linked into the specified target. 
#   If any library name matches that of a target in the current project a 
#   dependency will automatically be added in the build system to 
#   make sure the library being linked is up-to-date before the target links.
target_link_libraries(
    test_driver 
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
)
