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

add_executable(Baekjoon_p1_13309_hld Baekjoon/4_platinum/p1_13309_hld.cpp)
add_executable(Baekjoon_d5_2927_hld_offq Baekjoon/d5_2927_hld_offq.cpp)
add_executable(.contests_Codeforces_Codeforces_959_A .contests/Codeforces/Codeforces_959/A.cpp)
add_executable(.contests_Codeforces_Codeforces_959_B .contests/Codeforces/Codeforces_959/B.cpp)
add_executable(.contests_Codeforces_Codeforces_959_C .contests/Codeforces/Codeforces_959/C.cpp)