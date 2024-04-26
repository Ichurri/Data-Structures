#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class BinarySearchTree
{
private:
	Node<T>* root;

	Node<T>* insertDataHelper(Node<T>* index, T data);
	bool searchDataHelper(Node<T>* index, T data);
	Node<T>* findMinorHelper(Node<T>* index);
	Node<T>* findGreaterHelper(Node<T>* index);
	Node<T>* deleteDataHelper(Node<T>* index, T data);
	int countNodeHelper(Node<T>* index);
	void displayArrayHelper(Node<T>* index);
	int calculateHeightHelper(Node<T>* index);
	void inOrderTraversalHelper(Node<T>* index);
	void preOrderTraversalHelper(Node<T>* index);
	void postOrderTraversalHelper(Node<T>* index);
	void mirrorHelper(Node<T>* index);
	Node<T>* searchNodeHelper(Node<T>* index, T data);
public:
	BinarySearchTree();
	~BinarySearchTree();

	Node<T>* getRoot();

	void insertData(T data);
	bool searchData(T data);
	Node<T>* searchNode(T data);
	T findMinor();
	T findGreater();
	void deleteData(T data);
	int countNode();
	int calculateHeight();
	void displayArray();
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
	void readFile(BinarySearchTree<T>& tree, const string& fileName);
	void mirror();
};

template<class T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
}

template<class T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	delete root;
}

template<class T>
inline Node<T>* BinarySearchTree<T>::getRoot()
{
	return root;	
}

template<class T>
inline Node<T>* BinarySearchTree<T>::insertDataHelper(Node<T>* index, T data)
{
	if (index == nullptr)
	{
		index = new Node<T>(data);
		return index;
	}

	if (data < index->getData())
		index->setLeft(insertDataHelper(index->getLeft(), data));
	else if (data > index->getData())
		index->setRight(insertDataHelper(index->getRight(), data));

	return index;
}

template<class T>
inline void BinarySearchTree<T>::insertData(T data)
{
	root = insertDataHelper(root, data);
}

template<class T>
inline bool BinarySearchTree<T>::searchDataHelper(Node<T>* index, T data)
{
	if (index == nullptr)
		return false;

	if (index->getData() == data)
		return true;

	if (data < index->getData())
		return searchDataHelper(index->getLeft(), data);
	else
		return searchDataHelper(index->getRight(), data);
}

template<class T>
inline bool BinarySearchTree<T>::searchData(T data)
{
	return searchDataHelper(root, data);
}

template<class T>
inline Node<T>* BinarySearchTree<T>::searchNode(T data)
{
	searchNodeHelper(root, data);
}

template<class T>
inline Node<T>* BinarySearchTree<T>::findMinorHelper(Node<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getLeft() == nullptr)
		return index;

	return findMinorHelper(index->getLeft());
}


template<class T>
inline T BinarySearchTree<T>::findMinor()
{
	Node<T>* minorNode = findMinorHelper(root);	
	if (minorNode)
		return minorNode->getData();
	else
		cout << "El arbol esta vacio." << endl;
}

template<class T>
inline Node<T>* BinarySearchTree<T>::findGreaterHelper(Node<T>* index)
{
	if (index == nullptr)
		return nullptr;

	if (index->getRight() == nullptr)
		return index;

	return findGreaterHelper(index->getRight());
}

template<class T>
inline T BinarySearchTree<T>::findGreater()
{
	Node<T>* greaterNode = findGreaterHelper(root);
	if (greaterNode)
		return greaterNode->getData();
	else
		cout << "El arbol esta vacio." << endl;
}

