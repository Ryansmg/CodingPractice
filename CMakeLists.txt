cmake_minimum_required(VERSION 3.28)
project(Coding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-DLOCAL")
#set(CMAKE_CXX_FLAGS "-O2 -Wall -lm -DONLINE_JUDGE -DBOJ")


add_executable(z.etc_test z.etc/test.cpp)
add_executable(.Library_a_segtree .Library/a_segtree.cpp)
add_executable(.Library_a_sqrtdecomposition .Library/a_sqrtdecomposition.cpp)
add_executable(.Library_a_pollard_rho .Library/a_pollard_rho.cpp)
add_executable(.Library_a_flow .Library/a_flow.cpp)
add_executable(.Library_a_all .Library/a_all.cpp)

add_executable(.Library_.default_extended .Library/.default_extended.cpp)
add_executable(z.etc_IntegerClass z.etc/IntegerClass.cpp)
add_executable(.Library_iterative_lazyprop .Library/iterative_lazyprop.cpp)
add_executable(.Library_BigInt BigInt.cpp)
add_executable(test test.c)

add_executable(Baekjoon_4_platinum_p2_11012_pst_2 Baekjoon/4_platinum/p2_11012_pst_2.cpp)
add_executable(.Library_.a. .Library/.a..cpp)
add_executable(Koistudy_School_1-2_learnStruct Koistudy/School/1-2/learnStruct.cpp)
add_executable(Koistudy_School_1-2_1 Koistudy/School/1-2/1.cpp)
add_executable(Koistudy_School_1-2_E Koistudy/School/1-2/E.cpp)
add_executable(Baekjoon_g5_15681_dpTree Baekjoon/g5_15681_dpTree.cpp)