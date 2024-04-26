#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

template<class T>
class RedBlackTree
{
private:
    Node<T>* root;

    // Funciones privadas para el equilibrio del árbol
    void insertFixup(Node<T>* newNode);
    void deleteFixup(Node<T>* nodeToDelete);

    Node<T>* findSuccessor(Node<T>* node);
    void transplant(Node<T>* target, Node<T>* replacement);
    void rotateLeft(Node<T>* nodeToRotate);
    void rotateRight(Node<T>* nodeToRotate);

    Node<T>* findMinHelper(Node<T>* index);
    Node<T>* findMaxHelper(Node<T>* index);


    int countNodesHelper(Node<T>* index);

    void inOrderTraversalHelper(Node<T>* index);
    void preOrderTraversalHelper(Node<T>* index);
    void postOrderTraversalHelper(Node<T>* index);

    void mirrorHelper(Node<T>* index);

public:
    RedBlackTree();
    ~RedBlackTree();

    Node<T>* getRoot();

    Node<T>* searchData(T key);
    void insertData(T key);
    void removeData(T key);

    int calculateHeight();

    int countNodes();

    Node<T>* findMin();
    Node<T>* findMax();

    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();

    void mirror();
    void readFile(RedBlackTree& tree, const string& fileName);
    void searchOneMillion();

};

template<class T>
inline RedBlackTree<T>::RedBlackTree()
{
    root = nullptr;
}

template<class T>
inline RedBlackTree<T>::~RedBlackTree()
{
}

template<class T>
inline void RedBlackTree<T>::insertFixup(Node<T>* newNode)
{
    while (newNode != root && newNode->getParent()->getColor() == Color::RED)
    {
        if (newNode->getParent() == newNode->getParent()->getParent()->getLeft())
        {
            Node<T>* uncle = newNode->getParent()->getParent()->getRight();

            if (uncle != nullptr && uncle->getColor() == Color::RED)
            {
                // Caso 1: El tío es rojo
                newNode->getParent()->setColor(Color::BLACK);
                uncle->setColor(Color::BLACK);
                newNode->getParent()->getParent()->setColor(Color::RED);
                newNode = newNode->getParent()->getParent();
            }
            else
            {
                if (newNode == newNode->getParent()->getRight())
                {
                    // Caso 2: El tío es negro y el nodo es un hijo derecho
                    newNode = newNode->getParent();
                    rotateLeft(newNode);
                }

                // Caso 3: El tío es negro y el nodo es un hijo izquierdo
                newNode->getParent()->setColor(Color::BLACK);
                newNode->getParent()->getParent()->setColor(Color::RED);
                rotateRight(newNode->getParent()->getParent());
            }
        }
        else
        {
            Node<T>* uncle = newNode->getParent()->getParent()->getLeft();

            if (uncle != nullptr && uncle->getColor() == Color::RED)
            {
                // Caso 1: El tío es rojo
                newNode->getParent()->setColor(Color::BLACK);
                uncle->setColor(Color::BLACK);
                newNode->getParent()->getParent()->setColor(Color::RED);
                newNode = newNode->getParent()->getParent();
            }
            else
            {
                if (newNode == newNode->getParent()->getLeft())
                {
                    // Caso 2: El tío es negro y el nodo es un hijo izquierdo
                    newNode = newNode->getParent();
                    rotateRight(newNode);
                }

                // Caso 3: El tío es negro y el nodo es un hijo derecho
                newNode->getParent()->setColor(Color::BLACK);
                newNode->getParent()->getParent()->setColor(Color::RED);
                rotateLeft(newNode->getParent()->getParent());
            }
        }
    }

    root->setColor(Color::BLACK);
}

