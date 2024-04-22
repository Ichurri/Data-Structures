#pragma once
#include <iostream>
#define TAM 10
using namespace std;

template <class T>
class List1
{
	T vec[TAM];
	int last;
public:
	List1();
	~List1();

	const int insertLast(const T& data);
	const int deleteLast();

	void show();
	const int search(const T& toSearch);

	T& operator[](int index);

};

template<class T>
inline List1<T>::List1()
	:last(0)
{

}

template<class T>
inline List1<T>::~List1()
{

}

template<class T>
inline const int List1<T>::insertLast(const T& data)
{
	int result = 0;
	if (last < TAM)
	{
		vec[last] = data;
		last++;
	}
	else
	{
		result = -1;
	}
	return result;
}

template<class T>
inline const int List1<T>::deleteLast()
{
	int result = 0;
	if (last > 0)
	{
		last--;
	}
	else
	{
		result = -1;
	}
	return result;
}

template<class T>
inline void List1<T>::show()
{
	cout << "{";
	for (int i = 0; i < last; i++)
	{
		cout << vec[i];
		if (i < last - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}

template<class T>
inline const int List1<T>::search(const T& toSearch)
{
	int result = -1;
	for (int i = 0; i < last; i++)
	{
		if (vec[i] == toSearch)
		{
			result = i;
			break;
		}
	}
	return result;
}

template<class T>
inline T& List1<T>::operator[](int index)
{
	return vec[index];
}
