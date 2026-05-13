cmake_minimum_required(VERSION 3.20)
project(esercitazione6) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")
 
add_executable(test_grafo1 test_grafo1.cpp)
add_test(NAME grafo1 COMMAND test_grafo1)


enable_testing()