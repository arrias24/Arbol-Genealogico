#include <iostream>
#include "../node/node.cpp"
using namespace std;

template <class T>
class List{
    private:
        Node<T>* head = NULL;
    public:
        void insert(T data);
        void insertFirst(Node<T>* node);
        bool isEmpty();
        void print();
        bool deleteOne(T data);
        void update(int n, T data);
};