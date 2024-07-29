#include <iostream>
#include <string>
#include <cstdlib>

#include "../class/tree/tree.hpp"
#include "../model/fileOperations.h"

using namespace std;

void limpiarPantalla() // funcion que permite limpiar la consola.
{
    cout << endl << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    if (cin) 
    {
        system("clear");
    }
}

void mostrarFamilia(Tree<Persona> &arbol) // REQUISITO 1 - Indicar la linea paterna o la linea materna desde la raiz.
{
    system("clear");

    int opcion;
    cout<<"Seleccione la linea que desea ver:"<< endl<<endl;
    cout<<"1. Linea materna"<<endl;
    cout<<"2. Linea paterna"<<endl<<endl;
    cout<<"Seleccione una opcion: ";cin>>opcion;

    cout<<endl;

    if (opcion == 1) 
    {
        system("clear");
        arbol.findLineage("Marco", "Mavarez", arbol, true);
    } 
    else if (opcion == 2) 
    {
        system("clear");
        arbol.findLineage("Marco", "Mavarez", arbol, false);
    } 
    else 
    {
        cout<<"Opcion no valida."<<endl;
    }

    limpiarPantalla();
}

void mostrarHermanos(Tree<Persona>& tree) // REQUISITO 2 - Indicar los hermanos de un nodo especifico dentro del arbol.
{
    system("clear");

    string nombre, apellido;
    cout<<"Ingrese el nombre de la persona: ";cin>>nombre;
    cout<<"Ingrese el apellido de la persona: ";cin>>apellido;
    
    cout<<endl;

    string siblings = tree.findSiblings(nombre, apellido, tree);

    limpiarPantalla();
}

void mostrarLineaFamiliar(Tree<Persona> &arbol)  // REQUISITO 3 - Indicar desde un nodo la linea materna o paterna.
{
    system("clear");

    string nombre, apellido;
    cout<<"Ingrese el nombre de la persona: ";cin>>nombre;
    cout<<"Ingrese el apellido de la persona: ";cin>>apellido;
    cout << endl;

    int opcion;
    cout<<"Seleccione la linea que desea ver:"<<endl<<endl;
    cout<<"1. Linea materna"<<endl;
    cout<<"2. Linea paterna"<<endl<<endl;
    cout<<"Seleccione una opcion: ";cin>>opcion; 

    cout<<endl;

    if (opcion == 1) 
    {
        arbol.findLineage(nombre, apellido, arbol, true);
    } 
    else if (opcion == 2) 
    {
        arbol.findLineage(nombre, apellido, arbol, false);
    } 
    else 
    {
        cout << "Opción no válida." << endl;
    }

    limpiarPantalla();
}

void mostrarNumeroDeFamiliares(Tree<Persona> &arbol) // REQUISITO 4 - Indicar cantidad de hermanos o hijos.
{
    system("clear");
    
    string nombre, apellido;
    cout<<"Ingrese el nombre de la persona: ";cin>>nombre;
    cout<<"Ingrese el apellido de la persona: ";cin>>apellido;
    
    cout << endl;

    int opcion;
    cout<<"Seleccione la linea que desea ver:"<<endl<<endl;
    cout<<"1. Cantidad de hermanos"<<endl<<endl;

    if(nombre != "Marco")
    {
        cout << "2. Cantidad de hijos" <<endl<<endl;
    }

    cout<<"Seleccione una opcion: ";cin>>opcion; 
    
    cout<<endl;

    if (opcion == 1) 
    {
        countBrothersChildren(arbol, nombre, apellido, true);
    } 
    else if (opcion == 2 && nombre != "Marco") 
    {
        countBrothersChildren(arbol, nombre, apellido, false);
    } 
    else 
    {
        cout << "Opcion no valida." << endl;
    }

    limpiarPantalla();
}

void mostrarEstadoFamilia(Tree<Persona> &arbol) // REQUISITO 6 - Mostrar el estado de cada miembro incluyendo hermanos.
{   
    system("clear");

    cout<<"ESTADO DE LA FAMILIA"<<endl;

    arbol.printFamilyStatus(arbol.getRoot());

    cout<<endl;

    system("pause");
}


