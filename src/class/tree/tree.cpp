#include "./tree.hpp"
#include <iostream>
using namespace std;

template<class T>
bool Tree<T>::isEmpty() {
    return root == nullptr;
}

template <class T>
void Tree<T>::insert(T data) {
    if (root == nullptr) {
        root = new NodeTree<T>(data);
    } 
    else 
    {
        root = insert(root, data);
    }
}

template<class T>
NodeTree<T>* Tree<T>::insert(NodeTree<T>* node, T data) 
{
    if (node == NULL) 
    {
        return new NodeTree<T>(data, NULL, NULL);
    }

    NodeTree<T>* current = node;

    while (current != NULL) 
    {
        if (data.padre == current->getData().id) 
        {
            if (current->getChildren(0) == NULL) 
            {
                current->setChildren(current->getChildren(0),insert(NULL, data));
                break;
            } 
            else 
            {
                current = current->getChildren(0);
            }
        } 
        else if (data.madre == current->getData().id) 
        {
            if (current->getChildren(1) == NULL)
            {
                current->setChildren(insert(NULL, data),current->getChildren(1));
                break;
            } 
            else 
            {
                current = current->getChildren(1);
            }
        } 
        else 
        {
            if (current->getChildren(0) != NULL)
            {
                current = current->getChildren(0);
            } 
            else if (current->getChildren(1) != NULL) 
            {
                current = current->getChildren(1);
            } 
            else 
            {
                current->setChildren(insert(NULL, data), current->getChildren(0));
                break;
            }
        }
    }

    return node;
}

template <class T>
void Tree<T>::postOrden(NodeTree<T>* node) {
    if (node == nullptr) return;
    postOrden(node->getChildren(0)); // Izquierda
    postOrden(node->getChildren(1)); // Derecha
    node->print(); // Nodo
}

template <class T>
void Tree<T>::print(int orden) {
    switch (orden) {
        case 0:
            postOrden(root);
            break;
        case 1:
            inOrden(root);
            break;
        default:
            preOrden(root);
            break;
    }
}

template<class T>
void Tree<T>::inOrden(NodeTree<T>* node) {
    if (node == nullptr) return;
    inOrden(node->getChildren(0));
    node->print();
    inOrden(node->getChildren(1));
}

template<class T>
void Tree<T>::preOrden(NodeTree<T>* node) {
    if (node == nullptr) return;
    node->print();
    preOrden(node->getChildren(0));
    preOrden(node->getChildren(1));
}

template<class T>
NodeTree<T>* Tree<T>::getRoot() {
    return root;
}

