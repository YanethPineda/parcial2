// mysql_parcialestud.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Estudiante.h"  
using namespace std;
int q_estado;

int main()
{
    string carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento;
    Estudiante c = Estudiante(nombres, apellidos, direccion, telefono, fecha_nacimiento, carnet, email, genero);

    cout << "Ingrese la opcion que desea ejecutar: 1. Crear   2. Leer   3. Actualizar   4. Eliminar --- Opcion:  ";
    int op = 0;
    cin >> op;


    switch (op)

    {
    case 1: cout << "crear";
        c.crear();
        break;
    case 2: cout << "leer";
        c.leer();
        break;
    case 3: cout << "actualizar";
        c.modificar();
        break;
    case 4: cout << "eliminar";
        c.eliminar();
        break;
    }

    return 0;

}
