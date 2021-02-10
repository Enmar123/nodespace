// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node.hpp"

TEST(testing_gtest, assertion_check){
    ASSERT_TRUE( 1 == 1 ); 
}

int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
