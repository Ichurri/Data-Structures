#pragma once

template<class T>
class Node
{
private:
	T data;
	Node<T>* left;
	Node<T>* right;
public:
	Node();
	Node(T data);
	~Node();

	T getData();
	Node<T>* getLeft();
	Node<T>* getRight();

	void setData(T data);
	void setLeft(Node<T>* left);
	void setRight(Node<T>* right);

};

template<class T>
inline Node<T>::Node()
{
	this->left = nullptr;
	this->right = nullptr;
}

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

template<class T>
inline Node<T>::~Node()
{

}

template<class T>
inline T Node<T>::getData()
{
	return data;
}

template<class T>
inline Node<T>* Node<T>::getLeft()
{
	return left;
}

template<class T>
inline Node<T>* Node<T>::getRight()
{
	return right;
}

template<class T>
inline void Node<T>::setData(T data)
{
	this->data = data;
}

template<class T>
inline void Node<T>::setLeft(Node<T>* left)
{
	this->left = left;
}

template<class T>
inline void Node<T>::setRight(Node<T>* right)
{
	this->right = right;
}

