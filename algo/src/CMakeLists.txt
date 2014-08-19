cmake_minimum_required(VERSION 2.8, FATAL_ERROR)

add_definitions("-std=c++0x")

# include_directories: Add include directories to the build.
#   include_directories([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)
#   Add the given directories to those the compiler uses to search for include files. 
include_directories(${Algorithm_SOURCE_DIR}/include)

set(source_files 
    anagram.cpp
    palindrome.cpp
    longestSubstr.cpp
    longestCommonSeq.cpp
    str_removespace.cpp
    str_permute.cpp
    str_replace_space.cpp
    str_longestPalindrome.cpp
    str_kmp.cpp
    str_search_robin_karp.cpp
    str_reverse.cpp
    str_longest_substr_no_dup.cpp
    str_remove_dup.cpp
    str_rotate.cpp
    file_last_k_line.cpp
    stream_no_dup_char.cpp
    edit_distance.cpp
    regex.cpp
    sorted_array_partition.cpp
    min_cover_window.cpp
    fibo.cpp
    prime.cpp
    endian.cpp
    isqrt.cpp
    linked_list_api.cpp
    dlist.cpp
    circular_sorted_list.cpp
    list_reverse.cpp
    reservior_sampling.cpp
    rejection_sampling.cpp
    ugly_number.cpp
    gcd.cpp
    divide_and_mod.cpp
    max_sum.cpp
    reverseBit.cpp
    bst.cpp
    bst_api.cpp
    bst_lca.cpp
    bst_prettyprint.cpp
    bst_delete_node.cpp
    bst_mirror.cpp
    bst_to_doubly_list.cpp
    bst_subtree.cpp
    bst_rw_file.cpp
    bst_print_by_level.cpp
    bst_predecessor_successor.cpp
    top_k.cpp
    sum_subset.cpp
    search_rotate_array.cpp
    maxheap.cpp
    bit_swap.cpp
    bit_op.cpp
    bit_set_pattern.cpp
    bit_next_int.cpp
    bit_swap_even_odd_bits.cpp
    list_loop.cpp
    split_linked_list.cpp
    linked_list_add.cpp
    min_stack.cpp
    all_subset.cpp
    rectangle_overlap.cpp
    intersection_sorted_array.cpp
    unique_path.cpp
    parenthesis.cpp
    fast_expo.cpp
    rotate_matrix.cpp
    find_pair_to_sum.cpp
    excel_row_number.cpp
    matrix_set_zero.cpp
    matrix_search.cpp
    stl_unordered_map.cpp
    stk_sort.cpp
    queue_by_stack.cpp
    undirected_graph.cpp
    merge_array.cpp
    test_bst.cpp
    test_driver.cpp
    useful_api.cpp
)

# add_executable: Add an executable to the project using the specified source files.
add_executable(test_driver ${source_files})

# Specify a list of libraries to be linked into the specified target. 
#   If any library name matches that of a target in the current project a 
#   dependency will automatically be added in the build system to 
#   make sure the library being linked is up-to-date before the target links.
# target_link_libraries(test_driver m)
