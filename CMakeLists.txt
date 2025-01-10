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


add_executable(.gitignored_Winter2025_01-10_kong .gitignored/Winter2025/01-10/kong.cpp)
add_executable(.gitignored_Winter2025_01-10_element .gitignored/Winter2025/01-10/element.cpp)
add_executable(.gitignored_Winter2025_01-10_twolist .gitignored/Winter2025/01-10/twolist.cpp)
add_executable(.gitignored_Winter2025_01-10_moon .gitignored/Winter2025/01-10/moon.cpp)
