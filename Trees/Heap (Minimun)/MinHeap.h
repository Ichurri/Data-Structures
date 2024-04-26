#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class MinHeap
{
private:
    vector<T> heap;
    int lastLeaf;

    void heapifyUpDown(int leaf);
    void heapifyDownUp(int leaf);
public:
    MinHeap();
    ~MinHeap() {};

    void insert(T data);
    void show();
    T remove();
    int countNodes(int position);
    int calculateHeight(int position);
    vector<T> heapSort(vector<T> unsortedVector);
};

template<class T>
inline MinHeap<T>::MinHeap()
{
    lastLeaf = 0;
}

template<class T>
inline void MinHeap<T>::insert(T data)
{
    if (heap.size() == 0)
    {
        lastLeaf = 1;
        heap.push_back(-1);
        heap.push_back(data);
    }
    else
    {
        lastLeaf++;
        heap.push_back(data);
        heapifyDownUp(lastLeaf);
    }
}

template<class T>
inline void MinHeap<T>::heapifyUpDown(int leaf)
{
    int position = -1;
    if (heap.size() > leaf * 2 + 1)
    {
        if (heap[leaf] < heap[leaf * 2] && heap[leaf] < heap[leaf * 2 + 1])
        {
            if (heap[leaf * 2] > heap[leaf * 2 + 1])
            {
                position = leaf * 2;
                swap(heap[position], heap[leaf]);
            }
            else
            {
                position = leaf * 2 + 1;
                swap(heap[position], heap[leaf]);
            }
        }
        else
        {
            if (heap[leaf] < heap[leaf * 2])
            {
                position = leaf * 2;
                swap(heap[position], heap[leaf]);
            }
            else
            {
                if (heap[leaf] < heap[leaf * 2 + 1])
                {
                    position = leaf * 2 + 1;
                    swap(heap[position], heap[leaf]);
                }
            }
        }
    }
    else
    {
        if (heap.size() > leaf * 2)
        {
            if (heap[leaf] < heap[leaf * 2])
            {
                position = leaf * 2;
                swap(heap[position], heap[leaf]);
            }
        }
    }
    if (position != -1)
    {
        heapifyUpDown(position);
    }
}

template<class T>
inline void MinHeap<T>::heapifyDownUp(int leaf)
{
    if (leaf > 1)
    {
        if (heap[leaf] > heap[leaf / 2])
        {
            swap(heap[leaf], heap[leaf / 2]);
            heapifyDownUp(leaf / 2);
        }
    }
}

template<class T>
inline void MinHeap<T>::show()
{
    cout << "[";
    for (int i = 1; i < heap.size(); i++)
    {
        cout << heap[i];
        if (i < heap.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

template<class T>
inline T MinHeap<T>::remove()
{
    T value;
    if (heap.empty())
        value = NULL;
    else
    {
        value = heap[1];
        heap[1] = heap[lastLeaf];
        heap.pop_back();
        lastLeaf--;
        heapifyUpDown(1);
    }
    return value;
}

template<class T>
inline int MinHeap<T>::countNodes(int position)
{
    if (position <= lastLeaf) {
        int left = countNodes(position * 2);
        int right = countNodes(position * 2 + 1);
        return 1 + left + right; // Adds the current node, left and right.
    }
    return 0; // Indicate outside the limits of the tree.
}

template<class T>
inline int MinHeap<T>::calculateHeight(int position)
{
    if (position <= lastLeaf) {
        int leftHeight = calculateHeight(position * 2);
        int rightHeight = calculateHeight(position * 2 + 1);
        return 1 + std::max(leftHeight, rightHeight); // Maximum height of left and right subarbols.
    }
    return 0; // Empty tree or sign outside the limits of the tree.
}

template<class T>
inline vector<T> MinHeap<T>::heapSort(vector<T> unsortedVector)
{
    vector<T> sortedVector;
    for (int i = 0; i < unsortedVector.size(); i++)
        this->insert(unsortedVector[i]);
    for (int i = 0; i < unsortedVector.size(); i++)
        sortedVector.push_back(this->remove());
    return sortedVector;
}