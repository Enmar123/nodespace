#include "space.hpp"


Space::Space(){
}

// Update the next node in the update order
void Space::update(){
    // If update produces a change in the node
    if (node_update_queue.front()->update() == true){
        // Add neighboring nodes to update order
        for( Node* neighbor : node_update_queue.front()->neighbors){
            node_update_queue.push_back(neighbor);
        }
    }
    // Remove updated node from update order
    node_update_queue.pop_front();
}

// Set the first node to be updated
void Space::setUpdateStart(Node* node){
    node_update_queue.push_back(node);
}

// Set a node configuration
void Space::setNodes(std::list<Node*> &nodes){
    this->nodes = nodes; 
}

Node* Space::getNextUpdateNode(){
    return node_update_queue.front();
}

void Space::addNode(Node* node){
    nodes.push_back(node);
}