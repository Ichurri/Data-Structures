#pragma once

enum class Color { RED, BLACK };

template<class T>
class Node
{
private:
	T data;
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	Color color;

public:
	Node();
	Node(T data);
	~Node();

	T getData();
	Node<T>* getLeft();
	Node<T>* getRight();
	Node<T>* getParent();
	Color getColor(); 

	void setData(T data);
	void setLeft(Node<T>* left);
	void setRight(Node<T>* right);
	void setParent(Node<T>* parent);
	void setColor(Color color); 
};

template<class T>
inline Node<T>::Node()
{
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->color = Color::RED; // Por defecto, un nuevo nodo es rojo
}

template<class T>
inline Node<T>::Node(T data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->color = Color::RED;
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
inline Node<T>* Node<T>::getParent()
{
	return parent;
}

template<class T>
inline Color Node<T>::getColor()
{
	return color;
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

template<class T>
inline void Node<T>::setParent(Node<T>* parent)
{
	this->parent = parent;
}

template<class T>
inline void Node<T>::setColor(Color color)
{
	this->color = color;
}
