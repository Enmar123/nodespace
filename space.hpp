#pragma once

#include <iostream>
#include <list>
#include <memory>
#include "node.hpp"

class Space{
public:
    Space();
    void update();
    void setUpdateStart(Node* node);
    void addNode(Node* node);
    void setNodes(std::list<Node*> &nodes);

    Node* getNextUpdateNode();

    std::list<Node*> nodes;
    std::list<Node*> node_update_queue;
    
private:   
    
};