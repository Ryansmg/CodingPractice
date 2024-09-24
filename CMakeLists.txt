cmake_minimum_required(VERSION 3.28)
project(Coding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-DLOCAL")
#set(CMAKE_CXX_FLAGS "-O2 -Wall -lm -DONLINE_JUDGE -DBOJ")

add_executable(z.etc_test z.etc/test.cpp)
add_executable(.Library_a_segtree .Library/seg.cpp)
add_executable(.Library_a_sqrtdecomposition .Library/a_sqrtdecomposition.cpp)
add_executable(.Library_a_pollard_rho .Library/a_pollard_rho.cpp)
add_executable(.Library_a_flow .Library/a_flow.cpp)
add_executable(.Library_.def .Library/def.cpp)


add_executable(.Library_a_z.etc .Library/a_z.etc.cpp)
add_executable(Baekjoon_p1_13553_seg Baekjoon/p1_13553_seg.cpp)
add_executable(.Library_a_fenwick .Library/a_fenwick.cpp)
add_executable(Baekjoon_p3_16903_trie Baekjoon/p3_16903_trie.cpp)
add_executable(Baekjoon_p3_13505_trie Baekjoon/p3_13505_trie.cpp)
add_executable(Baekjoon_p3_13054_trie Baekjoon/p3_13504_trie.cpp)
add_executable(Baekjoon_p3_13504_trie Baekjoon/p3_13504_trie.cpp)