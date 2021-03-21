// Shared libs
#include <iostream>
// External libs
#include "gtest/gtest.h"
// My libs
#include "node.hpp"
#include "space.hpp"

struct SpaceTestBasic : public testing::Test {
    Node* testnode;
    Space* testspace;

    void SetUp() {
        testnode = new Node();
        testspace = new Space();
    }

    void Teardown(){
        delete testspace;
        delete testnode;
    }
};

struct SpaceTestSimple : public testing::Test {
    Node* testnode1;
    Node* testnode2;
    Node* testnode3;
    Node* testnode4;
    Node* testnode5;
    Space* testspace;

    void SetUp() {
        testnode1 = new Node();
        testnode2 = new Node();
        testnode3 = new Node();
        testnode4 = new Node();
        testnode5 = new Node();

        testspace = new Space();

        testnode1->addLink(testnode2);
        testnode2->addLink(testnode3);
        testnode3->addLink(testnode4);
        testnode4->addLink(testnode5);

        testspace->addNode(testnode1);
        testspace->addNode(testnode2);
        testspace->addNode(testnode3);
        testspace->addNode(testnode4);
        testspace->addNode(testnode5);
    }

    void Teardown(){
        delete testspace;
        delete testnode1;
        delete testnode2;
        delete testnode3;
        delete testnode4;
        delete testnode5;
    }
};

TEST_F( SpaceTestBasic, space_starts_empty){
    EXPECT_EQ(testspace->getNextUpdateNode(), nullptr);
    EXPECT_EQ(testspace->nodes.size(), 0);
}

TEST_F( SpaceTestBasic, add_node_to_space){
    testspace->addNode(testnode);
    EXPECT_EQ(testspace->nodes.size(), 1);
}

TEST_F( SpaceTestBasic, add_start_node_to_update_queue){
    testspace->setUpdateStart(testnode);
    EXPECT_EQ(testspace->getNextUpdateNode(), testnode);
}

TEST_F( SpaceTestSimple, update_can_add_to_queue){
    testspace->setUpdateStart(testnode1);
    testspace->update();

    EXPECT_NE( testspace->node_update_queue.size(), 0);
}

TEST_F( SpaceTestSimple, update_does_not_have_to_add_to_queue){
    testspace->setUpdateStart(testnode3);
    testspace->update();

    EXPECT_EQ( testspace->node_update_queue.size(), 0);
}
