#pragma once
#include "BST.h"
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <time.h>
#include <algorithm>

class Graph
{
private:
	BST<string> graph;
	int numNodes = 0;
	vector<string> nodes;
public:
	Graph();
	Graph(Graph& other);
	~Graph() {};
	void insert(string source, string destiny);
	void readFile(const string& fileName);
	void printGraph();
	void contract(string v1);
	void contract(string v1, string v2);
	string randomNodeSource();
	string randomNodeDestiny(List<string>* lista);

	BST<string>& tree() { return graph; }

	int& getNumNodes() { return numNodes; }

	void printAdjacencyList(string ciudad);
	void operator=(const Graph& g);
};



inline Graph::Graph()
{
	srand(time(NULL));
}

inline Graph::Graph(Graph& other)
{
	graph.root() = graph.copyBST(other.graph.p_root());
	numNodes = other.numNodes;
	nodes = other.nodes;
	srand(time(NULL));
}

void Graph::insert(string source, string destiny)
{
	graph.insert(source, destiny, graph.root());

	if (find(nodes.begin(), nodes.end(), source) == nodes.end())
	{
		nodes.push_back(source);
		numNodes++;
	}
}

inline void Graph::readFile(const string& fileName)
{
	ifstream f(fileName);
	string origin, aux;
	aux = "";
	while (!f.eof())
	{
		f >> origin;
		while (f >> aux)
		{
			if (aux == "-1")
				break;
			else
				this->insert(origin, aux);
		}
	}

}

inline void Graph::printGraph()
{
	graph.inOrder(graph.root());
}

inline void Graph::contract(string v1) {
	BSTNode<string>* nodoV1 = this->graph.buscar(v1, graph.root());
	if (!nodoV1 || nodoV1->list().isEmpty()) {
		return;
	}

	string v2 = randomNodeDestiny(&(nodoV1->list()));

	BSTNode<string>* nodoV2 = this->graph.buscar(v2, graph.root());

	if (!nodoV2 || nodoV2->list().isEmpty()) 
		return;

	nodoV1->list().deleteElement(v2);

	ListNode<string>* caminante = nodoV2->list().getFirst();
	while (caminante != nullptr)
	{
		string adyacente = caminante->getElement();
		if (adyacente != v1) {
			nodoV1->list().insertFirst(adyacente);
			BSTNode<string>* nodoAdyacente = this->graph.buscar(adyacente, graph.root());
			if (nodoAdyacente != nullptr) 
			{
				nodoAdyacente->list().insertFirst(v1);
				nodoAdyacente->list().deleteElement(v2);
			}
		}
		caminante = caminante->getNext();
	}

	nodoV2->list().deleteAll();

	this->graph.eliminar(v2, graph.root());
	numNodes--;
}

inline void Graph::contract(string v1, string v2)
{
	BSTNode<string>* nodoV1 = this->graph.buscar(v1, graph.root());
	BSTNode<string>* nodoV2 = this->graph.buscar(v2, graph.root());

	ListNode<string>* Ady = nodoV2->list().getFirst();
	while (Ady != nullptr)
	{
		BSTNode<string>* nodoAdy = this->graph.buscar(Ady->getElement(), graph.root());
		if (Ady->getElement() != v1)
		{
			nodoV1->list().insertLast(Ady->getElement());
			cout << "Insertando: " << v1 << " en " << nodoAdy->getElement() << endl;
			nodoAdy->list().insertFirst(v1);
			cout << "Lista de " << nodoAdy->getElement() << ": ";
			nodoAdy->list().show();
		}
		nodoAdy->list().deleteElement(v2);
		Ady = Ady->getNext();
	}
	nodoV2->list().deleteAll();
	graph.eliminar(v2, graph.root());
	numNodes--;
}

inline string Graph::randomNodeSource()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(0, numNodes - 1);
	int pos = distribucion(gen);
	return nodes[pos];
}

inline string Graph::randomNodeDestiny(List<string>* lista)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribucion(0, lista->getCant() - 1);

	int pos = distribucion(gen);
	string res;

	ListNode<string>* current = lista->getFirst();
	for (int i = 0; i < pos && current != nullptr; ++i) 
		current = current->getNext();

	if (current != nullptr) 
		res = current->getElement();

	for (int i = 0; i < nodes.size(); i++)
	{
		if (nodes[i] == res)
		{
			pos = i;
			break;
		}
	}

	nodes[pos] = nodes.back();
	nodes.pop_back();

	return res;
}

inline void Graph::printAdjacencyList(string ciudad)
{
	BSTNode<string>* node = graph.buscar(ciudad, graph.root());
	cout << "Ciudad: " << ciudad << endl;
	node->list().show();
}

inline void Graph::operator=(const Graph& g)
{
	graph = g.graph;
}

