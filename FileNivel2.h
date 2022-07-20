#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Controladora2.h"

using namespace System;
using namespace std;

class File2
{
private:

	ofstream Escribir;
	ifstream Leer;
	ControladoraNivel2* co;
public:
	File2(ControladoraNivel2* control) {
		co = control;
		leerData();
	}
	~File2() {}

	void leerData() {
		Leer.open("Nivel2.txt", ios::in);
		if (Leer.fail()) {
			Leer.close();
			Escribir.open("Nivel2.txt", ios::out); //crear archivo
			Escribir << "Puntaje: " << co->getBasuraRecogida() << endl;
			Escribir << "Vidas Restantes: " << co->getHeroe2()->getHp() << endl;
			Escribir << "Botellas Pasadas: " << co->getBasuraPasada() << endl;
			Escribir.close();
		}
		Leer.open("Nivel2.txt", ios::in);
	}
};