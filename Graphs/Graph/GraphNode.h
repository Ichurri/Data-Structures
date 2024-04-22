#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <class T>
class GraphNode {
private:
    T data;
    bool visited;
    T parent;
    vector<T> adjacencyList;

public:
    GraphNode(T value) : data(value), visited(false), parent(T()) {}

    T getData();
    void setData(T data);
    bool getVisited();
    void setVisited(bool visited);
    T getParent();
    void setParent(T parent);
    const vector<T>& getAdjacencyList();
    void addAdjacent(T value);
};

template<class T>
inline T GraphNode<T>::getData()
{
    return data;
}

template<class T>
inline void GraphNode<T>::setData(T data)
{
    this->data = data;
}

template<class T>
inline bool GraphNode<T>::getVisited()
{
    return visited;
}

template<class T>
inline void GraphNode<T>::setVisited(bool visited)
{
    this->visited = visited;
}

template<class T>
inline T GraphNode<T>::getParent()
{
    return parent;
}

template<class T>
inline void GraphNode<T>::setParent(T parent)
{
    this->parent = parent;
}

template<class T>
inline const vector<T>& GraphNode<T>::getAdjacencyList()
{
    return adjacencyList;
}

template<class T>
inline void GraphNode<T>::addAdjacent(T value)
{
    adjacencyList.push_back(value);
}
