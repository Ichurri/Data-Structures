#pragma once
#define TAM 50
#include <iostream>

using namespace std;

template <class T>
class List1
{
private:
	T arr[TAM];
	int last;
public:
	List1();
	~List1();
	int getLast();
	void insert(T data);
	void deleteList1();
	void show();
};

template<class T>
inline List1<T>::List1()
{
	last = -1;
}

template<class T>
inline List1<T>::~List1()
{
}

template<class T>
inline int List1<T>::getLast()
{
	return last;
}

template<class T>
inline void List1<T>::insert(T data)
{
	if (last < TAM - 1)
	{
		last++;
		arr[last] = data;
	}

}

template<class T>
inline void List1<T>::deleteList1()
{
	if (last >= 0)
		last--;
}

template<class T>
inline void List1<T>::show()
{
	cout << "{";
	for (int i = 0; i <= last; i++)
	{
		cout << arr[i];
		if (i != last)
			cout << ", ";
	}
	cout << "}";
}


