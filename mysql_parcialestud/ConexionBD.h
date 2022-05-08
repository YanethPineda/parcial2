#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD
{
private: MYSQL* conectar;
public :
	void abrirconexion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "usr_estudiantes", "Empres@123", "db_estudiantes", 3306, NULL, 0);

	}
	MYSQL* getConectar() {
		return conectar;
	}
	void cerrarconexion() {
		mysql_close(conectar);
	}

};

