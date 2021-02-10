cmake_minimum_required(VERSION 3.0.0)
project(NodeSpaceProject VERSION 0.1.0)


include_directories(googletest-release-1.10.0)

add_executable(nodespace main.cpp node.cpp)

target_link_libraries(nodespace PRIVATE gtest pthread)