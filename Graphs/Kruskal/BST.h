#include "BSTNode.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class BST
{
private:
	BSTNode<T>* root;


	BSTNode<T>* insertHelper(const T& data, const T& adjacent, int weight, BSTNode<T>*& root);
public:
	BST() : root(nullptr) {};
	~BST();

	BSTNode<T>*& getRoot();

	void inOrder(BSTNode<T>* index);


	BSTNode<T>* findMinorHelper(BSTNode<T>* index);
	BSTNode<T>* findGreaterHelper(BSTNode<T>* index);
	BSTNode<T>* deleteDataHelper(BSTNode<T>* index, T data);
	BSTNode<T>* searchNodeHelper(BSTNode<T>* index, const T& data);
	BSTNode<T>* searchNode(const T& data);
	void deleteData(T data);
	void insert(const T& data, const T& adjacent, int weight, BSTNode<T>*& root);
	const List<BSTNode<T>*> getNodes() const;

};

template<class T>
inline BST<T>::~BST()
{
	delete root;
}

template<class T>
inline BSTNode<T>*& BST<T>::getRoot()
{
	return root;
}

template<class T>
inline BSTNode<T>* BST<T>::searchNode(const T& data)
{
	return searchNodeHelper(root, data);
}

template<class T>
inline void BST<T>::deleteData(T data)
{
	root = deleteDataHelper(root, data);
}

template<class T>
inline void BST<T>::insert(const T& data, const T& adjacent, int weight, BSTNode<T>*& root)
{
	root = insertHelper(data, adjacent, weight, root);
}

template<class T>
inline const List<BSTNode<T>*> BST<T>::getNodes() const
{
	List<BSTNode<T>*> nodes;
	inOrderH(root, nodes);
	return nodes;
}

template<class T>
inline void BST<T>::inOrder(BSTNode<T>* index)
{
	if (index != nullptr)
	{
		inOrder(index->getLeft());
		cout << index->getData() << endl;
		index->getAdjacencyList().show();
		inOrder(index->getRight());
	}
}

template<class T>
inline BSTNode<T>* BST<T>::findMinorHelper(BSTNode<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getLeft() == nullptr)
		return index;

	return findMinorHelper(index->getLeft());
}

template<class T>
inline BSTNode<T>* BST<T>::findGreaterHelper(BSTNode<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getRight() == nullptr)
		return index;

	return findGreaterHelper(index->getRight());
}

template<class T>
inline BSTNode<T>* BST<T>::deleteDataHelper(BSTNode<T>* index, T data)
{
	if (index == nullptr)
		return index;

	if (data < index->getData())
		index->setLeft(deleteDataHelper(index->getLeft(), data));
	else if (data > index->getData())
		index->setRight(deleteDataHelper(index->getRight(), data));
	else
	{
		// Nodo sin hijos o con un solo hijo.
		if (index->getLeft() == nullptr)
		{
			BSTNode<T>* temp = index->getRight();
			delete index;
			return temp;
		}
		else if (index->getRight() == nullptr)
		{
			BSTNode<T>* temp = index->getLeft();
			delete index;
			return temp;
		}

		// Nodo con dos hijos, obtener el sucesor inorden.
		BSTNode<T>* temp = findMinorHelper(index->getRight());

		index->setData(temp->getData());

		index->setRight(deleteDataHelper(index->getRight(), temp->getData()));
	}
	return index;
}

template<class T>
inline BSTNode<T>* BST<T>::searchNodeHelper(BSTNode<T>* index, const T& data)
{
	if (index == nullptr)
		return nullptr;

	if (index->getData() == data)
		return index;

	if (data < index->getData())
		return searchNodeHelper(index->getLeft(), data);
	else
		return searchNodeHelper(index->getRight(), data);
}


template<class T>
inline BSTNode<T>* BST<T>::insertHelper(const T& data, const T& adjacent, int weight, BSTNode<T>*& index)
{
	if (index != nullptr)
	{
		if (data < index->getData())
			index->setLeft(insertHelper(data, adjacent, weight, index->getLeft()));
		else if (data > index->getData())
			index->setRight(insertHelper(data, adjacent, weight, index->getRight()));
		else
		{
			index->getAdjacencyList().insertLast(adjacent);
			index->getAdjacencyList().getLast()->setWeight(weight);
		}
		return index;
	}
	else
	{
		BSTNode<T>* current = new BSTNode<T>();
		current->setData(data);
		current->setParent(data);
		current->getAdjacencyList().insertLast(adjacent);
		current->getAdjacencyList().getLast()->setWeight(weight);
		return current;
	}
}


