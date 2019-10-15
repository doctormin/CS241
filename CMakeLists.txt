cmake_minimum_required(VERSION 3.14)
project(PAQ_homework)

set(CMAKE_CXX_STANDARD 14)

add_executable(PAQ_homework assignment3/exercise1/BisectionMethod.cpp assignment4/LinearSystem.cpp)

add_executable(LinearSystem assignment4/LinearSystem.cpp assignment4)
add_executable(Bugen assignment4/Bugen.cpp)