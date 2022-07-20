#pragma once
#include "Heroe2.h"
#include "Enemigo2.h"
#include "Barco.h"
#include "Basura2.h"
#include <vector>

using namespace std;

class ControladoraNivel2 {
private:
	Heroe2* heroe;
	Barco* barco;
	vector<Basura2*> basuras;
	vector<Enemigo2*> enemigos;
	int contadorbasurarecogida;

public:
	ControladoraNivel2(Bitmap^ bmpHeroe2, Bitmap^ bmpEnemigo2, Bitmap^ bmpBarco) {
		barco = new Barco(bmpBarco->Width / 3, bmpBarco->Height / 2);
		heroe = new Heroe2(bmpHeroe2->Width / 4, bmpHeroe2->Height / 4);
		for (int i = 0; i < 7; i++) {
			enemigos.push_back(new Enemigo2(bmpEnemigo2->Width / 4, bmpEnemigo2->Height / 2));
		}
		contadorbasurarecogida = 0;
	}

	~ControladoraNivel2() {}

	void agregaBasura(Basura2* b) {
		basuras.push_back(b);
	}

	int getBasuraPasada() {
		int cont = 0;
		for (int i = 0; i < basuras.size(); i++) {
			if (basuras[i]->getLand()) {
				cont++;
			}
		}

		return cont;
	}

	void dibujarTodos(Graphics^ g, Bitmap^ bmpHeroe2, Bitmap^ bmpEnemigo2, Bitmap^ bmpBarco, Bitmap^ bmpBasura2) {
		barco->dibujar(g, bmpBarco);
		heroe->dibujar(g, bmpHeroe2);
		for each (Basura2 * b in basuras) {
			b->dibujar(g, bmpBasura2);
		}
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->dibujar(g, bmpEnemigo2);
		}
	}

	void moverTodos(Graphics^ g) {
		barco->mover(g);
		for each (Basura2 * b in basuras) {
			b->mover(g);
		}
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->mover(g);
		}
	}

	void colision() {
		//Verificacion
		for (int i = 0; i < basuras.size(); i++)
		{
			if (heroe->getRectangle().IntersectsWith(basuras[i]->getRectangle())) {
				basuras[i]->setVisible(false);
				contadorbasurarecogida = 5 + contadorbasurarecogida;
			}
		}
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (heroe->getRectangle().IntersectsWith(enemigos[i]->getRectangle())) {
				enemigos[i]->setVisible(false);
				heroe->quitarHp();
				heroe->setX(heroe->getSpawnX());
				heroe->setY(heroe->getSpawnY());
			}
		}

		//Eliminacion
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (!enemigos[i]->getVisible()) {
				enemigos.erase(enemigos.begin() + i);
			}
		}
		for (int i = 0; i < basuras.size(); i++)
		{
			if (!basuras[i]->getVisible()) {
				basuras.erase(basuras.begin() + i);
			}
		}
	}

	Heroe2* getHeroe2() { return heroe; }
	int getBasuraRecogida() {
		return contadorbasurarecogida;
	}
};