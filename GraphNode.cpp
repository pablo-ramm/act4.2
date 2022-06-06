#include "GraphNode.h"

GraphNode::GraphNode(){

}

GraphNode::GraphNode(int numberNode_, int weight_){
    numberNode = numberNode_;
    weight = weight_;
}

int GraphNode::getWeight(){
    return weight;
}

int GraphNode::getNumberNode(){
    return numberNode;
}