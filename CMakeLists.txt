cmake_minimum_required(VERSION 3.23)
project(lc)

set(CMAKE_CXX_STANDARD 14)

ADD_SUBDIRECTORY(leetcode1)
ADD_SUBDIRECTORY(tree)
add_executable(lc main.cpp)
