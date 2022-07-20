#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Controladora.h"

using namespace System;
using namespace std;

class File1
{
private:

	ofstream Escribir;
	ifstream Leer;
	ControladoraNivel1* co;

public:
	File1(ControladoraNivel1* control) {
		co = control;
		leerData();
	}
	~File1() {}

	void leerData() {
		Leer.open("Nivel1.txt", ios::in);
		if (Leer.fail()) {
			Leer.close();
			Escribir.open("Nivel1.txt", ios::out); //crear archivo
			Escribir << "Puntaje: " << co->getBotellasRecogidas() << endl;
			Escribir << "Vidas Restantes: " << co->getHeroe()->getHp() << endl;
			Escribir << "Botellas Pasadas: " << co->getBotellasPasadas() << endl;
			Escribir.close();
		}
		Leer.open("Nivel1.txt", ios::in);
	}
};