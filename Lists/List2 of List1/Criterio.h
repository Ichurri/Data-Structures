#pragma once
#include "List1.h"

template <class T>
class Criterio
{
private:
	List1<T> list;
	string crit;
public:
	Criterio(string crit, int critSize);
	Criterio();
	~Criterio() {};

	List1<T>& getList();
	string getCrit() const;
	void setCrit(const string& c);
};

template<class T>
inline Criterio<T>::Criterio(string crit, int critSize)
	:crit(crit), list(TAM)
{

}

template<class T>
inline Criterio<T>::Criterio()
{
	crit = " ";

}

template<class T>
inline List1<T>& Criterio<T>::getList()
{
	return list;
}

template<class T>
inline string Criterio<T>::getCrit() const
{
	return crit;
}

template<class T>
inline void Criterio<T>::setCrit(const string& c)
{
	this->crit = c;
}