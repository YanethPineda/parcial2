#pragma once
#include <iostream>
using namespace std;
class Persona
{
protected: string nombres, apellidos, direccion, telefono,genero, email, fecha_nacimiento;


protected:
	Persona() {
	}
	Persona(string nom, string ape, string direc, string tel, string gen, string ema, string fn) {
		nombres = nom;
		apellidos = ape;
		direccion = direc;
		telefono = tel;
		genero = gen;
		email = ema;
		fecha_nacimiento = fn;
	}
};

