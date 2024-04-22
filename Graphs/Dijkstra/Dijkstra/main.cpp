#include "Graph.h"

int main()
{
    Graph<int> myGraph;

    myGraph.addNode(0);
    myGraph.addNode(1);
    myGraph.addNode(2);
    myGraph.addNode(3);
    myGraph.addEdge(0, 1, 2);
    myGraph.addEdge(0, 2, 4);
    myGraph.addEdge(1, 2, 1);
    myGraph.addEdge(1, 3, 7);
    myGraph.addEdge(2, 3, 3);

    myGraph.Dijkstra(0);

    cout << "Grafo" << endl;
    myGraph.printGraph();
    cout << endl;

    myGraph.printPath(1, 3);
}