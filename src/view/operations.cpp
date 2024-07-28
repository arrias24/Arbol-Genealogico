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