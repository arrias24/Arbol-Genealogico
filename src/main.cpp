//LIBRERIAS

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

//PROTOTIPOS

#include "../src/model/structures.h"
#include "../src/class/tree/tree.cpp"
#include "../src/controller/fileOperations.cpp"

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






    return 0;
}