#pragma once
#include "BST.h"
#include <tuple>
#include <string>
#include <queue>
#include <vector>

template<class T>
class Graph
{
private:
	BST<string> graph;
	int countEdges = 0;
	priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> priorityQueque;
public:
	Graph() {};
	~Graph() {};
	string cycle(string destiny);
	BST<string> getGraph();
	void insert(string source, string destiny, int weight);
	void printGraph();

	priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> getPriorityQueque();

	//Defensa 
	void loadFromFile(const string& filename);
	void showAdjacencyList(const T& vertex);
	void kruskal(Graph& AE, int& total);
	void contractEdge(const string& source, const string& destiny);
	int minCut();
};



template<class T>
inline string Graph<T>::cycle(string destiny)
{
	BSTNode<string>* node = graph.searchNodeHelper(graph.getRoot(), destiny);
	while (destiny != node->getParent())
	{
		destiny = node->getParent();
		node = graph.searchNodeHelper(graph.getRoot(), destiny);
	}
	return destiny;
}

template<class T>
inline BST<string> Graph<T>::getGraph()
{
	return graph;
}

template<class T>
inline void Graph<T>::insert(string source, string destiny, int weight)
{
	graph.insert(source, destiny, weight, graph.getRoot());
	graph.insert(destiny, source, weight, graph.getRoot());
	priorityQueque.push(make_tuple(weight, source, destiny));
	countEdges++;
}

template<class T>
inline void Graph<T>::printGraph()
{
	graph.inOrder(graph.getRoot());
}

template<class T>
inline priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>> Graph<T>::getPriorityQueque()
{
	return priorityQueque;
}

template<class T>
inline void Graph<T>::loadFromFile(const string& filename)
{
	ifstream file(filename);
	string source, destiny;
	int weight;

	while (file >> source >> destiny >> weight) 
		insert(source, destiny, weight);

	file.close();
}

template<class T>
inline void Graph<T>::showAdjacencyList(const T& vertex)
{
	BSTNode<string>* node = graph.searchNode(vertex);

	if (node)
	{
		cout << "Lista de adyacentes para el nodo " << vertex << ":" << endl;
		node->getAdjacencyList().show();
	}
	else
		cout << "El nodo " << vertex << " no se encuentra en el grafo." << endl;
}

template<class T>
inline void Graph<T>::kruskal(Graph& AE, int& total)
{
	tuple<int, string, string> triplet;
	int count = 0;
	string originVertex, destinyVertex, tmp, aux;

	while (count < this->countEdges)
	{
		triplet = priorityQueque.top();
		priorityQueque.pop();
		tmp = get<1>(triplet);
		aux = get<2>(triplet);
		originVertex = cycle(tmp);
		destinyVertex = cycle(aux);
		if (destinyVertex != originVertex)
		{
			AE.insert(get<1>(triplet), get<2>(triplet), get<0>(triplet));
			total = total + get<0>(triplet);
			BSTNode<string>* node = graph.searchNode(destinyVertex);
			BSTNode<string>* tmpNode = graph.searchNode(originVertex);
			tmpNode->setParent(node->getParent());
		}
		count++;
	}
}

template<class T>
inline void Graph<T>::contractEdge(const string& source, const string& destiny)
{
	// Contraer la arista en el grafo.
	graph.deleteData(source);
	graph.deleteData(destiny);

	string mergedVertex = source + "&" + destiny;
	graph.insert(mergedVertex, mergedVertex, 0, graph.getRoot());

	// Actualizar las aristas incidentes al nuevo vértice.
	//priorityQueque = priority_queue<tuple<int, string, string>, vector<tuple<int, string, string>>, greater<tuple<int, string, string>>>();
	BSTNode<string>* mergedNode = graph.searchNode(mergedVertex);
	BSTNode<string>* current = graph.getRoot();

	while (current != nullptr)
	{
		if (current->getData() != mergedVertex)
		{
			int weight;
			if (current->getAdjacencyList().deleteData(source))
				weight = graph.searchNode(source)->getAdjacencyList().getLast()->getWeight();
			else
				weight = graph.searchNode(destiny)->getAdjacencyList().getLast()->getWeight();
			graph.insert(current->getData(), mergedVertex, weight, graph.getRoot());
			priorityQueque.push(make_tuple(weight, current->getData(), mergedVertex));
		}
		current = graph.searchNodeHelper(graph.getRoot(), current->getParent());
	}
}

