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
                mostrarFamilia(tree);
                break;
            case 2:
                mostrarHermanos(tree);
                break;
            case 3:
                mostrarLineaFamiliar(tree);
                break;
            case 4:
                mostrarNumeroDeFamiliares(tree);
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                system("clear");
                cout<<"FIN DEL PROGRAMA."<<endl<<endl;
                break;
            default:
                cout << endl << "Opcion no valida, intente de nuevo." << endl;
                limpiarPantalla();
        }
    } while (opcion != 7);

    return 0;
}