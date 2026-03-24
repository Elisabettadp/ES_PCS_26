cmake_minimum_required(VERSION 3.20) 
project(primi_algoritmi) 

set(CMAKE_CXX_STANDARD 20) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-Wall -Wshadow -Werror=vla") 


add_executable(es1 figura1.cpp)
add_executable(es2 primi_algoritmi.cpp)
add_executable(es3 bubble_sort.cpp)