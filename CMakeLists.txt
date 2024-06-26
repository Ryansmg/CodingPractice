cmake_minimum_required(VERSION 3.28)
project(Coding)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_FLAGS "-O2")


add_executable(z.etc_test z.etc/test.cpp)
add_executable(Baekjoon_p5_4157_segtree Baekjoon/platinum/p5_4157_segtree.cpp)
add_executable(Baekjoon_p5_4442_segtree Baekjoon/platinum/p5_4442_segtree.cpp)
add_executable(.Library_a_segtree .Library/a_segtree.cpp)
add_executable(.Library_a_sqrtdecomposition .Library/a_sqrtdecomposition.cpp)
add_executable(Baekjoon_platinum_p5_3770_segtree Baekjoon/platinum/p5_3770_segtree.cpp)
add_executable(Baekjoon_g1_1615_segtree Baekjoon/gold/g1_1615_segtree.cpp)
add_executable(Baekjoon_p5_4297_segtree Baekjoon/platinum/p5_4297_segtree.cpp)
add_executable(.Library_a_pollard_rho .Library/a_pollard_rho.cpp)
add_executable(.Library_a_flow .Library/a_flow.cpp)
add_executable(Baekjoon_p4_4445_flow Baekjoon/platinum/p4_4445_flow.cpp)
add_executable(.Library_a_all .Library/a_all.cpp)