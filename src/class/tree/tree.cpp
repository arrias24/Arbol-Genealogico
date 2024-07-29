#include "./tree.hpp"
#include <functional>
#include <iostream>
#include "tree.hpp"

using namespace std;

template<class T>
bool Tree<T>::isEmpty() 
{
    return root == NULL;
}

template <class T>
void Tree<T>::insert(T data) 
{
    if (root == NULL) 
    {
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
void Tree<T>::postOrden(NodeTree<T>* node) 
{
    if (node == NULL) return;
    postOrden(node->getChildren(0));
    postOrden(node->getChildren(1));
    node->print();

}

template <class T>
void Tree<T>::print(int orden) 
{
    switch (orden) {
        case 0:
            postOrden(root);
            break;
        default:
            postOrden(root);
            break;
    }
}

template<class T>
NodeTree<T>* Tree<T>::getRoot() 
{
    return root;
}

template <class T>
NodeTree<T>* Tree<T>::findByName(string nombre, string apellido) 
{
    return findByNameHelper(root, nombre, apellido);
}

template <class T>
NodeTree<T> *Tree<T>::findByNameHelper(NodeTree<T> *node, string nombre, string apellido)
{
    if (node == NULL) 
    {
        return NULL;
    }

    T data = node->getData();

    if (data.nombre == nombre && data.apellido == apellido) 
    {
        return node;
    }

    NodeTree<T>* foundNode = findByNameHelper(node->getChildren(0), nombre, apellido);

    if (foundNode != NULL) 
    {
        return foundNode;
    }

    return findByNameHelper(node->getChildren(1), nombre, apellido);
}

template <class T>
NodeTree<T>* Tree<T>::findById(int id)
{
    return findByIdHelper(root, id);
}

template <class T>
NodeTree<T> *Tree<T>::findByIdHelper(NodeTree<T> *node, int id)
{
    if (node == NULL)
    {
        return NULL;
    }

    T data = node->getData();

    if (data.id == id)
    {
        return node;
    }

    NodeTree<T>* foundNode = findByIdHelper(node->getChildren(0), id);

    if (foundNode != NULL)
    {
        return foundNode;
    }

    return findByIdHelper(node->getChildren(1), id);
}

template <class T>
string Tree<T>::findSiblings(string nombre, string apellido, Tree<Persona> &arbol)
{
    NodeTree<Persona>* personaNode = arbol.findByName(nombre, apellido); // Buscar la persona en el árbol
    if (personaNode == NULL) 
    {
        cout << "Persona no encontrada." << endl;
        return "resultado";
    }

    Persona persona = personaNode->getData();

    
    if (persona.numero_hermanos != 0)  // Imprimir hermanos
    {
        cout << "Hermanos de " << persona.nombre << " " << persona.apellido << ":" << endl << endl;
        Node<Hermano>* current = persona.hermanos.head;
        while (current != NULL) 
        {
            Hermano hermano = current->getData();
            if (hermano.edad > persona.edad) 
            {
                cout << "Hermano mayor -> " << hermano.nombre << " " << hermano.apellido << endl;
            } 
            else if (hermano.edad < persona.edad) 
            {
                cout << "Hermano menor -> " << hermano.nombre << " " << hermano.apellido << endl;
            } 
            else 
            {
                cout << "Hermano -> " << hermano.nombre << " " << hermano.apellido << endl;
            }

            cout<<"Cedula: " << hermano.id << endl;
            cout<<"Genero: " << hermano.genero << endl;
            cout<<"Edad: " << hermano.edad << endl;
            cout<<"Estado: " << hermano.estado << endl;
            cout<<"Fecha de nacimiento: " << hermano.fecha_nacimiento << endl;

            if (hermano.fecha_muerte != "00/00/0000")
            {
                cout << "Fecha de muerte: " << hermano.fecha_muerte << endl;
            }

            cout << endl;

            current = current->getNextNode();
        }
    } 
    else 
    {
        cout<< "No tiene hermanos." << endl;
    }
    return "resultado";
}

template <class T>
void Tree<T>::findLineage(string nombre, string apellido, Tree<Persona> &arbol, bool isMaternal)
{
    NodeTree<Persona>* personaNode = arbol.findByName(nombre, apellido); // Buscar la persona en el árbol
    if (personaNode == NULL) 
    {
        cout << "Persona no encontrada." << endl;
        return;
    }

    Persona persona = personaNode->getData();

    cout << "Linea " << (isMaternal ? "materna" : "paterna") << " de " << persona.nombre << " " << persona.apellido << ":" << endl << endl;

    
    int count = 0;
    while (personaNode != NULL)  // Recorrer la línea materna o paterna
    {
        Persona currentPersona = personaNode->getData();

        if (count > 0)
        {
            cout << currentPersona.nombre << " " << currentPersona.apellido << endl;
            cout << "Cedula: " << currentPersona.id << endl;
            cout << "Genero: " << currentPersona.genero << endl;
            cout << "Edad: " << currentPersona.edad << endl;
            cout << "Estado: " << currentPersona.estado << endl;
            cout << "Fecha de nacimiento: " << currentPersona.fecha_nacimiento << endl;
            if (currentPersona.fecha_muerte != "00/00/0000") cout << "Fecha de muerte: " << currentPersona.fecha_muerte << endl;
            cout << endl;
        }

        if ((personaNode = arbol.findById(currentPersona.madre)) == NULL) 
        { 
           break;
        }

        switch (count)
        {
        case 0:
            cout << "- Padres: " << endl  << endl;
            break;
        case 1:
            cout << "- Abuelos: " << endl  << endl;
            break;
        case 2:
            cout << "- Bisabuelos: " << endl  << endl;
            break;
        case 3:
            cout << "- Tatarabuelos: " << endl  << endl;
            break;
        default:
            break;
        }

        
        if (isMaternal) // Moverse al siguiente ancestro en la línea seleccionada
        {
            if (count >= 0)
            {
                NodeTree<Persona>* parejaNode = arbol.findById(currentPersona.padre);
                if (parejaNode != NULL) 
                {
                    Persona pareja = parejaNode->getData();
                    cout << pareja.nombre << " " << pareja.apellido << endl;
                    cout << "Cedula: " << pareja.id << endl;
                    cout << "Genero: " << pareja.genero << endl;
                    cout << "Edad: " << pareja.edad << endl;
                    cout << "Estado: " << pareja.estado << endl;
                    cout << "Fecha de nacimiento: " << pareja.fecha_nacimiento << endl;
                    if (pareja.fecha_muerte != "00/00/0000") cout << "Fecha de muerte: " << pareja.fecha_muerte << endl;
                }
            }
        } 
        else 
        {
            personaNode = arbol.findById(currentPersona.padre);
            if (count >= 0)
            {
                NodeTree<Persona>* parejaNode = arbol.findById(currentPersona.madre);
                if (parejaNode != NULL) {
                    Persona pareja = parejaNode->getData();
                    cout << pareja.nombre << " " << pareja.apellido << endl;
                    cout << "Cedula: " << pareja.id << endl;
                    cout << "Genero: " << pareja.genero << endl;
                    cout << "Edad: " << pareja.edad << endl;
                    cout << "Estado: " << pareja.estado << endl;
                    cout << "Fecha de nacimiento: " << pareja.fecha_nacimiento << endl;
                    if (pareja.fecha_muerte != "00/00/0000") cout << "Fecha de muerte: " << pareja.fecha_muerte << endl;
                }
            }
        }
        cout << endl;
        count++;
    }
}

void countBrothersChildren(Tree<Persona> &arbol, const string &nombre, const string &apellido, bool contarHermanos) 
{
    NodeTree<Persona>* personaNode = arbol.findByName(nombre, apellido);
    if (personaNode == NULL) 
    {
        cout << "Persona no encontrada." << endl;
        return;
    }

    Persona persona = personaNode->getData();
    int count = 0;

    if (contarHermanos) 
    {
        count = persona.numero_hermanos;  // Contar hermanos
    } 
    else 
    {
        Persona hijo;
        int hermanos;

        for (NodeTree<Persona>* node = arbol.getRoot(); node != NULL; node = node->getLeft())  // Contar hijos
        {
            hijo = node->getData();
            if (hijo.madre == persona.id || hijo.padre == persona.id) 
            {
                count++;
                hermanos = hijo.numero_hermanos;
            }
        }
        count += hermanos;
    }
    cout << "Cantidad de " << (contarHermanos ? "hermanos" : "hijos") << " de " << persona.nombre << " " << persona.apellido << ": " << count << endl;
}



template <class T>
void Tree<T>::printFamilyStatus(NodeTree<T>* node) 
{

    if (node == NULL) {
        return;
    }

    printFamilyStatus(node->getChildren(0));

    T data = node->getData();
    cout<<endl;
    cout<<"Nombre: "<<data.nombre<<endl;
    cout<<"Apellido: "<<data.apellido<<endl;
    cout<<"Estado: " <<data.estado<<endl;
    if (data.estado == "Muerto") 
    {
        cout<<"Fecha de fallecimiento: "<<data.fecha_muerte<<endl<<endl;
    }

    if (!data.hermanos.isEmpty())
    {
        cout<<endl<<"Estado de sus hermanos:"<<endl;
        Node<Hermano>* current = data.hermanos.head;
        while (current != NULL) 
        {
            Hermano hermano = current->getData();
            cout<<hermano.nombre<<" "<<hermano.apellido<<" ("<<hermano.estado<<")"<<endl;
            if (hermano.estado == "muerto") 
            {
                cout<<"Fecha de fallecimiento: "<<hermano.fecha_muerte<<endl;
            }
            current = current->getNextNode();
        }
    }

    printFamilyStatus(node->getChildren(1));
}