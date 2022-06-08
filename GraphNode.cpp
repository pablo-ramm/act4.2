#include "GraphNode.h"

GraphNode::GraphNode(){

}

GraphNode::GraphNode(int numberNode_, int weight_){
    numberNode = numberNode_;
    weight = weight_;
    minDistance = 0;
}

int GraphNode::getWeight(){
    return weight;
}

int GraphNode::getNumberNode(){
    return numberNode;
}

int GraphNode::getMinDistance(){
    return minDistance;
}

void GraphNode::setMinDistance(int minD){
    minDistance = minD;
}