#include "node.hpp"

// Default node constructor starts with empty node
Node::Node(){
}

// Key update rule for the univese
bool Node::update(){
    // if node is stable do nothing
    if(chk_ifStable()){
        return false;
    }
    // if node is not stable, change it somehow
    for(auto neighbor : neighbors){
        for (auto neighbor2 : neighbor->neighbors){
            if(this->neighbors.size() < neighbor2->neighbors.size()){
                addLink(neighbor2);
                neighbor->rmvLink(neighbor2);
                //update_neighbors();
                return true;
            // Do nothing for other cases for now
            }
        }
    }
}

// Goes to neighbors and runs update
void Node::update_neighbors(){
    for(auto &neighbor : neighbors){
        neighbor->update();
    }
}

// Checks if the node wants to update
bool Node::chk_ifStable(){
    for(auto &neighbor : neighbors){
        if(neighbor->neighbors.size() != this->neighbors.size()){
            return false;
        }
    }
    return true;
} 


// Adds a one-way link to the input node
void Node::add_connection(Node *node){
    neighbors.push_back(node);
}

// Adds bi-directional link to and from input node
void Node::addLink(Node* node){
    add_connection(node);
    node->add_connection(this);
}

// Removes a one-way link to the input neighbors
void Node::rmv_connection(Node *node){
    std::list<Node*>::iterator it = neighbors.begin();
    for(auto &current_node : neighbors){
        if(current_node == node){
            neighbors.erase(it);
            return;
        }
        it++;
    }
}

// Removes bi-directional link to and from input node
void Node::rmvLink(Node* node){
    node->rmv_connection(this);
    rmv_connection(node);
}