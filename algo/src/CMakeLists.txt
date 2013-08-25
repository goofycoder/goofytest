cmake_minimum_required(VERSION 2.8, FATAL_ERROR)

add_definitions("-std=c++0x")

# include_directories: Add include directories to the build.
#   include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)
#   Add the given directories to those the compiler uses to search for include files. 
include_directories(${Algorithm_SOURCE_DIR}/include)

set(source_files 
    anagram.cpp
    fibo.cpp
    linked_list_api.cpp
    palindrome.cpp
    prime.cpp
    reservior_sampling.cpp
    reverse.cpp
    test_bst.cpp
    bst.cpp
    longestSubstr.cpp
    longestCommonSeq.cpp
    max_sum.cpp
    rotateStr.cpp
    reverseBit.cpp
    test_driver.cpp
)

# add_executable: Add an executable to the project using the specified source files.
add_executable(test_driver ${source_files})

# Specify a list of libraries to be linked into the specified target. 
#   If any library name matches that of a target in the current project a 
#   dependency will automatically be added in the build system to 
#   make sure the library being linked is up-to-date before the target links.
# target_link_libraries(test_driver m)





