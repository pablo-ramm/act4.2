#ifndef __GRAPHNODE_H_
#define __GRAPHNODE_H_

class GraphNode{
    private:
        int numberNode;
        int weight;
    public:
        GraphNode();
        GraphNode(int numberNode_, int weight);
        int getNumberNode();
        int getWeight();

};

#endif