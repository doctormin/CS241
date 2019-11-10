cmake_minimum_required(VERSION 3.14)
project(CS241)

set(CMAKE_CXX_STANDARD 14)


add_executable(LinearSystem Assignment/Assignment4/LinearSystem.cpp)
add_executable(NewtonsMethod Assignment/Assignment3/HW3-NewtonsMethod/NewtonsMethod.cpp)
add_executable(BisectionMethod Assignment/Assignment3/HW3-BisectionMethod/BisectionMethod.cpp)

add_executable(NewtonInterpolation Assignment/Assignment2/exercise2/NewtonInterpolation.cpp)
add_executable(Assignment6_main Assignment/Assignment6/Assignment6_main.cpp)

add_executable(Assignment8_main Assignment/Assignment8/Assignment8_main.cpp)

add_executable(exercise2_main Assignment/Assignment2/exercise2/exercise2_main.cpp)