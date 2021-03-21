// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node_tests.hpp"

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