template<class T>
inline Node<T>* BinarySearchTree<T>::deleteDataHelper(Node<T>* index, T data)
{
	if (index == nullptr)
		return index;

	if (data < index->getData())
		index->setLeft(deleteDataHelper(index->getLeft(), data));
	else if (data > index->getData())
		index->setRight(deleteDataHelper(index->getRight(), data));
	else
	{
		if (index->getLeft() == nullptr)
		{
			Node<T>* temp = index->getRight();
			delete index;
			return temp;
		}
		else if (index->getRight() == nullptr)
		{
			Node<T>* temp = index->getLeft();
			delete index;
			return temp;
		}

		Node<T>* temp = findMinorHelper(index->getRight());

		index->setData(temp->getData());

		index->setRight(deleteDataHelper(index->getRight(), temp->getData()));
	}
	return index;
}

template<class T>
inline void BinarySearchTree<T>::deleteData(T data)
{
	root = deleteDataHelper(root, data);
}

template<class T>
inline int BinarySearchTree<T>::countNodeHelper(Node<T>* index)
{
	if (index == nullptr)
		return 0;

	return 1 + countNodeHelper(index->getLeft()) + countNodeHelper(index->getRight());
}

template<class T>
inline int BinarySearchTree<T>::countNode()
{
	return countNodeHelper(root);
}

template<class T>
inline int BinarySearchTree<T>::calculateHeightHelper(Node<T>* index)
{
	if (index == nullptr)
		return -1;
	int leftHeight = calculateHeightHelper(index->getLeft());
	int rightHeight = calculateHeightHelper(index->getRight());

	return max(leftHeight, rightHeight) + 1;
}


template<class T>
inline int BinarySearchTree<T>::calculateHeight()
{
	return calculateHeightHelper(root);
}

template<class T>
inline void BinarySearchTree<T>::displayArrayHelper(Node<T>* index)
{
	if (index == nullptr)
		return;
	displayArrayHelper(index->getLeft());
	cout << index->getData() << endl;
	displayArrayHelper(index->getRight());
}


template<class T>
inline void BinarySearchTree<T>::displayArray()
{
	displayArrayHelper(root);
}


template<class T>
inline void BinarySearchTree<T>::inOrderTraversalHelper(Node<T>* index)
{
	if (index == nullptr)
		return;

	inOrderTraversalHelper(index->getLeft());
	cout << index->getData() << " ";
	inOrderTraversalHelper(index->getRight());
}


template<class T>
inline void BinarySearchTree<T>::inOrderTraversal()
{
	inOrderTraversalHelper(root);
}

template<class T>
inline void BinarySearchTree<T>::preOrderTraversalHelper(Node<T>* index)
{
	if (index == nullptr)
		return;

	cout << index->getData() << " ";
	preOrderTraversalHelper(index->getLeft());
	preOrderTraversalHelper(index->getRight());
}

template<class T>
inline void BinarySearchTree<T>::preOrderTraversal()
{
	preOrderTraversalHelper(root);
}

template<class T>
inline void BinarySearchTree<T>::postOrderTraversalHelper(Node<T>* index)
{
	if (index == nullptr)
		return;

	postOrderTraversalHelper(index->getLeft());
	postOrderTraversalHelper(index->getRight());
	cout << index->getData() << " ";
}

template<class T>
inline void BinarySearchTree<T>::postOrderTraversal()
{
	postOrderTraversalHelper(root);
}

template<class T>
inline void BinarySearchTree<T>::readFile(BinarySearchTree<T>& tree, const string& fileName)
{
	ifstream inputFile(fileName);
	T number;
	while (inputFile >> number)
		tree.insertData(number);
	inputFile.close();
}


template<class T>
inline void BinarySearchTree<T>::mirrorHelper(Node<T>* index)
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
inline Node<T>* BinarySearchTree<T>::searchNodeHelper(Node<T>* index, T data)
{
	if (index == nullptr || index->getData() == data)
		return index;

	if (data < index->getData())
		return searchNodeHelper(index->getLeft(), data);
	else
		return searchNodeHelper(index->getRight(), data);
}

template<class T>
inline void BinarySearchTree<T>::mirror()
{
	mirrorHelper(root);
}