template<class T>
inline void RedBlackTree<T>::deleteFixup(Node<T>* nodeToDelete)
{
    while (nodeToDelete != root && nodeToDelete->getColor() == Color::BLACK)
    {
        if (nodeToDelete == nodeToDelete->getParent()->getLeft())
        {
            Node<T>* sibling = nodeToDelete->getParent()->getRight();

            if (sibling != nullptr)
            {
                if (sibling->getColor() == Color::RED)
                {
                    // Caso 1: El hermano es rojo
                    sibling->setColor(Color::BLACK);
                    nodeToDelete->getParent()->setColor(Color::RED);
                    rotateLeft(nodeToDelete->getParent());
                    sibling = nodeToDelete->getParent()->getRight();
                }

                if ((sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == Color::BLACK) &&
                    (sibling->getRight() == nullptr || sibling->getRight()->getColor() == Color::BLACK))
                {
                    // Caso 2: Ambos hijos del hermano son negros
                    sibling->setColor(Color::RED);
                    nodeToDelete = nodeToDelete->getParent();
                }
                else
                {
                    if (sibling->getRight() == nullptr || sibling->getRight()->getColor() == Color::BLACK)
                    {
                        // Caso 3: El hermano tiene un hijo derecho negro
                        sibling->getLeft()->setColor(Color::BLACK);
                        sibling->setColor(Color::RED);
                        rotateRight(sibling);
                        sibling = nodeToDelete->getParent()->getRight();
                    }

                    // Caso 4: El hermano es negro, y su hijo derecho es rojo
                    sibling->setColor(nodeToDelete->getParent()->getColor());
                    nodeToDelete->getParent()->setColor(Color::BLACK);
                    sibling->getRight()->setColor(Color::BLACK);
                    rotateLeft(nodeToDelete->getParent());
                    nodeToDelete = root; // Termina el bucle
                }
            }
            else
                nodeToDelete = nodeToDelete->getParent();// Caso especial: El hermano es nulo (negro)
        }
        else
        {
            Node<T>* sibling = nodeToDelete->getParent()->getLeft();

            if (sibling != nullptr)
            {
                if (sibling->getColor() == Color::RED)
                {
                    // Caso 1: El hermano es rojo
                    sibling->setColor(Color::BLACK);
                    nodeToDelete->getParent()->setColor(Color::RED);
                    rotateRight(nodeToDelete->getParent());
                    sibling = nodeToDelete->getParent()->getLeft();
                }

                if ((sibling->getRight() == nullptr || sibling->getRight()->getColor() == Color::BLACK) &&
                    (sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == Color::BLACK))
                {
                    // Caso 2: Ambos hijos del hermano son negros
                    sibling->setColor(Color::RED);
                    nodeToDelete = nodeToDelete->getParent();
                }
                else
                {
                    if (sibling->getLeft() == nullptr || sibling->getLeft()->getColor() == Color::BLACK)
                    {
                        // Caso 3: El hermano tiene un hijo izquierdo negro
                        sibling->getRight()->setColor(Color::BLACK);
                        sibling->setColor(Color::RED);
                        rotateLeft(sibling);
                        sibling = nodeToDelete->getParent()->getLeft();
                    }

                    // Caso 4: El hermano es negro, y su hijo izquierdo es rojo
                    sibling->setColor(nodeToDelete->getParent()->getColor());
                    nodeToDelete->getParent()->setColor(Color::BLACK);
                    sibling->getLeft()->setColor(Color::BLACK);
                    rotateRight(nodeToDelete->getParent());
                    nodeToDelete = root; 
                }
            }
            else
                nodeToDelete = nodeToDelete->getParent();// Caso especial: El hermano es nulo (negro)
        }
    }

    nodeToDelete->setColor(Color::BLACK);
}

template<class T>
inline Node<T>* RedBlackTree<T>::findSuccessor(Node<T>* node)
{
    while (node->getLeft() != nullptr)
        node = node->getLeft();
    return node;
}

template<class T>
inline void RedBlackTree<T>::transplant(Node<T>* target, Node<T>* replacement)
{
    if (target->getParent() == nullptr)
        root = replacement;
    else if (target == target->getParent()->getLeft())
        target->getParent()->setLeft(replacement);
    else
        target->getParent()->setRight(replacement);
    if (replacement != nullptr)
        replacement->setParent(target->getParent());
}

