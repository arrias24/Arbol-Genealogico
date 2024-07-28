#include <iostream>
#include "../node/node.cpp"
using namespace std;

template <class T>
class List{
    private:
    
    public:
        Node<T>* head = NULL;
        void insert(T data);
        void insertFirst(Node<T>* node);
        bool isEmpty();
        void print();
};