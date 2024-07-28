#ifndef TREE_HPP
#define TREE_HPP

#include "../nodeTree/nodeTree.cpp"

template<class T>
class Tree {
private:
    NodeTree<T>* root = NULL;
    NodeTree<T>* insert(NodeTree<T>* node, T data);

public:
    bool isEmpty();
    void insert(T data);
    void print(int orden);
    void postOrden(NodeTree<T>* node);
    void inOrden(NodeTree<T>* node);
    void preOrden(NodeTree<T>* node);
    NodeTree<T>* getRoot();

    void findBrothers(string);
};

#endif // TREE_HPP


