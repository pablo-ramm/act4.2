#include <iostream>
#include <sstream>
#include "Graph.h"

int main() {
  std::stringstream inputInfo;
  inputInfo << std::cin.rdbuf(); 
  // Construye un grafo a partir de la consola usando
  // representacion de Lista de adyacencia
  Graph g1(3, inputInfo);
  g1.printGraph();
  //g1.printGraph();
  // Regresa a linea cero el archivo de entrada
  //inputInfo.clear();
  //inputInfo.seekg(0);
  // Construye un grafo a partir de la consola usando
  // representacion de Matriz de adyacencia
  //Graph g2(2, inputInfo);
  //g2.printGraph();
  // Algoritmo BFS iniciando en el nodo 1 del grafo g1
  //g1.BFS(1);
  // Algoritmo BFS iniciando en el nodo 1 del grafo g2
  //g2.BFS(1);


} 