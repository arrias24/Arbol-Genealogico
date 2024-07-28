#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void limpiarPantalla() {
    cout << endl << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
    if (cin) {
        system("clear");
    }
}