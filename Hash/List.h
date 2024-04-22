#pragma once
#include "Node.h"
#include <string>
#include <sstream>

using namespace std;

template<class T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
public:
	List();
	~List();

	bool insertFirst(T data);
	bool insertLast(T data);
	bool deleteFirst();
	bool deleteLast();
	void deleteData(T data);
	void show();
	void bubbleSort();
	void deleteAll();
	int search(T data);
	T operator[](int index);
	List<T> merge(List<T> list1, List<T> list2);

	Node<T>* getFirst();
	Node<T>* getLast();

	int getInd();

};

template<class T>
inline List<T>::List()
{
	this->first = nullptr;
	this->last = nullptr;
}

template<class T>
inline List<T>::~List()
{
	deleteAll();
}

template<class T>
inline bool List<T>::insertFirst(T data)
{
	bool result = false;
	if (first == nullptr)
	{
		first = new Node<T>(data, nullptr, nullptr);
		last = first;
		result = true;
	}
	else
	{
		Node<T>* tmp = new Node<T>(data, first, nullptr);
		first->setPrevious(tmp);
		first = tmp;
		result = true;
	}
	return result;
}

template<class T>
inline bool List<T>::insertLast(T data)
{
	bool result = false;
	if (last == nullptr)
	{
		last = new Node<T>(data, nullptr, nullptr);
		first = last;
		result = true;
	}
	else
	{
		Node<T>* tmp = new Node<T>(data, nullptr, last);
		tmp->setPrevious(last);
		last->setNext(tmp);
		last = tmp;
		result = true;
	}
	return result;
}

template<class T>
inline bool List<T>::deleteFirst()
{
	bool result = true;
	if (first == nullptr)
		result = false;
	else
	{
		Node<T>* tmp = first;
		first = first->getNext();
		if (first)
			first->setPrevious(nullptr);
		else
			last = nullptr;
		delete tmp;
	}
	return result;
}

template<class T>
inline bool List<T>::deleteLast()
{
	bool result = true;
	if (last == nullptr)
		result = false;
	else
	{
		Node<T>* tmp = last;
		last = last->getPrevious();
		if (last)
			last->setNext(nullptr);
		delete tmp;
		if (last == nullptr)
			first = nullptr;
		else
			last->setNext(nullptr);
	}
	return result;
}

template<class T>
inline void List<T>::deleteData(T data)
{
	if (first != NULL)
	{
		if (data == first->getData())
			this->deleteFirst();
		else
		{
			if (data == last->getData())
				this->deleteLast();
			else
			{
				bool flag = false;
				Node<T>* current = first;
				Node<T>* next = first->getNext();
				while (next != nullptr && flag == false)
				{
					if (current->getData() == data)
					{
						next->setPrevious(current->getPrevious());
						current->getPrevious()->setNext(next);
						delete current;
						flag = true;
					}
					current = next;
					next = current->getNext();
				}
			}
		}
	}
	/*
	template<class T>
inline bool List8<T>::deleteData(T data)
{
	bool res = false;
	Node<T>* tmp = first;

	while (tmp != nullptr)
	{
		if (tmp->getData() == data)
		{
			if (tmp == first)
				deleteFirst();
			else if (tmp == last)
				deleteLast();
			else
			{
				Node<T>* prev = tmp->getPrevious();
				Node<T>* next = tmp->getNext();
				prev->setNext(next);
				next->setPrevious(prev);
				delete tmp;
			}
			res = true; // Se encontró y eliminó el dato
		}

		tmp = tmp->getNext();
	}

	return res; // No se encontró el dato en la lista
}
	*/
}


template<class T>
inline void List<T>::show()
{
	cout << "{";
	Node<T>* tmp = first;
	while (tmp != nullptr)
	{
		cout << tmp->getData();
		if (tmp->getNext() != nullptr)
			cout << " ,";
		tmp = tmp->getNext();
	}
	cout << "}";
	cout << endl;
}


template<class T>
inline void List<T>::bubbleSort()
{
	Node<T>* tmp = first;
	Node<T>* aux = tmp;
	while (tmp != NULL)
	{
		aux = tmp->getNext();
		while (aux != NULL)
		{
			if (tmp->getData() > aux->getData())
			{
				T datoAux = tmp->getData();
				tmp->setData(aux->getData());
				aux->setData(datoAux);
			}
			aux = aux->getNext();
		}
		tmp = tmp->getNext();
	}
}

template<class T>
inline void List<T>::deleteAll()
{
	if (first)
	{
		while (last)
		{
			deleteLast();
		}
	}
}

template<class T>
int List<T>::search(T dataSearch)
{
	Node<T>* tmp = first;
	int pos = 0;
	while (tmp != NULL)
	{
		if (tmp->getData() == dataSearch)
			return pos;
		tmp = tmp->getNext();
		pos++;
	}
	return -1;
}



template<class T>
inline T List<T>::operator[](int index)
{
	Node<T>* tmp = first;
	int position = 0;
	T found = NULL;
	while (tmp != nullptr)
	{
		if (position == index)
		{
			found = tmp->getData();
			break;
		}
		tmp = tmp->getNext();
		position++;
	}
	return found;
}

template<class T>
inline List<T> List<T>::merge(List<T> list1, List<T> list2)
{
	List<T> result;

	Node<T>* current1 = list1.first;
	Node<T>* current2 = list2.first;

	while (current1 != nullptr && current2 != nullptr)
	{
		result.insertLast(current1->getData());
		result.insertLast(current2->getData());
		current1 = current1->getNext();
		current2 = current2->getNext();
	}

	// Caso de que una lista sea mas grande que la otra
	while (current1 != nullptr)
	{
		result.insertLast(current1->getData());
		current1 = current1->getNext();
	}

	while (current2 != nullptr)
	{
		result.insertLast(current2->getData());
		current2 = current2->getNext();
	}

	return result;
}

template<class T>
inline Node<T>* List<T>::getFirst()
{
	return first;
}

template<class T>
inline Node<T>* List<T>::getLast()
{
	return last;
}

template<class T>
inline int List<T>::getInd()
{
	int count = 0;
	Node<T>* tmp = first;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->getNext();
	}
	return count;
}

