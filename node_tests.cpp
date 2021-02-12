// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node.hpp"

TEST(testing_gtest, assertion_check){
    ASSERT_TRUE( 1 == 1 ); 
}

struct NodeTestBasic : public testing::Test {
    Node* testnode1;
    Node* testnode2;

    void SetUp() {
        testnode1 = new Node();
        testnode2 = new Node();
    }

    void Teardown(){
        delete testnode1;
        delete testnode2;
    }
};

struct NodeTestSimple : public testing::Test {
    Node* testnode1;
    Node* testnode2;
    Node* testnode3;
    Node* testnode4;
    Node* testnode5;

    void SetUp() {
        testnode1 = new Node();
        testnode2 = new Node();
        testnode3 = new Node();
        testnode4 = new Node();
        testnode5 = new Node();
    }

    void Teardown(){
        delete testnode1;
        delete testnode2;
        delete testnode3;
        delete testnode4;
        delete testnode5;
    }
};


TEST_F( NodeTestBasic, node_starts_empty){
    EXPECT_EQ(testnode1->neighbors.size(), 0);
}

TEST_F( NodeTestBasic, node_can_add_a_link){
    testnode1->addLink(testnode2);

    EXPECT_EQ( *(testnode1->neighbors.begin()), testnode2 );
}

TEST_F( NodeTestBasic, node_can_add_a_link_bidirectionally){
    testnode1->addLink(testnode2);

    EXPECT_EQ( *(testnode1->neighbors.begin()), testnode2 );
    EXPECT_EQ( *(testnode2->neighbors.begin()), testnode1 );
}

TEST_F( NodeTestBasic, node_can_remove_a_link){
    testnode1->addLink(testnode2);
    testnode1->rmvLink(testnode2);

    EXPECT_EQ( testnode1->neighbors.size(), 0);
}

TEST_F( NodeTestBasic, node_can_remove_a_link_bidirectionally){
    testnode1->addLink(testnode2);
    testnode1->rmvLink(testnode2);

    EXPECT_EQ( testnode1->neighbors.size(), 0);
    EXPECT_EQ( testnode2->neighbors.size(), 0);
}

TEST_F( NodeTestSimple, node_has_the_correct_neighbor_count){
    testnode1->addLink(testnode2);
    testnode2->addLink(testnode3);
    testnode3->addLink(testnode4);
    testnode4->addLink(testnode5);
    
    EXPECT_EQ( testnode1->neighbors.size(), 1);
    EXPECT_EQ( testnode2->neighbors.size(), 2);
    EXPECT_EQ( testnode3->neighbors.size(), 2);
    EXPECT_EQ( testnode4->neighbors.size(), 2);
    EXPECT_EQ( testnode5->neighbors.size(), 1);

}

TEST_F(NodeTestSimple, node_has_the_correct_neighbors){
    testnode1->addLink(testnode2);
    testnode2->addLink(testnode3);
    testnode3->addLink(testnode4);
    testnode4->addLink(testnode5);

    EXPECT_EQ( *(  testnode3->neighbors.begin()), testnode2);
    EXPECT_EQ( *(++testnode3->neighbors.begin()), testnode4);
}

TEST_F( NodeTestSimple, stable_node_will_not_update){
    testnode1->addLink(testnode2);
    testnode2->addLink(testnode3);
    testnode3->addLink(testnode4);
    testnode4->addLink(testnode5);
    
    testnode3->update();

    EXPECT_EQ(*(  testnode3->neighbors.begin()), testnode2);
    EXPECT_EQ(*(++testnode3->neighbors.begin()), testnode4);
}


TEST_F( NodeTestSimple, unstable_node_will_update){
    testnode1->addLink(testnode2);
    testnode2->addLink(testnode3);
    testnode3->addLink(testnode4);
    testnode4->addLink(testnode5);
    
    testnode1->update();

    EXPECT_TRUE(testnode1->neighbors.size() != 1);
    EXPECT_TRUE(testnode2->neighbors.size() != 2);
}