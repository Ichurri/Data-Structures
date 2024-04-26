#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"

using namespace std;

template<class T>
class BinaryTree
{
private:
    Node<T>* nodes;
    int size;
    int root;

    void inOrderHelper(int root);
    void preOrderHelper(int root);
    void postOrderHelper(int root);
    void mirrorHelper(int root);

public:
    BinaryTree(int maxSize);
    ~BinaryTree();

    void insertRandom(T data);
    int countNodes();
    int calculateHeight();
    void swapChildren(int root);
    void mirror();

    void inOrder();
    void preOrder();
    void postOrder();

    void showArray();
};

template<class T>
BinaryTree<T>::BinaryTree(int maxSize)
{
    size = maxSize;
    nodes = new Node<T>[size];
    root = 1; 
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    delete[] nodes;
}

template<class T>
void BinaryTree<T>::insertRandom(T data)
{
    if (nodes[root].getExistance() == false)
        nodes[root].setData(data);
    else
    {
        int pos = root;
        while (true)
        {
            int aux = rand() % 2;
            if (aux == 0)
                pos = 2 * pos;
            else
                pos = 2 * pos + 1;

            if (pos >= size)
            {
                cout << "The tree is full, no more data can be inserted." << endl;
                break;
            }

            if (nodes[pos].getExistance() == false)
            {
                nodes[pos].setData(data);
                break;
            }
        }
    }
}

template<class T>
int BinaryTree<T>::countNodes()
{
    int count = 0;
    for (int i = 1; i < size; i++)
    {
        if (nodes[i].getExistance())
            count++;
    }
    return count;
}

template<class T>
int BinaryTree<T>::calculateHeight()
{
    return static_cast<int>(log2(size + 1));

}

template<class T>
inline void BinaryTree<T>::swapChildren(int root)
{
    if (root < size && nodes[root].getExistance())
    {
        int leftChild = 2 * root;
        int rightChild = 2 * root + 1;

        swap(nodes[leftChild], nodes[rightChild]);
    }
}

template<class T>
inline void BinaryTree<T>::mirror()
{
    mirrorHelper(root); 
}


template<class T>
void BinaryTree<T>::inOrder()
{
    inOrderHelper(root);
}

template<class T>
void BinaryTree<T>::inOrderHelper(int root)
{
    if (root < size && nodes[root].getExistance())
    {
        inOrderHelper(2 * root); 
        cout << nodes[root].getData() << " ";
        inOrderHelper(2 * root + 1); 
    }
}

template<class T>
void BinaryTree<T>::preOrder()
{
    preOrderHelper(root);
}

template<class T>
void BinaryTree<T>::preOrderHelper(int root)
{
    if (root < size && nodes[root].getExistance())
    {
        cout << nodes[root].getData() << " ";
        preOrderHelper(2 * root); // <-
        preOrderHelper(2 * root + 1); // ->
    }
}

template<class T>
void BinaryTree<T>::postOrder()
{
    postOrderHelper(root);
}

template<class T>
void BinaryTree<T>::postOrderHelper(int root)
{
    if (root < size && nodes[root].getExistance())
    {
        postOrderHelper(2 * root);
        postOrderHelper(2 * root + 1);
        cout << nodes[root].getData() << " ";
    }
}

template<class T>
inline void BinaryTree<T>::mirrorHelper(int root)
{
    if (root < size && nodes[root].getExistance())
    {
        swapChildren(root);

        mirrorHelper(2 * root);
        mirrorHelper(2 * root + 1);
    }
}

template<class T>
inline void BinaryTree<T>::showArray()
{
    for (int i = 1; i < size; i++)
    {
        if (nodes[i].getExistance())
            cout << i << ": " << nodes[i].getData() << endl;
    }
}