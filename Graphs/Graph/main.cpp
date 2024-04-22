#include "Graph.h"

int main() 
{
    Graph<string> graph;

    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");

    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "E");

    graph.printGraph();

    cout << "BFS from A to D: " << (graph.BFS("A", "D") ? "Encontrado" : "No encontrado") << endl;
    cout << "DFS from A to D: " << (graph.DFS("A", "D") ? "Encontrado" : "No encontrado") << endl;

}
