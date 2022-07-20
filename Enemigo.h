#pragma once
#include <iostream>
#include "Character.h"
#include "Heroe.h"
#include "Botella.h"
#include "Bomba.h"
using namespace std;
#include <vector>
class Enemigo : public Character
{
private:
	int iContador;
	vector <Botella*> botellas;
	vector <Bomba*> bombas;
	Botella* molde;
	Bomba* moldeBomba;
	int contadorBombas;
public:

	Enemigo(int ancho, int alto) : Character(ancho, alto) {
		dx = dy = 15;
		this->x = 650;
		this->y = 510;
		iContador = 0;

		agregaBotellas();

		//Añadidos
		contadorBombas = 0;
		agregaBombas();
	}
	~Enemigo() {}

	void agregaBotellas() {
		//Rellenamos el vector de botellas
		for (int i = 0; i < 25; i++)
		{
			molde = new Botella(250, 250);
			botellas.push_back(molde);
		}
	}

	void mover(Graphics^ g) {
		int i = rand() % 4;
		direccion = i;
		switch (i)
		{
		case 0://A
			if (x > 250) {
				x -= dx;
				indicey = 3;
			}
			break;

		case 1://D
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				indicey = 1;
			}
			break;

		case 2://W
			if (y > 460) {
				y -= dy;
				indicey = 0;
			}
			break;

		case 3://S
			if (y + alto * 1.0 < 650) {
				y += dy;
				indicey = 2;
			}
			break;
		}
		indicex++;
		if (indicex > 2)
		{
			indicex = 0;
		}
	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle seccionUsar = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		g->DrawImage(bmp, this->getRectangle(), seccionUsar, GraphicsUnit::Pixel);
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho / 1.7, alto / 1.7);
	}

	Botella* tirarBasura(Graphics^ g, Bitmap^ bmpBotella, vector<Botella*>botellasTiradas) {
		if (iContador < 25) {
			botellas[iContador]->setX(x);
			botellas[iContador]->setY(y + 30);
			botellas[iContador]->dibujar(g, bmpBotella);
			return botellas[iContador];
		}
	}
	int get_i() {
		return iContador;
	}
	void incrementarIteracion() {
		iContador += 1;
	}

	//Agregado de Bombas
	void agregaBombas() {
		//Rellenamos el vector de botellas
		for (int i = 0; i < 5; i++)
		{
			moldeBomba = new Bomba(90, 90);
			bombas.push_back(moldeBomba);
		}
	}
	Bomba* tirarBombas(Graphics^ g, Bitmap^ bmpBomba, vector<Bomba*>bombasTiradas) {
		if (contadorBombas < 5) {
			bombas[contadorBombas]->setX(x);
			bombas[contadorBombas]->setY(y + 30);
			bombas[contadorBombas]->dibujar(g, bmpBomba);
			return bombas[contadorBombas];
		}
	}
	int getContadorBombas() {
		return contadorBombas;
	}
	void incrementarIteracionBombas() {
		contadorBombas += 1;
	}
};
