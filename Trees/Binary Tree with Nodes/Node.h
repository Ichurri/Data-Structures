#pragma once
#include <iostream>
#include "string"

using namespace std;

template<class T>
class Node
{
private:
	T data;
	bool exist;
public:
	Node();
	~Node();
	void setData(T d);
	T getData();
	bool getExistance();
};

template<class T>
inline Node<T>::Node()
{
	data = NULL;
	exist = false;
}

template<class T>
inline Node<T>::~Node()
{
}


template<class T>
inline void Node<T>::setData(T d)
{
	this->data = d;
	exist = true;
}

template<class T>
inline T Node<T>::getData()
{
	return data;
}

template<class T>
inline bool Node<T>::getExistance()
{
	if (exist)
		return true;
	return false;
}
