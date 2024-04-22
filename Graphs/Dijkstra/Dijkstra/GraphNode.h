#pragma once
#include "Edge.h"

template <class T>
class GraphNode {
private:
    T data;
    bool visited;
    T parent;
    int distance;
    vector<Edge<T>> adjacencyList;

public:
    GraphNode(T data) : data(data), visited(false), parent(T()), distance(numeric_limits<int>::max()) {}

    T getData() const;
    void setData(T data);
    bool getVisited() const;
    void setVisited(bool visited);
    T getParent() const;
    void setParent(int parent);
    int getDistance() const;
    void setDistance(int distance);
    const vector<Edge<T>>& getAdjacencyList() const;
    void addAdjacent(int position, int weight);
};

template<class T>
inline T GraphNode<T>::getData() const
{
    return data;
}

template<class T>
inline void GraphNode<T>::setData(T data)
{
    this->data = data;
}

template<class T>
inline bool GraphNode<T>::getVisited() const
{
    return visited;
}

template<class T>
inline void GraphNode<T>::setVisited(bool visited)
{
    this->visited = visited;
}

template<class T>
inline T GraphNode<T>::getParent() const
{
    return parent;
}

template<class T>
inline void GraphNode<T>::setParent(int parent)
{
    this->parent = parent;
}

template<class T>
inline int GraphNode<T>::getDistance() const
{
    return distance;
}

template<class T>
inline void GraphNode<T>::setDistance(int distance)
{
    this->distance = distance;
}

template<class T>
inline const vector<Edge<T>>& GraphNode<T>::getAdjacencyList() const
{
    return adjacencyList;
}

template<class T>
inline void GraphNode<T>::addAdjacent(int position, int weight)
{
    adjacencyList.push_back(Edge<T>(position, weight));
}


