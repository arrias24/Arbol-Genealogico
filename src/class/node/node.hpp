#include <iostream>
using namespace std;

template <class T>

class Node{
    private:
        T data;
        Node<T>* next = NULL;
    public:
        Node(T data, Node<T>* next);    
        T getData();
        void setData(T data);
        Node<T>* getNextNode();
        void setNextNode(Node<T>* next);
        void print();
};