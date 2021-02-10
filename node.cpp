#include "node.hpp"


Node::Node(std::list<Node> connections){
    for(Node &node : connections){
        addLink(node);
    }
}

// Key update rule for the univese
void Node::update(){
    // if node is stable do nothing
    if(chk_ifStable()){
        return;
    }
    // if node is not stable, change it somehow
    for(Node &neighbor : connections){
        for (Node &neighbor2: neighbor.connections){
            if( &neighbor2 != this){
                // Steal a connection
                if(connections.size() < neighbor2.connections.size()){
                    neighbor.rmvLink(neighbor2);
                    addLink(neighbor2);
                    update_neighbors();
                }
                else if(connections.size() == neighbor2.connections.size()){
                    //do nothing
                }
                // Donate a connection???
                else if(connections.size() > neighbor2.connections.size()){
                    // might be alreade accounted for... do nothign for now
                } 

            }
        }
    }

        
}

void Node::update_neighbors(){
    for(Node &neighbor : connections){
        neighbor.update();
    }
}

bool Node::chk_ifStable(){
    for(Node &neighbor : connections){
        if(neighbor.connections.size() != connections.size()){
            return false;
        }
    }
    return true;
} 


// Adds a one-way link to the input node
void Node::add_connection(Node &node){
    connections.push_back(node);
}

// Adds bi-directional link to and from input node
void Node::addLink(Node &node){
    add_connection(node);
    node.add_connection(*this);
}

// Removes a one-way link to the input connections
void Node::rmv_connection(Node &node){
    std::list<Node>::iterator it = connections.begin();
    for(Node &current_node : connections){
        if(&current_node == &node){
            connections.erase(it);
            return;
        }
        it++;
    }
}

// Removes bi-directional link to and from input node
void Node::rmvLink(Node &node){
    node.rmv_connection(*this);
    rmv_connection(node);
}