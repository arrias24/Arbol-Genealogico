//LIBRERIAS

#include <iostream>
#include <fstream>
#include <string>

//PROTOTIPOS

#include "../src/model/structures.h"
#include "../src/class/tree/tree.cpp"
#include "../src/controller/fileOperations.cpp"
#include "./view/menu.cpp"
#include "./view/operations.cpp"

using namespace std;

int main()
{
    //ABRIMOS LOS ARCHIVOS Y LOS GUARDAMOS DENTRO DE LAS ESTRUCTURAS

    ifstream file_family, file_brothers;

    openFile(file_family, "../assets/dataTree.csv");
    openFile(file_brothers, "../assets/dataBrothers.csv");

    string header_family; getline(file_family, header_family);
    string header_brothers; getline(file_brothers, header_brothers);

    Persona personas[11]; Hermano hermanos[8];
    int num_personas, num_hermanos;

    saveDataPerson(file_family,personas, num_personas);
    saveDataBrother(file_brothers,hermanos, num_hermanos);
    insertBrothers(personas,hermanos,num_personas,num_hermanos);

    //CREAMOS EL ARBOL Y GUARDAMOS LOS DATOS

    Tree <Persona> tree;

    for (int i = 0; i < num_personas; i++)
    {
        tree.insert(personas[i]);
    }

    //MENU

    system("clear");
    int opcion;
    do 
    {
        opcion = mostrarMenu();

        if(opcion)

        switch (opcion) {
            case 1:
                mostrarFamilia(tree); // Indicar la linea paterna o la linea materna desde la raiz.
                break;
            case 2:
                mostrarHermanos(tree); // Indicar los hermanos de un nodo especifico dentro del arbol.
                break;
            case 3:
                mostrarLineaFamiliar(tree); // Indicar desde un nodo la linea materna o paterna.
                break;
            case 4:
                mostrarNumeroDeFamiliares(tree); // Indicar cantidad de hermanos o hijos.
                break;
            case 5:
                // Eliminar del arbol uno o varios nodos en caso de divorcio.
                break;
            case 6:
                mostrarEstadoFamilia(tree); // Mostrar el estado de cada miembro incluyendo hermanos.
                break;
            case 7: 
                system("clear");
                cout<<"FIN DEL PROGRAMA."<<endl<<endl; // Fin del programa.
                break;
            default:
                cout <<endl<<"Opcion no valida, intente de nuevo."<<endl; // Opcion por defecto.
                limpiarPantalla();
        }
    } while (opcion != 7);

    return 0;
}