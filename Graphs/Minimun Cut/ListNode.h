#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class ListNode
{
private:
	T element;
	ListNode<T>* next;
	ListNode<T>* pre;
public:
	ListNode(T element, ListNode<T>* next, ListNode<T>* pre);
	ListNode(const ListNode<T>& n);
	~ListNode() {};

	T getElement() const;
	ListNode<T>* getNext() const;
	ListNode<T>* getPre() const;

	void setElement(const T& element);
	void setNext(ListNode<T>* next);
	void setPre(ListNode<T>* pre);

	void CreateNext(const T& element);

};

template<class T>
inline ListNode<T>::ListNode(T element, ListNode<T>* next, ListNode<T>* pre)
	:element(element), next(next), pre(pre)
{

}

template<class T>
inline ListNode<T>::ListNode(const ListNode<T>& n)
	: element(n.element), pre(nullptr), next(nullptr)
{
	if (n.next != nullptr)
	{
		next = new ListNode<T>(*n.next);
		next->pre = this;
	}
}

template<class T>
inline T ListNode<T>::getElement() const
{
	return element;
}


template<class T>
inline ListNode<T>* ListNode<T>::getNext() const
{
	return next;
}

template<class T>
inline ListNode<T>* ListNode<T>::getPre() const
{
	return pre;
}

template<class T>
inline void ListNode<T>::setElement(const T& element)
{
	this->element = element;
}

template<class T>
inline void ListNode<T>::setNext(ListNode<T>* next)
{
	this->next = next;
}

template<class T>
inline void ListNode<T>::setPre(ListNode<T>* pre)
{
	this->pre = pre;
}

template<class T>
inline void ListNode<T>::CreateNext(const T& element)
{
	next = new ListNode<T>(element, NULL, this);
}
