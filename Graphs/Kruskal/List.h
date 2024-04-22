#pragma once
#include "ListNode.h"
#include <string>
#include <sstream>

using namespace std;

template<class T>
class List
{
private:
	ListNode<T>* first;
	ListNode<T>* last;
	int amount;
public:
	List() :first(nullptr), last(nullptr), amount(0) {};
	~List();

	ListNode<T>* getFirst();
	ListNode<T>* getLast();
	int getAmount();

	bool insertFirst(T data);
	bool insertLast(T data);
	bool deleteFirst();
	bool deleteLast();

	const bool deleteData(const T& data);

	void show();
	void bubbleSort();
	void deleteAll();
	void search(T data);
	T operator[](int index);
	void setAmount(int amount);
};

template<class T>
inline List<T>::~List()
{
	deleteAll();
}

template<class T>
inline ListNode<T>* List<T>::getFirst()
{
	return first;
}

template<class T>
inline ListNode<T>* List<T>::getLast()
{
	return last;
}

template<class T>
inline int List<T>::getAmount()
{
	return amount;
}

template<class T>
inline bool List<T>::insertFirst(T data)
{
	bool result = false;
	if (first == nullptr)
	{
		first = new ListNode<T>(data, nullptr, nullptr);
		last = first;
		result = true;
	}
	else
	{
		ListNode<T>* tmp = new ListNode<T>(data, first, nullptr);
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
		last = new ListNode<T>(data, nullptr, nullptr);
		first = last;
		result = true;
	}
	else
	{
		ListNode<T>* tmp = new ListNode<T>(data, nullptr, last);
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
		ListNode<T>* tmp = first;
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
		ListNode<T>* tmp = last;
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
inline const bool List<T>::deleteData(const T& data)
{
	bool res = false;
	ListNode<T>* tmp = first;

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
				ListNode<T>* prev = tmp->getPrevious();
				ListNode<T>* next = tmp->getNext();
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


template<class T>
inline void List<T>::show()
{
	if(first!= NULL)
	{
		ListNode<T>* tmp = first;
		while (tmp != NULL)
		{
			cout << tmp->getData() << ": " << tmp->getWeight() << " | ";
			tmp = tmp->getNext();
			cout << endl;
		}
		cout << endl;
	}
}


template<class T>
inline void List<T>::bubbleSort()
{
	ListNode<T>* tmp = first;
	ListNode<T>* tmp = tmp;
	while (tmp != NULL)
	{
		tmp = tmp->getNext();
		while (tmp != NULL)
		{
			if (tmp->getData() > tmp->getData())
			{
				T datotmp = tmp->getData();
				tmp->setData(tmp->getData());
				tmp->setData(datotmp);
			}
			tmp = tmp->getNext();
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
inline void List<T>::search(T data)
{
	ListNode<T>* tmp = first;
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
inline T List<T>::operator[](int index)
{
	ListNode<T>* tmp = first;
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
inline void List<T>::setAmount(int amount)
{
	this->amount = amount;
}

