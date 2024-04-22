#pragma once
#define TAM 10
#include <iostream>

using namespace std;

template<class T>
class List2
{
private:
    T arr[TAM];
    int first;
    int last;
public:
    List2();
    ~List2();

    bool insertFirst(T newElement);
    bool insertLast(T newElement);
    bool deleteFirst();
    bool deleteLast();
    void showList();
    int search(T target);
    void bubbleSort();
    List2<T> interleaveLists(List2<T> list1, List2<T> list2);
};

template<class T>
List2<T>::List2()
{
    first = -1;
    last = -1;
}

template<class T>
List2<T>::~List2()
{
}

template<class T>
bool List2<T>::insertFirst(T newElement)
{
    bool result;
    if ((first == 0 && last == TAM - 1) || (first == last + 1))
        result = false;
    else
    {
        result = true;
        if (first == -1)
        {
            first = 0;
            last = 0;
        }
        else if (first == 0)
            first = TAM - 1;
        else
            first--;
        arr[first] = newElement;
    }
    return result;
}

template<class T>
bool List2<T>::insertLast(T newElement)
{
    bool result;
    if ((first == 0 && last == TAM - 1) || (first == last + 1))
        result = false;
    else
    {
        result = true;
        if (last == -1)
        {
            first = 0;
            last = 0;
        }
        else if (last == TAM - 1)
            last = 0;
        else
            last++;
        arr[last] = newElement;
    }
    return result;
}

template<class T>
bool List2<T>::deleteFirst()
{
    bool result;
    if (first == -1)
        result = false;
    else
    {
        if (first == last)
        {
            first = -1;
            last = -1;
        }
        else if (first == TAM - 1)
            first = 0;
        else
            first++;
        result = true;
    }
    return result;
}

template<class T>
bool List2<T>::deleteLast()
{
    bool result;
    if (last == -1)
        result = false;
    else
    {
        if (first == last)
        {
            first = -1;
            last = -1;
        }
        else if (last == 0)
            last = TAM - 1;
        else
            last--;
        result = true;
    }
    return result;
}

template<class T>
void List2<T>::showList()
{
    if (first != -1)
    {
        int it = first;
        cout << "{";
        while (true)
        {
            cout << arr[it];
            if (it == last)
                break;
            if (it == TAM - 1)
                it = 0;
            else
                it++;
            if (arr[it + 1] != NULL)
                cout << ",";
        }
        cout << "}" << endl;
    }
}

template<class T>
int List2<T>::search(T target)
{
    int current = first;
    int pos = -1; // Inicializar la posici�n con un valor no v�lido
    if (current != -1)
    {
        do
        {
            if (arr[current] == target)
            {
                pos = current; // Actualizar la posici�n cuando se encuentra el elemento
                break;
            }

            if (current == TAM - 1)
                current = 0;
            else
                current++;
        } while (current != last);
    }

    return pos;
}

template<class T>
void List2<T>::bubbleSort()
{
    {
        if (first != -1)
        {
            int i = 0;
            int current = first;
            // Contar los elementos de la List2
            do
            {
                i++;
                if (current == last)
                    break;
                if (current == TAM - 1)
                    current = 0;
                else
                    current++;
            } while (current != last);
            i++;

            // Bubble sort
            for (int i = 0; i < n - 1; i++)
            {
                current = first;
                for (int j = 0; j < n - i - 1; j++)
                {
                    int next;
                    if (current == last)
                        break;
                    if (current == TAM - 1)
                        next = 0;
                    else
                        next = current + 1;

                    if (arr[current] > arr[next])
                        swap(arr[current], arr[next]);
                    current = next;
                }
            }
        }
    }

}

template<class T>
List2<T> List2<T>::interleaveLists(List2<T> list1, List2<T> list2)
{
    List2<T> result;

    int current1 = list1.first;
    int current2 = list2.first;

    while (current1 != -1 || current2 != -1)
    {
        if (current1 != -1)
        {
            result.insertLast(list1.arr[current1]);  // Insertar el elemento de List2 1 en result
            if (current1 == list1.last)  // Se llego al final de la List2
                current1 = -1;  // Ya no hay mas elementos
            else
                current1++;  // Hay mas elementos, sigue incrementando
        }

        if (current2 != -1)
        {
            result.insertLast(list2.arr[current2]);
            if (current2 == list2.last)
                current2 = -1;
            else
                current2++;
        }
    }

    return result;
}
