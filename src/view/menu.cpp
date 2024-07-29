#include <iostream>
using namespace std;

int mostrarMenu() // funcion del menu principal y para evitar errores de datos ingresados.
{
    int decision;
    while (true)
    {
        system("clear");

        cout<<"//// Arbol Genealogico ////" <<endl<<endl;
        cout<<"1. Indicar la linea paterna o la linea materna."<<endl;
        cout<<"2. Indicar los hermanos de un nodo especifico"<<endl;
        cout<<"3. Indicar desde un nodo la linea materna o paterna."<<endl;
        cout<<"4. Indicar cantidad de hermanos o hijos"<<endl;
        cout<<"5. Eliminar del arbol uno o varios nodos en caso de divorcio"<<endl;
        cout<<"6. Mostrar el estado de cada miembro."<<endl;
        cout<<"7. Salir" <<endl<<endl;

        cout<<"Seleccione una opcion: "; cin>>decision;  

        cout<<endl;

        if(cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout<<"[ERROR] - Debes ingresar un numero entero."<<endl<<endl;
            system("pause");
        }
        else if(decision <= 0 || decision > 7)
        {
            cout<<"[ERROR] - Opcion Incorrecta, vuelva a intentarlo."<<endl<<endl;
            system("pause");
        }
        else
        {
            return decision;
        }
    }
}