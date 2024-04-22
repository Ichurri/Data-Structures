#pragma once
#include <iostream>
#include "List.h"
using namespace std;

template <class T>
class BSTNode
{
private:
	T element;
	BSTNode<T>* left;
	BSTNode<T>* right;

	List<string> m_list;
	T padre;
public:
	BSTNode();
	BSTNode(T elem, const List<T>& l);
	~BSTNode();

	T getElement() const;
	void setElement(const T& elem);

	BSTNode<T>*& getLeft();
	void setLeft(BSTNode<T>* l);

	BSTNode<T>*& getRight();
	void setRight(BSTNode<T>* r);

	List<string>& list();
	List<string> getList();
	T getPadre();
	void setPadre(T p);

	void setList(List<string> l);

	void copiarLista(List<string>& l);

};

template<class T>
inline BSTNode<T>::BSTNode()
{
	left = nullptr;
	right = nullptr;
}

template<class T>
inline BSTNode<T>::BSTNode(T elem, const List<T>& l)
	:element(elem), m_list(l)
{
	left = nullptr;
	right = nullptr;
}

template<class T>
inline BSTNode<T>::~BSTNode()
{

}

template<class T>
inline T BSTNode<T>::getElement() const
{
	return element;
}

template<class T>
inline void BSTNode<T>::setElement(const T& elem)
{
	element = elem;
}

template<class T>
inline BSTNode<T>*& BSTNode<T>::getLeft()
{
	return left;
}

template<class T>
inline void BSTNode<T>::setLeft(BSTNode<T>* l)
{
	left = l;
}

template<class T>
inline BSTNode<T>*& BSTNode<T>::getRight()
{
	return right;
}

template<class T>
inline void BSTNode<T>::setRight(BSTNode<T>* r)
{
	right = r;
}

template<class T>
inline List<string>& BSTNode<T>::list()
{
	return m_list;
}

template<class T>
inline List<string> BSTNode<T>::getList()
{
	return m_list;
}

template<class T>
inline T BSTNode<T>::getPadre()
{
	return padre;
}

template<class T>
inline void BSTNode<T>::setPadre(T p)
{
	padre = p;
}

template<class T>
inline void BSTNode<T>::setList(List<string> l)
{
	this->m_list = l;
}

template<class T>
inline void BSTNode<T>::copiarLista(List<string>& l)
{
	ListNode<T>* temp = l.getFirst();
	ListNode<T>* curr = m_list.getFirst();
	while (temp != nullptr)
	{
		curr = new ListNode<T>(temp->getElement(), nullptr, nullptr);
		curr = curr->getNext();
		temp = temp->getNext();
	}
}



