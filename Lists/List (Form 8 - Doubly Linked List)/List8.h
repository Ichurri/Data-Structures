#pragma once
#include "Node.h"
#include <string>
#include <sstream>

using namespace std;

template<class T>
class List8
{
private:
	Node<T>* first;
	Node<T>* last;
public:
	List8();
	~List8();

	bool insertFirst(T data);
	bool insertLast(T data);
	bool deleteFirst();
	bool deleteLast();
	bool deleteData(T data);
	void show();
	void bubbleSort();
	void deleteAll();
	void search(T data);
	T operator[](int index);
	List8<T> merge(List8<T> list1, List8<T> list2);
};

template<class T>
inline List8<T>::List8()
{
	this->first = nullptr;
	this->last = nullptr;
}

template<class T>
inline List8<T>::~List8()
{
	deleteAll();	
}

template<class T>
inline bool List8<T>::insertFirst(T data)
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
inline bool List8<T>::insertLast(T data)
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
inline bool List8<T>::deleteFirst()
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
inline bool List8<T>::deleteLast()
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
			res = true;	
		}

		tmp = tmp->getNext();
	}

	return res; 
}


template<class T>
inline void List8<T>::show()
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
inline void List8<T>::bubbleSort()
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
inline void List8<T>::deleteAll()
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
inline void List8<T>::search(T data)
{
	Node<T>* tmp = first;
	int position = 0;
	while (tmp != nullptr)
	{
		if (tmp->getData() == data)
		{
			cout << "Dato " << data << " encontrado en la posicion: " << position << endl;
			return;
		}
		tmp = tmp->getNext();
		position++;
	}
	cout << "Dato " << data << " no encontrado en la lista." << endl;
}

template<class T>
inline T List8<T>::operator[](int index)
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
inline List8<T> List8<T>::merge(List8<T> list1, List8<T> list2)
{
	List8<T> result;

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

