#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <stack>

using namespace std;

template <class T>
class Edge 
{
private:
    int position;
    int weight;

public:
    Edge(int position, int weight) : position(position), weight(weight) {};

    int getPosition() const;

    void setPosition(int position);

    int getWeight() const;

    void setWeight(int weight);
};

template<class T>
inline int Edge<T>::getPosition() const
{
    return position;
}

template<class T>
inline void Edge<T>::setPosition(int position)
{
    this->position = position;
}

template<class T>
inline int Edge<T>::getWeight() const
{
    return weight;
}

template<class T>
inline void Edge<T>::setWeight(int weight)
{
    this->weight = weight;
}
