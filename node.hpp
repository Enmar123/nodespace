#pragma once

#include <iostream>
#include <list>
#include <memory>

class Node{
public:
    Node();
    Node(std::list<Node> connections);
    void update();
    void addLink(Node &node);
    void rmvLink(Node &node);
    
    std::list<Node> connections;

private:   
    bool chk_ifStable();
    bool chk_forNode(Node &node);
    void rmv_connection(Node &node);
    void add_connection(Node &node);
    void update_neighbors();

};