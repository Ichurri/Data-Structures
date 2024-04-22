#include <iostream>
template <class T>
class Node
{
private:
    T data;
    Node<T>* next;
    Node<T>* previous; 

public:
    Node(T data, Node<T>* next, Node<T>* previous);
    ~Node();
    T getData();
    Node<T>* getNext();
    Node<T>* getPrevious();
    void createNext(T data);
    void setData(T data);
    void setNext(Node<T>* next);
    void setPrevious(Node<T>* previous); 
};

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous)
{
    this->data = data;
    this->next = next;
    this->previous = previous;
}

template <class T>
Node<T>::~Node()
{
}

template <class T>
T Node<T>::getData()
{
    return data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template <class T>
Node<T>* Node<T>::getPrevious()
{
    return previous;
}

template <class T>
void Node<T>::createNext(T data)
{
    next = new Node<T>(data);
    next->previous = this; 
}

template <class T>
void Node<T>::setData(T data)
{
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next)
{
    this->next = next;
}

template <class T>
void Node<T>::setPrevious(Node<T>* previous)
{
    this->previous = previous;
}