template<class T>
inline void RedBlackTree<T>::rotateLeft(Node<T>* nodeToRotate)
{
    Node<T>* rightChild = nodeToRotate->getRight();
    nodeToRotate->setRight(rightChild->getLeft());

    if (rightChild->getLeft() != nullptr)
        rightChild->getLeft()->setParent(nodeToRotate);

    rightChild->setParent(nodeToRotate->getParent());

    if (nodeToRotate->getParent() == nullptr)
        root = rightChild;
    else if (nodeToRotate == nodeToRotate->getParent()->getLeft())
        nodeToRotate->getParent()->setLeft(rightChild);
    else
        nodeToRotate->getParent()->setRight(rightChild);

    rightChild->setLeft(nodeToRotate);
    nodeToRotate->setParent(rightChild);
}

template<class T>
inline void RedBlackTree<T>::rotateRight(Node<T>* nodeToRotate)
{
    Node<T>* leftChild = nodeToRotate->getLeft();
    nodeToRotate->setLeft(leftChild->getRight());

    if (leftChild->getRight() != nullptr)
        leftChild->getRight()->setParent(nodeToRotate);

    leftChild->setParent(nodeToRotate->getParent());

    if (nodeToRotate->getParent() == nullptr)
        root = leftChild;
    else if (nodeToRotate == nodeToRotate->getParent()->getLeft())
        nodeToRotate->getParent()->setLeft(leftChild);
    else
        nodeToRotate->getParent()->setRight(leftChild);

    leftChild->setRight(nodeToRotate);
    nodeToRotate->setParent(leftChild);
}

template<class T>
inline Node<T>* RedBlackTree<T>::findMinHelper(Node<T>* index)
{
    if (index == nullptr)
        return nullptr;

    while (index->getLeft() != nullptr)
        index = index->getLeft();
    return index;
}

template<class T>
inline Node<T>* RedBlackTree<T>::findMaxHelper(Node<T>* index)
{
    if (index == nullptr)
        return nullptr;

    while (index->getRight() != nullptr)
        index = index->getRight();
    return index;
}

template<class T>
inline int RedBlackTree<T>::countNodesHelper(Node<T>* index)
{
    if (index == nullptr)
        return 0;

    return 1 + countNodesHelper(index->getLeft()) + countNodesHelper(index->getRight());
}

template<class T>
inline void RedBlackTree<T>::inOrderTraversalHelper(Node<T>* index)
{
    if (index != nullptr)
    {

        inOrderTraversalHelper(index->getLeft());
        cout << index->getData() << "(" << (index->getColor() == Color::RED ? "Rojo" : "Negro") << ")  ";
        inOrderTraversalHelper(index->getRight());;
    }
}

template<class T>
inline void RedBlackTree<T>::preOrderTraversalHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    cout << index->getData() << " (" << (index->getColor() == Color::RED ? "Rojo" : "Negro") << ")  ";
    preOrderTraversalHelper(index->getLeft());
    preOrderTraversalHelper(index->getRight());

}

template<class T>
inline void RedBlackTree<T>::postOrderTraversalHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    postOrderTraversalHelper(index->getLeft());
    postOrderTraversalHelper(index->getRight());
    cout << index->getData() << " (" << (index->getColor() == Color::RED ? "Rojo" : "Negro") << ")  ";
}

template<class T>
inline void RedBlackTree<T>::mirrorHelper(Node<T>* index)
{
    if (index == nullptr)
        return;

    Node<T>* temp = index->getLeft();
    index->setLeft(index->getRight());
    index->setRight(temp);

    mirrorHelper(index->getLeft());
    mirrorHelper(index->getRight());
}

template<class T>
inline Node<T>* RedBlackTree<T>::getRoot()
{
    return root;
}

template<class T>
inline Node<T>* RedBlackTree<T>::searchData(T key)
{
    Node<T>* currentNode = root;
    while (currentNode != nullptr)
    {
        if (key == currentNode->getData())
            return currentNode;
        else if (key < currentNode->getData())
            currentNode = currentNode->getLeft();
        else
            currentNode = currentNode->getRight();
    }
    return nullptr;
}

