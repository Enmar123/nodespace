#pragma once

#include <iostream>
#include <list>
#include <memory>
#include "node.hpp"

class Space{
public:
    Space();
    void update();
    void setStart(Node* node);
    void setNodes(std::list<Node*> &nodes);
    
private:   
    std::list<Node*> nodes;
    std::list<Node*> node_update_order;
};