// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node.hpp"

TEST(testing_gtest, assertion_check){
    ASSERT_TRUE( 1 == 1 ); 
}

TEST(NodeTest, node_starts_empty){
    Node  testnode = Node();
    EXPECT_EQ(testnode.connections.size(), 0);
}

/*
TEST(NodeTest, adding_neigbor_bi_directional){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(testnode1);

    EXPECT_EQ(testnode1.chk_forNode(testnode2), true);
    EXPECT_EQ(testnode2.chk_forNode(testnode1), true);
}
*/

TEST(NodeTest, added_node_is_the_same){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(testnode2);

    EXPECT_TRUE( &*(testnode1.connections.begin()) == &testnode2 );
    std::cout << "are these the same? " << &*(testnode1.connections.begin()) << " and " << &testnode2 << std::endl;

}

TEST(NodeTest, nodes_have_correct_number_of_neighbors){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(testnode2);
    testnode2.addLink(testnode3);
    testnode3.addLink(testnode4);
    testnode4.addLink(testnode5);
    
    EXPECT_EQ(testnode1.connections.size(), 1);
    EXPECT_EQ(testnode2.connections.size(), 2);
    EXPECT_EQ(testnode3.connections.size(), 2);
    EXPECT_EQ(testnode4.connections.size(), 2);
    EXPECT_EQ(testnode5.connections.size(), 1);

}

TEST(NodeTest, stable_node_does_not_update){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(testnode2);
    testnode2.addLink(testnode3);
    testnode3.addLink(testnode4);
    testnode4.addLink(testnode5);
    
    testnode3.update();
    EXPECT_EQ(&(*testnode3.connections.begin()), &testnode2);
    EXPECT_EQ(&(*testnode3.connections.end()), &testnode4);

}

int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
