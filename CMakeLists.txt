cmake_minimum_required(VERSION 3.28)
project(Coding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-DLOCAL -Wall -Wno-unknown-pragmas")
#set(CMAKE_CXX_FLAGS "-O2 -Wall -lm -DONLINE_JUDGE -DBOJ")
#set(CMAKE_CXX_FLAGS "-O2 -DLOCAL")

add_executable(def def.cpp)
add_executable(Baekjoon_findCounterExample_fce_main Baekjoon/findCounterExample/fce_main.cpp)
add_executable(ext ext.cpp)

add_executable(test test.cpp)
add_executable(.gitignored_Winter2025_01-07_countingstars .gitignored/Winter2025/01-07/countingstars.cpp)
add_executable(.gitignored_Winter2025_01-07_2dsegtest .gitignored/Winter2025/01-07/2dsegtest.cpp)
add_executable(.gitignored_Winter2025_01-07_switch .gitignored/Winter2025/01-07/switch.cpp)