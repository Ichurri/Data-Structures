#include <iostream>
template <class T>
class ListNode
{
private:
    T data;
    ListNode<T>* next;
    ListNode<T>* previous;
    int weight = 0;

public:
    ListNode(T data, ListNode<T>* next, ListNode<T>* previous) :data(data), next(next), previous(previous) {};
    ~ListNode() {};
    T getData();
    ListNode<T>* getNext();
    ListNode<T>* getPrevious();
    void createNext(const T& data);
    void setData(const T& data);
    void setNext(ListNode<T>* next);
    void setPrevious(ListNode<T>* previous);

    int getWeight();
    void setWeight(int weight);
};

template <class T>
T ListNode<T>::getData()
{
    return data;
}

template <class T>
ListNode<T>* ListNode<T>::getNext()
{
    return next;
}

template <class T>
ListNode<T>* ListNode<T>::getPrevious()
{
    return previous;
}

template<class T>
inline void ListNode<T>::createNext(const T& data)
{
    next = new ListNode<T>(data, nullptr, this);
}

template<class T>
inline void ListNode<T>::setData(const T& data)
{
    this->data = data;
}

template <class T>
void ListNode<T>::setNext(ListNode<T>* next)
{
    this->next = next;
}

template <class T>
void ListNode<T>::setPrevious(ListNode<T>* previous)
{
    this->previous = previous;
}

template<class T>
inline int ListNode<T>::getWeight()
{
    return weight;
}

template<class T>
inline void ListNode<T>::setWeight(int weight)
{
    this->weight = weight;
}
