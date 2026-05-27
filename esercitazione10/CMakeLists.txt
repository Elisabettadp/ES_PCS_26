cmake_minimum_required(VERSION 3.20)
project(Esercitazione10)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")


find_package(Eigen3 CONFIG REQUIRED)
list(APPEND libraries_list PUBLIC Eigen3::Eigen)

add_executable(test_cg test_cg.cpp)

target_link_libraries(test_cg ${libraries_list})