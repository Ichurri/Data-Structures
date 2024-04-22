#pragma once
#include "ListNode.h"
#include "cmath"
template<class T>
class List
{
private:
	ListNode<T>* first;
	ListNode<T>* last;
	int cant;
public:
	List();
	List(const List<T>& l);
	~List();

	ListNode<T>* getLast();

	const int insertFirst(const T& element);
	const int insertLast(const T& element);
	const int deleteFirst();
	const int deleteLast();

	const void deleteElement(const T& element);

	void show() const;
	const int search(T element) const;
	void sort(const bool(*cmp)(const T&, const T&));
	void deleteAll();
	T operator[](int index) const;
	const static bool compAsc(const T& t1, const T& t2);
	const static bool compDesc(const T& t1, const T& t2);

	const int getCant() const;
	ListNode<T>* getFirst();
	void operator=(List<T> l);

	bool isEmpty() { return cant == 0; }

};

template<class T>
inline List<T>::List()
	:first(NULL), last(NULL), cant(0)
{

}

template<class T>
inline List<T>::List(const List<T>& l)
{
	this->first = (l.first == NULL) ? NULL : new ListNode<T>(*l.first);
	this->last = (l.last == NULL) ? NULL : new ListNode<T>(*l.last);
	this->cant = l.cant;
}

template<class T>
inline List<T>::~List()
{
	deleteAll();
}

template<class T>
inline ListNode<T>* List<T>::getLast()
{
	return last;
}

template<class T>
inline const int List<T>::insertFirst(const T& element)
{
	int result = 0;
	if (first == NULL)
	{
		first = new ListNode<T>(element, NULL, NULL);
		last = first;
	}
	else
	{
		ListNode<T>* tmp = new ListNode<T>(element, first, NULL);
		first->setPre(tmp);
		first = tmp;
	}
	cant++;
	return result;

}

template<class T>
inline const int List<T>::insertLast(const T& element)
{
	int result = 0;
	if (first == NULL && last == NULL)
	{
		first = new ListNode<T>(element, NULL, NULL);
		last = first;
	}
	else
	{
		ListNode<T>* newLast = new ListNode<T>(element, NULL, last);
		last->setNext(newLast);
		last = newLast;
	}
	cant++;
	return result;
}

template<class T>
inline const int List<T>::deleteFirst()
{
	int result = 0;
	if (first == NULL)
	{
		result = -1;
	}
	else
	{
		ListNode<T>* tmp = first;
		first = first->getNext();

		delete tmp;
		if (first == NULL)
		{
			last = NULL;
		}
		else
		{
			first->setPre(NULL);
		}
		cant--;
	}
	return result;
}

template<class T>
inline const int List<T>::deleteLast()
{
	int result = 0;
	if (first == NULL)
	{
		result = -1;
	}
	else
	{
		ListNode<T>* tmp = last;
		last = last->getPre();

		delete tmp;
		if (last == NULL)
			first = NULL;
		else
			last->setNext(NULL);
		cant--;
	}
	return result;
}

template<class T>
const void List<T>::deleteElement(const T& element)
{
	ListNode<T>* current = first;
	while (current != nullptr) {
		ListNode<T>* temp = current;
		current = current->getNext();

		if (temp->getElement() == element) {
			if (temp == first) {
				first = temp->getNext();
				if (first != nullptr) {
					first->setPre(nullptr);
				}
			}
			else {
				temp->getPre()->setNext(temp->getNext());
				if (temp->getNext() != nullptr) {
					temp->getNext()->setPre(temp->getPre());
				}
			}
			if (temp == last) {
				last = temp->getPre();
				if (last != nullptr) {
					last->setNext(nullptr);
				}
			}
			delete temp;
			cant--;
		}
	}
}


template<class T>
inline void List<T>::show() const
{
	if (first == NULL)
	{
		cout << " " << endl;
	}
	else
	{
		ListNode<T>* tmp = first;
		while (tmp != NULL)
		{
			cout << tmp->getElement();
			cout << " / ";
			tmp = tmp->getNext();
		}
		cout << endl;
	}
}

template<class T>
inline const int List<T>::search(T element)	const
{
	ListNode<T>* tmp = first;
	int index = -1;
	int foundIndex = -1;

	while (tmp != NULL)
	{
		index++;
		if (tmp->getElement() == element)
		{
			foundIndex = index;
			break;
		}
		tmp = tmp->getNext();
	}

	return foundIndex;
}

template<class T>
inline void List<T>::sort(const bool(*cmp)(const T&, const T&))
{
	ListNode<T>* temp1 = first;
	ListNode<T>* temp2 = temp1;
	while (temp1 != NULL)
	{
		temp2 = temp1->getNext();
		while (temp2 != NULL)
		{
			if ((*cmp)(temp1->getElement(), temp2->getElement()))
			{
				T datoTemp = temp1->getElement();
				temp1->setElement(temp2->getElement());
				temp2->setElement(datoTemp);
			}
			temp2 = temp2->getNext();
		}
		temp1 = temp1->getNext();
	}
}

template<class T>
inline void List<T>::deleteAll()
{
	ListNode<T>* temp = first;

	while (temp != NULL)
	{
		ListNode<T>* nextNode = temp->getNext();
		delete temp;
		temp = nextNode;
	}

	first = NULL;
	last = NULL;
}

template<class T>
inline T List<T>::operator[](int index) const
{
	int i = 0;
	ListNode<T>* tmp = first;
	T encontrado = NULL;
	while (tmp != NULL)
	{
		if (i == index)
			encontrado = tmp->getElement();
		i++;
		tmp = tmp->getNext();
	}
	return encontrado;
}

template<class T>
const inline bool List<T>::compAsc(const T& t1, const T& t2)
{
	return t1 > t2;
}

template<class T>
const inline bool List<T>::compDesc(const T& t1, const T& t2)
{
	return t1 < t2;
}

template<class T>
inline const int List<T>::getCant() const
{
	return cant;
}

template<class T>
inline ListNode<T>* List<T>::getFirst()
{
	return first;
}

template<class T>
inline void List<T>::operator=(List<T> l)
{
	this->first = (l.first == nullptr) ? nullptr : new ListNode<T>(*l.first);
	this->last = (l.last == nullptr) ? nullptr : new ListNode<T>(*l.last);
	this->cant = l.cant;
}

