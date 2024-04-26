#pragma once
#include <iostream>

class Node
{
private:
	char data;
	bool isLeaf;
	Node* firstChild;
	Node* brother;
public:
	Node(char data);
	~Node() {};

	char getData();
	bool getIsLeaf();
	Node* getFirstChild();
	Node* getBrother();

	void setData(char data);
	void setIsLeaf(bool isLeaf);
	void setFirstChild(Node* firstChild);
	void setBrother(Node* brother);
};

inline Node::Node(char data)
{
	this->data = data;
	isLeaf = false;
	firstChild = nullptr;
	brother = nullptr;
}

inline char Node::getData()
{
	return data;
}

inline bool Node::getIsLeaf()
{
	return isLeaf;
}

inline Node* Node::getFirstChild()
{
	return firstChild;
}

inline Node* Node::getBrother()
{
	return brother;
}

inline void Node::setData(char data)
{
	this->data = data;
}

inline void Node::setIsLeaf(bool isLeaf)
{
	this->isLeaf = isLeaf;
}

inline void Node::setFirstChild(Node* firstChild)
{
	this->firstChild = firstChild;
}

inline void Node::setBrother(Node* brother)
{
	this->brother = brother;
}