#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>
#include "../class/list/list.cpp"
using namespace std;

struct Hermano
{
    int id;
    string nombre;
    string apellido;
    string genero;
    int edad;
    string fecha_nacimiento;
    string fecha_muerte;
    string estado;
    int padre;
    int madre;    
};

struct Persona
{
    int id;
    string nombre;
    string apellido;
    string genero;
    int edad;
    string fecha_nacimiento;
    string fecha_muerte;
    string estado;
    int padre;
    int madre;  
    List<Hermano> hermanos;
};

#endif