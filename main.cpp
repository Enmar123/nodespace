// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node.hpp"

TEST(testing_gtest, assertion_check){
    ASSERT_TRUE( 1 == 1 ); 
}

/*
struct NodeTestSimple : public testing::Test {
    Node* testnode1;
    Node* testnode2;

    void SetUp() {
        testnode1 = new Node();
        testnode2 = new Node();
    }
    void Teardown
}
*/

TEST(NodeTest, node_starts_empty){
    Node  testnode = Node();
    EXPECT_EQ(testnode.neighbors.size(), 0);
}

TEST(NodeTest, node_can_add_a_link){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(&testnode2);

    EXPECT_EQ( *(testnode1.neighbors.begin()) , &testnode2 );
}

TEST(NodeTest, node_can_add_a_link_bidirectionally){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(&testnode2);

    EXPECT_EQ( *(testnode1.neighbors.begin()) , &testnode2 );
    EXPECT_EQ( *(testnode2.neighbors.begin()) , &testnode1 );
}

TEST(NodeTest, node_can_remove_a_link){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(&testnode2);
    testnode1.rmvLink(&testnode2);

    EXPECT_EQ( testnode1.neighbors.size() , 0);
}

TEST(NodeTest, node_can_remove_a_link_bidirectionally){
    Node testnode1 = Node();
    Node testnode2 = Node();

    testnode1.addLink(&testnode2);
    testnode1.rmvLink(&testnode2);

    EXPECT_EQ( testnode1.neighbors.size(), 0);
    EXPECT_EQ( testnode2.neighbors.size(), 0);
}

TEST(NodeTest, node_has_the_correct_neighbor_count){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(&testnode2);
    testnode2.addLink(&testnode3);
    testnode3.addLink(&testnode4);
    testnode4.addLink(&testnode5);
    
    EXPECT_EQ(testnode1.neighbors.size(), 1);
    EXPECT_EQ(testnode2.neighbors.size(), 2);
    EXPECT_EQ(testnode3.neighbors.size(), 2);
    EXPECT_EQ(testnode4.neighbors.size(), 2);
    EXPECT_EQ(testnode5.neighbors.size(), 1);

}

TEST(NodeTest, node_has_the_correct_neighbors){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(&testnode2);
    testnode2.addLink(&testnode3);
    testnode3.addLink(&testnode4);
    testnode4.addLink(&testnode5);

    EXPECT_EQ( *(testnode3.neighbors.begin() ), &testnode2);
    EXPECT_EQ( *(++testnode3.neighbors.begin()) , &testnode4);
}

TEST(NodeTest, stable_node_will_not_update){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(&testnode2);
    testnode2.addLink(&testnode3);
    testnode3.addLink(&testnode4);
    testnode4.addLink(&testnode5);
    
    testnode3.update();

    EXPECT_EQ(*(testnode3.neighbors.begin()), &testnode2);
    EXPECT_EQ(*(++testnode3.neighbors.begin()), &testnode4);
}


TEST(NodeTest, unstable_node_will_update){
    Node testnode1 = Node();
    Node testnode2 = Node();
    Node testnode3 = Node();
    Node testnode4 = Node();
    Node testnode5 = Node();

    testnode1.addLink(&testnode2);
    testnode2.addLink(&testnode3);
    testnode3.addLink(&testnode4);
    testnode4.addLink(&testnode5);
    
    testnode1.update();

    EXPECT_TRUE(testnode1.neighbors.size() != 1);
    EXPECT_TRUE(testnode2.neighbors.size() != 2);
}


int main(int argc, char** argv) {
    std::cout << "Hello, world!\n";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
