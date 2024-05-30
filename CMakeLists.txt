cmake_minimum_required(VERSION 3.23)
project(lc)

set(CMAKE_CXX_STANDARD 14)

ADD_SUBDIRECTORY(leetcode1)
ADD_SUBDIRECTORY(tree)
ADD_SUBDIRECTORY(listNode)
ADD_SUBDIRECTORY(backtrack)
add_executable(lc main.cpp
        string/maximumLength.cpp)
