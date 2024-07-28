#include <iostream>
#include "./node.hpp"
using namespace std;

template <class T>
Node<T>::Node(T data, Node<T>* next){
    this->data = data;
    if(next != NULL){
        this->next = next;
    }
}

template <class T>
T Node<T>::getData(){
    return this->data;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
Node<T>* Node<T>::getNextNode(){
    return this->next;
}

template <class T>
void Node<T>::setNextNode(Node<T>* next){
    if(next!=NULL)
    {
        this->next=next;
    }
}

template <class T>
void Node<T>::print(){
    cout << "Cedula: " << this->data.id << "." << endl;
    cout << "Nombre: " << this->data.nombre << "." << endl;
    cout << "Apellido: " << this->data.apellido << "." << endl;
    cout << "Genero: " << this->data.genero << "." << endl;
    cout << "Edad: " << this->data.edad << "." << endl;
    cout << "Fecha de nacimiento: " << this->data.fecha_nacimiento << "." << endl;
    cout << "Fecha de muerte: " << this->data.fecha_muerte << "." << endl;
    cout << "Padre: " << this->data.padre << "." << endl;
    cout << "Madre: " << this->data.madre << "." << endl<<endl;
}