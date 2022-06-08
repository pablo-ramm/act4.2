#include "Graph.h"
#include "GraphNode.h"
#include "MinHeap.h"

Graph::Graph(int representa, std::istream &input)
{
    if (representa == 1)
    {
        loadGraphList(input);
        representation = 1;
    }
    else if (representa == 2)
    {
        loadGraphMatrix(input);
        representation = 2;
    }
    else
    {
        loadDirectedGraph(input);
        representation = 3;
    }
}

Graph::~Graph()
{
    if (representation == 1)
        adjList.clear();
    else
        adjMatrix.clear();
}

void Graph::loadGraphMatrix(std::istream &input)
{
    std::string line;
    int i = 0;
    while (std::getline(input, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        if (i == 1)
        {
            std::vector<int> res;
            split(line, res);
            numNodes = res[0];
            numEdges = res[2];
            // Reservar memoria para los renglones de la matriz de adyacencia
            adjMatrix.resize(numNodes + 1);
            // Declara un vector de numNodes elementos en cada renglon (renglon 0 no utilizado)
            for (int k = 1; k <= numNodes; k++)
            {
                std::vector<int> tmpVector(numNodes + 1, 0);
                adjMatrix[k] = tmpVector;
            }
            i++;
            continue;
        }
        std::vector<int> res;
        split(line, res);
        int u = res[0];
        int v = res[1];
        // Grafos no dirigidos agrega aristas (u,v) y (v,u)
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        i++;
    }
}

void Graph::loadGraphList(std::istream &input)
{
    std::string line;
    int i = 0;
    while (std::getline(input, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        if (i == 1)
        {
            std::vector<int> res;
            split(line, res);
            numNodes = res[0];
            numEdges = res[2];
            // Reservar memoria para los renglones de la lista de adyacencia (renglon 0 no utilizado)
            adjList.resize(numNodes + 1);
            // Declara una lista vacia para cada renglon y la almacena en el vector
            for (int k = 1; k <= numNodes; k++)
            {
                LinkedList<int> tmpList;
                adjList[k] = tmpList;
            }
            i++;
            continue;
        }
        std::vector<int> res;
        split(line, res);
        int u = res[0];
        int v = res[1];
        // Grafos no dirigidos agrega aristas (u,v) y (v,u)
        adjList[u].addLast(v);
        adjList[v].addLast(u);
        i++;
    }
}

void Graph::split(std::string line, std::vector<int> &res)
{
    size_t strPos = line.find(" ");
    size_t lastPos = 0;
    while (strPos != std::string::npos)
    {
        res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
        lastPos = strPos + 1;
        strPos = line.find(" ", lastPos);
    }
    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

void Graph::printAdjList()
{
    std::cout << "Adjacency List" << std::endl;
    for (int i = 1; i <= numNodes; i++)
    {
        std::cout << "vertex " << i << ": ";
        adjList[i].printList();
    }
}

void Graph::printAdjMatrix()
{
    std::cout << "Adjacency Matrix" << std::endl;
    for (int i = 1; i <= numNodes; i++)
    {
        std::cout << "vertex " << i << ": ";
        for (int j = 1; j <= numNodes; j++)
        {
            std::cout << " " << adjMatrix[i][j];
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjDirList()
{
    std::cout << "Adjacency List" << std::endl;
    for (int i = 1; i <= numNodes; i++)
    {
        std::cout << "vertex " << i << ": ";
        adjDirList[i].printGNodeList();
    }
}

void Graph::printGraph()
{
    if (representation == 1)
    {
        printAdjList();
    }
    else if (representation == 2)
    {
        printAdjMatrix();
    }
    else
    {
        printAdjDirList();
    }
}

void Graph::BFS(int v)
{
    // Declaramos un set del STL de C++ (elementos unicos y ordenados)
    std::set<int> visited;
    // Creamos una queue
    QueueLinkedList<int> queue;
    // Marcamos el vertice actual v como visitado y entra al queue
    visited.insert(v);
    queue.enqueue(v);
    std::cout << "Recorrido BFS " << std::endl;
    while (!queue.isEmpty())
    {
        // Extraemos un vertice del queue y lo procesamos (print)
        v = queue.dequeue();
        std::cout << v << " ";
        // Obtenemos los vertices adyacentes del vertice v
        // Si estos no han sido visitados entonces se marcan como visitados
        // y los metemos al queue
        if (representation == 1)
        { // Lista de adyacencia
            // Recorrer nodos adyacentes de v
            for (int j = 0; j < (int)adjList[v].getNumElements(); j++)
            {
                int u = adjList[v].getData(j);
                // Verifica si u ya fue visitado en tiempo O(log n)
                bool isInVisited = visited.find(u) != visited.end();
                if (!isInVisited)
                {
                    visited.insert(u);
                    queue.enqueue(u);
                }
            }
        }
        else
        { // Matriz de adyacencia
            // Recorrer nodos adyacentes a v
            for (int u = 1; u <= numNodes; u++)
            {
                int c = adjMatrix[v][u];
                if (c != 0)
                {
                    // Verifica si u ya fue visitado en tiempo O(log n)
                    bool isInVisited = visited.find(u) != visited.end();
                    if (!isInVisited)
                    {
                        visited.insert(u);
                        queue.enqueue(u);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}

void Graph::loadDirectedGraph(std::istream &input)
{
    std::string line;
    int i = 0;
    while (std::getline(input, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }
        if (i == 1)
        {
            std::vector<int> res;
            split(line, res);
            numNodes = res[0];
            numEdges = res[2];
            // Reservar memoria para los renglones de la lista de adyacencia (renglon 0 no utilizado)
            adjDirList.resize(numNodes + 1);
            // Declara una lista vacia para cada renglon y la almacena en el vector
            for (int k = 1; k <= numNodes; k++)
            {
                LinkedList<GraphNode> tmpList;
                adjDirList[k] = tmpList;
            }
            i++;
            continue;
        }
        std::vector<int> res;
        split(line, res);
        int u = res[0];
        int v = res[1];
        int weight = res[2];
        GraphNode node(v, weight);
        // Grafos no dirigidos agrega aristas (u,v) y (v,u)
        adjDirList[u].addLast(node);
        i++;
    }
}

void Graph::dijkstra()
{
    
    MinHeap<GraphNode> minh(numNodes+1);
    int v = 1;
    std::vector<GraphNode> processNodes;
    processNodes.resize(numNodes+1);

//inicializamos por insertar el nodo raiz 0 con una distancia minima de cero en el minheap
    GraphNode node(v, 0);
    node.setMinDistance(0);
    minh.push(node);

//insertamos los demas nodos con el valor maximo que puedan tener
    for(int i = 2; i<numNodes; i++){
        GraphNode node(i, 0);
        node.setMinDistance(std::numeric_limits<int>::max());
        minh.push(node);
    }

    minh.printMinHeap();
    
    
    while (!minh.isEmpty())
    {
        // Extraemos el vertice con la menor distancia del min heap
        v = minh.top().getNumberNode();
        std::cout << "Nodo extraido: " << v << std::endl;
        //Actualizamos las distancias entre los nodos adjacientes de v
        for (int j = 0; j < (int)adjDirList[v].getNumElements(); j++)
        {
            int u = adjDirList[v].getData(j).getNumberNode();
            

            //si el nodo adyacente u de v se encuentra en el minheap, lo procesamos
            if (minh.isInMinHeap(u))
            {
                //si la distancia actual de v a u mas el peso de u es menor a la actual distancia del nodo dentro el minheap la actualizamos
                if(minh.top().getMinDistance()+adjDirList[v].getData(j).getWeight() < minh.getMinDistance(u)){
                    minh.updateMinDistance(u, minh.top().getMinDistance()+adjDirList[v].getData(j).getWeight());
                    std::cout << "Update min distance of: " << u << " for: "<< minh.getMinDistance(u) << std::endl;
                }
               
            }
        }

        std::cout << "top before pop: " << minh.top().getNumberNode() << std::endl;
        processNodes[v].setMinDistance(minh.top().getMinDistance());
        std::cout << "top " << minh.top().getMinDistance() << std::endl;
        minh.pop();
       
    }
        std::cout << "Dijkstra\n"; 
        std::cout << "vertex\t \t Distance from source\n";
        for(int i = 1; i<numNodes; i++){
            std::cout << i << "\t\t" << processNodes[i].getMinDistance() << std::endl;
        }
    
}