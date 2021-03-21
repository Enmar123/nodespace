cmake_minimum_required(VERSION 3.0.0)
project(NodeSpaceProject VERSION 0.1.0)

add_library (nodespace node.cpp)

add_executable(nodespace_unittests nodespace_unittests.cpp)

target_link_libraries(nodespace_unittests PRIVATE
    # External
    gtest 
    pthread
    # Internal
    nodespace
    )
