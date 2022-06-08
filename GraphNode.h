#ifndef __GRAPHNODE_H_
#define __GRAPHNODE_H_

class GraphNode{
    private:
        int numberNode;
        int weight;
        int minDistance;
    public:
        GraphNode();
        GraphNode(int numberNode_, int weight);
        int getNumberNode();
        int getWeight();
        int getMinDistance();
        void setMinDistance(int minD);

};

#endif