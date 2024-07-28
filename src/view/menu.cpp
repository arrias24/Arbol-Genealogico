#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "//// Arbol Genealogico ////" << endl << endl;
    cout << "1. Indicar la linea paterna o la linea materna (Ambas opciones deben de estar disponibles)" << endl;
    cout << "2. Indicar los hermanos de un nodo especifico" << endl;
    cout << "3. Indicar desde un nodo la linea materna o paterna (ambas opciones deben de estar disponibles)" << endl;
    cout << "4. Indicar cantidad de hermanos o hijos" << endl;
    cout << "5. Eliminar del arbol uno o varios nodos en caso de divorcio" << endl;
    cout << "6. Mostrar el estado de cada miembro incluyendo hermanos (muerto, vivo, desaparecido), en caso de estar muerto indicar fecha de muerto" << endl;
    cout << "7. Salir" << endl << endl;
    cout << "Seleccione una opción: ";
}