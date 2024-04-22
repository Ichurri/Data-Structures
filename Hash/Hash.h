#pragma once
#include "List.h"
#include <string>
#include <fstream>

//36809

#define TAM 36809

template <class T>
class Hash
{
private:
	List<T> nodes[TAM];
	int collisions[21];
public:
	Hash();
	~Hash() {};

	int toAscii(string word);

	bool insertData(T data);
	bool deleteData(T data);
	int searchData(T data);
	void showData(T data);
	void showAll();
	void readFile(string location);

	void countCollisions();
};

template<class T>
inline Hash<T>::Hash()
{
}

template<class T>
inline int Hash<T>::toAscii(string word)
{
	int result = 0;
	for (int i = 0; i < word.length(); i++)
	{
		result = result + ((int)(word[i]) * pow(2, i));
	}
	return result % TAM;
}

template<class T>
inline bool Hash<T>::insertData(T data)
{
	bool result = false;
	nodes[toAscii(data)].insertFirst(data);
	result = true;
	return result;
}

template<class T>
inline bool Hash<T>::deleteData(T data)
{
	bool result = false;
	nodes[toAscii(data)].deleteData(data);
	result = true;
	return result;
}

template<class T>
inline int Hash<T>::searchData(T data)
{
	int pos;
	pos = nodes[toAscii(data)].searchData(data);
	return pos;
}

template<class T>
inline void Hash<T>::showData(T data)
{
	nodes[toAscii(data)].showData();
}

template<class T>
inline void Hash<T>::showAll()
{
	for (int i = 0; i < TAM; i++)
	{
		if (nodes[i].getFirst() != NULL)
			nodes[i].showData();
	}
}

template<class T>
inline void Hash<T>::readFile(string location)
{
	string data;
	ifstream file(location);
	int cont = 0;
	while (!file.eof())
	{
		if (cont == 0 || cont % 5 == 0)
			file >> data;
		else
		{
			file >> data;
			this->insertData(data);
		}
		cont++;
	}
	file.close();
}

template<class T>
inline void Hash<T>::countCollisions()
{
	for (int i = 0;i < 20; i++)
		collisions[i] = 0;
	for (int i = 0; i < TAM; i++)
		collisions[nodes[i].getInd()]++;
	for (int i = 0; i < 20; i++)
		cout << "Colision " << i << ": " << collisions[i] << endl;
}

