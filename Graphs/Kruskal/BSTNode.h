#pragma once
#include "List.h"

template<class T>
class BSTNode
{
private:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;

	List<string> adjacencyList;
	T parent;
public:
	BSTNode() : left(nullptr), right(nullptr) {};
	BSTNode(T data) : data(data), left(nullptr), right(nullptr) {};
	~BSTNode() {};

	T getData() const;
	BSTNode<T>*& getLeft();
	BSTNode<T>*& getRight();
	T getParent();
	List<string>& getAdjacencyList();

	void setData(const T& data);
	void setLeft(BSTNode<T>* left);
	void setRight(BSTNode<T>* right);
	void setParent(T parent);
};

template<class T>
inline T BSTNode<T>::getData() const
{
	return data;
}

template<class T>
inline BSTNode<T>*& BSTNode<T>::getLeft()
{
	return left;
}

template<class T>
inline BSTNode<T>*& BSTNode<T>::getRight()
{
	return right;
}

template<class T>
inline T BSTNode<T>::getParent()
{
	return parent;
}

template<class T>
inline List<string>& BSTNode<T>::getAdjacencyList()
{
	return adjacencyList;
}

template<class T>
inline void BSTNode<T>::setData(const T& data)
{
	this->data = data;
}

template<class T>
inline void BSTNode<T>::setLeft(BSTNode<T>* left)
{
	this->left = left;
}

template<class T>
inline void BSTNode<T>::setRight(BSTNode<T>* right)
{
	this->right = right;
}

template<class T>
inline void BSTNode<T>::setParent(T parent)
{
	this->parent = parent;
}

