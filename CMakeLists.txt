cmake_minimum_required(VERSION 3.28)
project(Coding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-DLOCAL -Wall -Wno-unknown-pragmas")
#set(CMAKE_CXX_FLAGS "-O2 -Wall -lm -DONLINE_JUDGE -DBOJ")
#set(CMAKE_CXX_FLAGS "-O2 -DLOCAL")


add_executable(def def.cpp)
add_executable(Baekjoon_findCounterExample_fce_main Baekjoon/findCounterExample/fce_main.cpp)
add_executable(Baekjoon_z.giveup_d2_13159_splay_tree Baekjoon/z.giveup/d2_13159_splay_tree.cpp)
add_executable(Baekjoon_5_diamond_Generator_analyze_an1 Baekjoon/z.etcBJ/Generator/analyze/an1.cpp)
add_executable(Baekjoon_5_diamond_Generator_analyze_simple Baekjoon/z.etcBJ/Generator/analyze/simple.cpp)
add_executable(Baekjoon_5_diamond_Generator_check Baekjoon/z.etcBJ/Generator/check.cpp)
add_executable(Baekjoon_z.etcBJ_Generator_solution_sol0 Baekjoon/z.etcBJ/Generator/solution/sol0.cpp)
add_executable(Baekjoon_z.etcBJ_Generator_solution_sol1 Baekjoon/z.etcBJ/Generator/solution/sol1.cpp)
add_executable(Baekjoon_6_ruby_r5_19455_segbeats Baekjoon/6_ruby/r5_19455_segbeats.cpp)
add_executable(Baekjoon_6_ruby_r4_17477_segbeats Baekjoon/6_ruby/r4_17477_segbeats.cpp)