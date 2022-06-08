#include <iostream>
#include <sstream>
#include "Graph.h"
#include "GraphNode.h"
#include "MinHeap.h"

int main() {
std::stringstream inputInfo;
inputInfo << std::cin.rdbuf(); 
// Construye un grafo a partir de la consola usando
// representacion de Lista de adyacencia grafo directo ponderado
Graph g1(3, inputInfo);
g1.printGraph();

g1.dijkstra();

    



} 