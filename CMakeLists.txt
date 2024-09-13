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

add_executable(.Library_.default_extended .Library/def.cpp)

add_executable(.contests_Codeforces_LAKOTEN_1_A .contests/Codeforces/LAKOTEN_1_virtual/A.cpp)
add_executable(.contests_Codeforces_LAKOTEN_1_F .contests/Codeforces/LAKOTEN_1_virtual/F.cpp)
add_executable(.contests_Codeforces_LAKOTEN_1_D .contests/Codeforces/LAKOTEN_1_virtual/D.cpp)
add_executable(.contests_Codeforces_LAKOTEN_1_B .contests/Codeforces/LAKOTEN_1_virtual/B.cpp)
add_executable(.contests_Codeforces_LAKOTEN_1_C .contests/Codeforces/LAKOTEN_1_virtual/C.cpp)
add_executable(.contests_Codeforces_LAKOTEN_1_E .contests/Codeforces/LAKOTEN_1_virtual/E.cpp)

add_executable(Baekjoon_p4_1280_segtree Baekjoon/4_platinum/p4_1280_segtree.cpp)
add_executable(Koistudy_School_1-2_2_J Koistudy/School/1-2/2/J.cpp)
add_executable(Koistudy_School_1-2_2_K Koistudy/School/1-2/2/K.cpp)
add_executable(Koistudy_School_1-2_2_E Koistudy/School/1-2/2/E.cpp)
add_executable(Baekjoon_p5_1306_segtree Baekjoon/4_platinum/p5_1306_segtree.cpp)

add_executable(Baekjoon_p5_1849_segtree Baekjoon/4_platinum/p5_1849_segtree.cpp)