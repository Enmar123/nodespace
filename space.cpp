#include "space.hpp"


Space::Space(){
}

// Update the next node in the update order
void Space::update(){
    // If update produces a change in the node
    if (node_update_order.front()->update()){
        // Add neighboring nodes to update order
        for( Node* node : node_update_order.front()->neighbors){
            node_update_order.push_back(node);
        }
    }
    // Remove updated node from update order
    node_update_order.pop_front();
}

// Set the first node to be updated
void Space::setStart(Node* node){
    node_update_order.push_back(node);
}

// Set a node configuration
void Space::setNodes(std::list<Node*> &nodes){
    this->nodes = nodes; 
}
