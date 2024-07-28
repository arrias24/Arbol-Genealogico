#ifndef TREE_HPP
#define TREE_HPP

#include "../nodeTree/nodeTree.cpp"

template<class T>
class Tree {
private:
    NodeTree<T>* root = NULL;
    NodeTree<T>* insert(NodeTree<T>* node, T data);
    NodeTree<T>* findByNameHelper(NodeTree<T>* node, string nombre, string apellido);

public:
    bool isEmpty();
    void insert(T data);
    void print(int orden);
    void postOrden(NodeTree<T>* node);
    void inOrden(NodeTree<T>* node);
    void preOrden(NodeTree<T>* node);
    NodeTree<T>* getRoot();

    NodeTree<T>* findByName(string nombre, string apellido);
    string findSiblings(string nombre, string apellido, Tree<Persona>& arbol);
};

#endif


