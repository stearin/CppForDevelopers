cmake_minimum_required(VERSION 3.20)
project(day11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(day11_01_function 01_function.cpp)

add_executable(day11_02_class 02_class.cpp)

add_executable(day11_03_vector 03_vector.cpp)

add_executable(day11_04_map 04_map.cpp)

add_executable(day11_05_unordered 05_unordered.cpp)

add_executable(day11_06_invalidation 06_invalidation.cpp)

add_executable(day11_extra_20_concepts extra_20_concepts.cpp)

add_executable(day11 main.cpp)

add_executable(day11_03_array 03_array.cpp)

add_executable(day11_03_list 03_list.cpp)

add_executable(day11_span span.cpp)
