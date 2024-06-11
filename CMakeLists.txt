cmake_minimum_required(VERSION 3.24)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(singleton)
add_executable(singleton singleton/singleton_lazy98_1.cpp)