template<class T>
inline void RedBlackTree<T>::insertData(T key)
{
    Node<T>* newNode = new Node<T>(key);
    Node<T>* parent = nullptr;
    Node<T>* current = root;

    while (current != nullptr)
    {
        parent = current;
        if (key < current->getData())
            current = current->getLeft();
        else
            current = current->getRight();
    }

    newNode->setParent(parent);

    if (parent == nullptr)
        root = newNode; // Si el árbol estaba vacío, el nuevo nodo se convierte en la raíz
    else if (key < parent->getData())
        parent->setLeft(newNode);
    else
        parent->setRight(newNode);
    insertFixup(newNode); // Restaura las propiedades del árbol rojo-negro
}

template<class T>
inline void RedBlackTree<T>::removeData(T key)
{
    Node<T>* nodeToDelete = searchData(key);
    if (nodeToDelete == nullptr)
    {
        return; // El elemento no está en el árbol
    }

    Node<T>* nodeToReplace;
    Color originalColor = nodeToDelete->getColor();

    if (nodeToDelete->getLeft() == nullptr)
    {
        nodeToReplace = nodeToDelete->getRight();
        transplant(nodeToDelete, nodeToDelete->getRight());
    }
    else if (nodeToDelete->getRight() == nullptr)
    {
        nodeToReplace = nodeToDelete->getLeft();
        transplant(nodeToDelete, nodeToDelete->getLeft());
    }
    else
    {
        Node<T>* successor = findSuccessor(nodeToDelete);
        originalColor = successor->getColor();
        nodeToReplace = successor->getRight();

        if (successor->getParent() == nodeToDelete)
            nodeToReplace->setParent(successor);
        else
        {
            transplant(successor, successor->getRight());
            successor->setRight(nodeToDelete->getRight());
            successor->getRight()->setParent(successor);
        }

        transplant(nodeToDelete, successor);
        successor->setLeft(nodeToDelete->getLeft());
        successor->getLeft()->setParent(successor);
        successor->setColor(nodeToDelete->getColor());
    }

    delete nodeToDelete;

    if (originalColor == Color::BLACK)
        deleteFixup(nodeToReplace); // Restaura las propiedades del árbol rojo-negro
}

template<class T>
inline int RedBlackTree<T>::calculateHeight()
{
    return static_cast<int>(log2(countNodes() + 1));
}

template<class T>
inline int RedBlackTree<T>::countNodes()
{
    return countNodesHelper(root);
}

template<class T>
inline Node<T>* RedBlackTree<T>::findMin()
{
    Node<T>* minorNode = findMinHelper(root);
    if (minorNode)
        return minorNode;
    else
        cout << "El arbol esta vacio." << endl;
}

template<class T>
inline Node<T>* RedBlackTree<T>::findMax()
{
    Node<T>* maxNode = findMaxHelper(root);
    if (maxNode)
        return maxNode;
    else
        cout << "El arbol esta vacio." << endl;
}

template<class T>
inline void RedBlackTree<T>::inOrderTraversal()
{
    inOrderTraversalHelper(root);
}

template<class T>
inline void RedBlackTree<T>::preOrderTraversal()
{
    preOrderTraversalHelper(root);
}

template<class T>
inline void RedBlackTree<T>::postOrderTraversal()
{
    postOrderTraversalHelper(root);
}

template<class T>
inline void RedBlackTree<T>::mirror()
{
    mirrorHelper(root);
}

template<class T>
inline void RedBlackTree<T>::readFile(RedBlackTree& tree, const string& fileName)
{
    ifstream inputFile(fileName);
    T key;
    while (inputFile >> key)
        tree.insertData(key);
    inputFile.close();
}

template<class T>
inline void RedBlackTree<T>::searchOneMillion()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int randomNum = rand() % 1000000 + 1;
    for (int i = 0; i < 1000000; i++) 
        searchData(randomNum);
    if(searchData(randomNum)!= nullptr)
        cout << "El numero " << randomNum << " se encontro en el arbol." << endl;
    else 
     cout << "El numero " << randomNum << " no se encontro en el arbol." << endl;
}

