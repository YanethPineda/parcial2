#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Estudiante :
    public Persona
{
private: string id, carnet;

public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string direc, string ema, string fn, string tel, string gen, string d, string car) : Persona(nom, ape, direc, ema, fn, tel, gen) {
		id = d;
		carnet = car;
	}

	void setId(string d) { id = d; }
	void setCarnet(string car) { carnet = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string direc) { direccion = direc; }
	void setTelefono(int tel) { telefono = tel; }
	void setGenero(int gen) { genero = gen; }
	void setEmail(string ema) { email = ema; }
	void setFecha_nacimiento(string fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getId() { return id; }
	string getCarnet() { return carnet; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getTelefono() { return telefono; }
	string getGenero() { return genero; }
	string getEmail() { return email; }
	string getFecha_nacimiento() { return fecha_nacimiento; }

	void crear() {
	
		int q_estado;
		ConexionBD cn = ConexionBD();
		cout << " Ingrese carnet: ";
		cin >> carnet;
		cout << "Ingrese nombres: ";
		cin >> nombres;
		cout << "Ingrese apellidos: ";
		cin >> apellidos;
		cout << "Ingrese direccion: ";
		cin >> direccion;
		cout << "Ingrese telefono: ";
		cin >> telefono;
		cout << "Ingrese genero: ";
		cin >> genero;
		cout << "Ingrese email: ";
		cin >> email;
		cout << "Ingrese fecha de nacimiento: ";
		cin >> fecha_nacimiento;

		cn.abrirconexion();
		if (cn.getConectar()) {
			string insert = "insert into estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) values('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "','" + genero + "','" + email + "','" + fecha_nacimiento + "')";
			const char* i = insert.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESO EXITOSO" << endl;
			}
			else
			{
				cout << "FALLO AL INGRESAR" << endl;
			}
		}
		else {
			cout << "ERROR DE CONEXION" << endl;
		}
		cn.cerrarconexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrirconexion();

		if (cn.getConectar()) {
			cout << "DATOS DEL ESTUDIANTE" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
				}
			}
			else {
				cout << "Error al Consultar..." << endl;
			}
			
		}
		else {
			cout << "Error al consultar..." << endl;
		}
		cn.cerrarconexion();
	}

	void modificar() {
		int q_esatdo;
		ConexionBD cn = ConexionBD();
		string id, carne, nombre, apellido, direccio, telefon, gener, emai, fecha_nacimient;
		cout << "Igrese el Id que desea modificar: ";
		cin >> id;
		cout << "Ingrese carnet: ";
		cin >> carnet;
		cout << "Ingrese nombres: ";
		cin >> nombres;
		cout << "Ingrese apellidos: ";
		cin >> apellidos;
		cout << "Ingrese direccion: ";
		cin >> direccion;
		cout << "Ingrese telefono: ";
		cin >> telefono;
		cout << "Ingrese genero: ";
		cin >> genero;
		cout << "Ingrese email: ";
		cin >> email;
		cout << "Ingrese fecha de nacimiento: ";
		cin >> fecha_nacimiento;

		cn.abrirconexion();
		if (cn.getConectar()) {
			string modificar = "UPDATE `db_estudiantes`.`estudiantes` SET `carnet` = '"+ carne + "' , `nombres` = '" + nombre + "' , `apellidos` = '" + apellido + "' , `direccion` =  '" + direccio + "' , `telefono` = '" + telefon + "' ,`genero`  = '" + gener + "' , `email`  = '" + emai + "' WHERE(`id_estudiantes` = '" + id + "')";
			const char* i = modificar.c_str();
			q_esatdo = mysql_query(cn.getConectar(), i);
			if (!q_esatdo) {
				cout << " Datos actualizados" << endl;
			}
		}
		else {
			cout << "Los datos no fueron actualizados" << endl;
		}
		cn.cerrarconexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		string id;
		cout << "Ingrese el di que desea eliminar: ";
		cin >> id;
		cn.abrirconexion();
		if(cn.getConectar()){
			string eliminar = "DELETE FROM estudiantes WHERE (id_estudiante= '" + id + "')";
			const char* i = eliminar.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "El dato ha sido eliminado" << endl;

			}
			else {
				cout << "ERROR AL ELIMINAR" << endl;
			}
			cn.cerrarconexion();
		}
	}

};

