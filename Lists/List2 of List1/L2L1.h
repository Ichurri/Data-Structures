#pragma once
#include "Criterio.h"
#define SIZE 10

template <class T>
class L2L1
{
	int first;
	int last;
	int cantCriterios;


public:
	Criterio<T> critArray[SIZE];
	L2L1();
	~L2L1();
	const int insertFirst(const string& crit, const T& data);
	const int insertLast(const string& crit, const T& data);

	int getFirst();
	int getLast();

	const int deleteFirst();
	const int deleteLast();
	const int search(const string& crit, const T& data);
	void show();
	void showCriterio(const string& crit);
};

template<class T>
inline L2L1<T>::L2L1()
	:first(NULL), last(NULL), cantCriterios(0)
{

}

template<class T>
inline L2L1<T>::~L2L1()
{

}

template<class T>
inline const int L2L1<T>::insertFirst(const string& crit, const T& data)
{
	int result = 0;
	if (cantCriterios == SIZE)
	{
		result = -1;
	}
	else
	{
		if (first == NULL && last == NULL)
		{
			first = SIZE / 2;
			last = first;
			critArray[first].setCrit(crit);
			critArray[first].getList().insertLast(data);
			cantCriterios++;
		}
		else
		{
			int aux = first;
			while (crit != critArray[aux].getCrit() && aux != last)
			{
				aux = (aux + 1) % SIZE;
			}
			if (crit == critArray[aux].getCrit())
			{
				critArray[aux].getList().insertLast(data);
				cantCriterios++;
			}
			else
			{
				if (first == 0 && last != SIZE - 1)
					first = SIZE - 1;
				else
					first = (first - 1 + SIZE) % SIZE;
				critArray[first].setCrit(crit);
				critArray[first].getList().insertLast(data);
				cantCriterios++;
			}

		}
	}
	return result;
}

template<class T>
inline const int L2L1<T>::insertLast(const string& crit, const T& data)
{
	int result = 0;
	if (cantCriterios == SIZE)
	{
		result = -1;
	}
	else
	{
		if (first == NULL && last == NULL)
		{
			first = SIZE / 2;
			last = first;
			critArray[first].setCrit(crit);
			critArray[first].getList().insertLast(data);
		}
		else
		{
			int aux = first;
			while (crit != critArray[aux].getCrit() && aux != last)
			{
				aux = (aux + 1) % SIZE;
			}
			if (crit == critArray[aux].getCrit())
			{
				critArray[aux].getList().insertLast(data);
			}
			else
			{
				if (last == SIZE - 1 && first != 0)
					last = 0;
				else
					last = (last + 1) % SIZE;
				critArray[last].setCrit(crit);
				critArray[last].getList().insertLast(data);
			}
		}
	}
	return result;
}

template<class T>
inline int L2L1<T>::getFirst()
{
	return first;
}

template<class T>
inline int L2L1<T>::getLast()
{
	return last;
}

template<class T>
inline const int L2L1<T>::deleteFirst()
{
	int result = 0;
	if (first == NULL && last == NULL)
	{
		result = -1;
	}
	else
	{
		if (first == last)
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			if (first == SIZE - 1)
				first = 0;
			else
				first++;
		}
	}
	return result;
}

template<class T>
inline const int L2L1<T>::deleteLast()
{
	int result = 0;
	if (first == NULL && last == NULL)
	{
		result = -1;
	}
	else
	{
		if (first == last)
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			if (last == 0)
				last = SIZE - 1;
			else
				last--;
		}
	}
	return result;
}

template<class T>
inline const int L2L1<T>::search(const string& crit, const T& data)
{
	int i = first;
	while (i != last)
	{
		if (crit == critArray[i].getCrit())
			return critArray[i].getList().search(data);
		if (i == SIZE - 1)
			i = 0;
		else
			i++;
	}
	return -1;
}

template<class T>
inline void L2L1<T>::show()
{
	int i = first;
	while (i != last)
	{
		cout << "[" << critArray[i].getCrit() << "]" << endl;
		critArray[i].getList().show();
		cout << endl;
		if (i == SIZE - 1)
			i = 0;
		else
			i++;
	}
	cout << "[" << critArray[i].getCrit() << "]" << endl;
	critArray[i].getList().show();
	cout << endl;
}

template<class T>
inline void L2L1<T>::showCriterio(const string& crit)
{
	int i = first;
	bool res = false;
	while (i != last)
	{
		if (crit == critArray[i].getCrit())
		{
			res = true;
			cout << "[" << critArray[i].getCrit() << "]" << endl;
			critArray[i].getList().show();
			cout << endl;
			break;
		}
		if (i == SIZE - 1)
			i = 0;
		else
			i++;
	}
	if(res == false)
		cout << "Criterion was not found" << endl;
}
