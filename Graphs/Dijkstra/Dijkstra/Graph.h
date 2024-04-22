#pragma once
#include "GraphNode.h"

using namespace std;

template <class T>
class Graph {
private:
    vector<GraphNode<T>> nodes;

public:
    Graph() {};
    ~Graph() {};

    const vector<GraphNode<T>>& getNodes() const;
    void setNodes(const vector<GraphNode<T>>& newNodes);
    void addNode(T value);
    void addEdge(int source, int destination, int weight);
    Graph<T> Dijkstra(int source);

    void printGraph();
    void printPath(int source, int destination);
};

template<class T>
inline const vector<GraphNode<T>>& Graph<T>::getNodes() const
{
    return nodes;
}

template<class T>
inline void Graph<T>::setNodes(const vector<GraphNode<T>>& newNodes)
{
    this->nodes = newNodes;
}

template<class T>
inline void Graph<T>::addNode(T value)
{
    nodes.push_back(GraphNode<T>(value));
}

template<class T>
inline void Graph<T>::addEdge(int source, int destination, int weight)
{
    nodes[source].addAdjacent(destination, weight);
}

template<class T>
inline Graph<T> Graph<T>::Dijkstra(int origin)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;

    nodes[origin].setDistance(0);
    //distancia, nodo
    priorityQueue.push({ 0, origin });

    while (!priorityQueue.empty())
    {
        auto duo = priorityQueue.top();
        priorityQueue.pop();

        int vertex = duo.second;

        if (!nodes[vertex].getVisited())
        {
            nodes[vertex].setVisited(true);

            for (const auto& edge : nodes[vertex].getAdjacencyList())
            {
                int adjacent = edge.getPosition();
                int weight = edge.getWeight();

                if (!nodes[adjacent].getVisited() && weight > 0)
                {
                    if (nodes[vertex].getDistance() + weight < nodes[adjacent].getDistance())
                    {
                        nodes[adjacent].setDistance(nodes[vertex].getDistance() + weight);
                        nodes[adjacent].setParent(vertex);
                        priorityQueue.push({ nodes[adjacent].getDistance(), adjacent });
                    }
                }
            }
        }
    }

    return *this;
}

template<class T>
inline void Graph<T>::printGraph()
{
    for (const auto& node : nodes) 
    {
        cout << "Node " << node.getData() << ": ";
        for (const auto& edge : node.getAdjacencyList()) 
            cout << "(" << edge.getPosition() << ", " << edge.getWeight() << ") ";
        cout << endl;
    }
}

template<class T>
inline void Graph<T>::printPath(int source, int destination)
{
    vector<int> stack;
    stack.push_back(destination);
    while (nodes[destination].getParent() != source)
    {
        stack.push_back(nodes[destination].getParent());
        destination = nodes[destination].getParent();
    }
    stack.push_back(source);
    reverse(stack.begin(), stack.end());
    for (int i = 0; i < stack.size(); i++)
        cout << stack[i] << " ";
    cout << endl;
}