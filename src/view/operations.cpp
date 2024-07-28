#include <iostream>
#include <string>
#include <cstdlib>

#include "../class/tree/tree.hpp"
#include "../model/fileOperations.h"

using namespace std;

void limpiarPantalla() {
    cout << endl << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    if (cin) {
        system("clear");
    }
}

void mostrarHermanos(Tree<Persona>& tree) {
    system("clear");

    string nombre, apellido;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;
    cout << "Ingrese el apellido de la persona: ";
    cin >> apellido;
    cout << endl;

    string siblings = tree.findSiblings(nombre, apellido, tree);

    limpiarPantalla();
}

void mostrarLineaFamiliar(Tree<Persona> &arbol) {
    system("clear");

    string nombre, apellido;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;
    cout << "Ingrese el apellido de la persona: ";
    cin >> apellido;
    cout << endl;
    int opcion;
    cout << "Seleccione la línea que desea ver:" << endl << endl;
    cout << "1. Línea materna" << endl;
    cout << "2. Línea paterna" << endl << endl;
    cout << "Seleccione una opción: ";

    cin >> opcion; cout << endl;

    if (opcion == 1) {
        arbol.findLineage(nombre, apellido, arbol, true);
    } else if (opcion == 2) {
        arbol.findLineage(nombre, apellido, arbol, false);
    } else {
        cout << "Opción no válida." << endl;
    }

    limpiarPantalla();
}

void mostrarNumeroDeFamiliares(Tree<Persona> &arbol) {
    system("clear");
    
    string nombre, apellido;
    cout << "Ingrese el nombre de la persona: ";
    cin >> nombre;
    cout << "Ingrese el apellido de la persona: ";
    cin >> apellido;
    cout << endl;
    int opcion;
    cout << "Seleccione la línea que desea ver:" << endl << endl;
    cout << "1. Cantidad de hermanos" << endl;
    cout << "2. Cantidad de hijos" << endl << endl;
    cout << "Seleccione una opción: ";

    cin >> opcion; cout << endl;

    if (opcion == 1) {
        countBrothersChildren(arbol, nombre, apellido, true);
    } else if (opcion == 2) {
        countBrothersChildren(arbol, nombre, apellido, false);
    } else {
        cout << "Opción no válida." << endl;
    }

    limpiarPantalla();
}