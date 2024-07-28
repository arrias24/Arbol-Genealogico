#include<iostream>
#include "./nodeTree.hpp"
using namespace std;

template <class T>
NodeTree<T>::NodeTree(T data, NodeTree<T>* left, NodeTree<T>* right) {
    this->data = data;
    this->left = left;
    this->right = right;
}

template <class T>
NodeTree<T>::~NodeTree() {
    // Aquí podrías agregar código para eliminar nodos hijos si fuera necesario
}

template <class T>
NodeTree<T>* NodeTree<T>::getChildren(int child) {
    if (child == 0) return this->left;
    if (child == 1) return this->right;
    return NULL;
}

template <class T>
void NodeTree<T>::setData(T data) {
    this->data = data;
}

template <class T>
T NodeTree<T>::getData() {
    return this->data;
}

template <class T>
void NodeTree<T>::setChildren(NodeTree<T>* left, NodeTree<T>* right) {
    this->left = left;
    this->right = right;
}

template <class T>
void NodeTree<T>::print() {
    cout << "Cedula: " << this->data.id << "." << endl;
    cout << "Nombre: " << this->data.nombre << "." << endl;
    cout << "Apellido: " << this->data.apellido << "." << endl;
    cout << "Genero: " << this->data.genero << "." << endl;
    cout << "Edad: " << this->data.edad << "." << endl;
    cout << "Fecha de nacimiento: " << this->data.fecha_nacimiento << "." << endl;
    cout << "Fecha de muerte: " << this->data.fecha_muerte << "." << endl;
    cout << "Padre: " << this->data.padre << "." << endl;
    cout << "Madre: " << this->data.madre << "." << endl;
    cout << "Cantidad de hermanos: " << this->data.numero_hermanos << "." << endl << endl;
}

