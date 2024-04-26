#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>  
#include <cmath>

using namespace std; 

template <class T>
class ArrayBinaryTree
{
private:
    vector<T> treeArray;
    int size;

public:
    ArrayBinaryTree(int capacity);
    void insertRandom(T data);
    int countNodes();
    int calculateHeight();
    void inOrderTraversal(int index);
    void preOrderTraversal(int index);
    void postOrderTraversal(int index);
    void showArray();
};

template <class T>
ArrayBinaryTree<T>::ArrayBinaryTree(int capacity)
{
    treeArray.resize(capacity);
    size = 0;
}

template <class T>
void ArrayBinaryTree<T>::insertRandom(T data)
{
    if (size >= treeArray.size())
    {
        cout << "The tree is full, no more data can be inserted." << endl;
        return;
    }

    srand(time(0));
    int index = rand() % (size + 1);

    treeArray[size] = data;

    for (int i = size; i > index; i--)
        treeArray[i] = treeArray[i - 1];

    treeArray[index] = data;
    size++;
}

template <class T>
int ArrayBinaryTree<T>::countNodes()
{
    return size;
}

template <class T>
int ArrayBinaryTree<T>::calculateHeight()
{
    return static_cast<int>(log2(size + 1));
    /*
    int height = 0;
    int index = size - 1;

    while (index >= 0)
    {
        height++;
        index = (index - 1) / 2;
    }

    return height;
    */
}

template <class T>
void ArrayBinaryTree<T>::inOrderTraversal(int index)
{
    if (index < size)
    {
        inOrderTraversal(2 * index + 1);
        cout << treeArray[index] << " ";
        inOrderTraversal(2 * index + 2);
    }
}

template <class T>
void ArrayBinaryTree<T>::preOrderTraversal(int index)
{
    if (index < size)
    {
        cout << treeArray[index] << " ";
        preOrderTraversal(2 * index + 1);
        preOrderTraversal(2 * index + 2);
    }
}

template <class T>
void ArrayBinaryTree<T>::postOrderTraversal(int index)
{
    if (index < size)
    {
        postOrderTraversal(2 * index + 1);
        postOrderTraversal(2 * index + 2);
        cout << treeArray[index] << " ";
    }
}

template<class T>
void ArrayBinaryTree<T>::showArray()
{
    for (int i = 0; i < treeArray.size(); i++)
        cout << i << ": " << treeArray[i] << endl;
}
