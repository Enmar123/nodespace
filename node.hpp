#pragma once

#include <iostream>
#include <list>

class Node{
public:
    Node(std::list<Node> connections);
    void update();
    void addLink(Node &node);
    void rmvLink(Node &node);
    

private:   
    std::list<Node> connections;

    bool chk_ifStable();
    bool chk_forNode(Node &node);
    void rmv_connection(Node &node);
    void add_connection(Node &node);
    void update_neighbors();

};