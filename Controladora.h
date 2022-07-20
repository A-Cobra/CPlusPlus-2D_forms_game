#pragma once
#include <vector>
#include "Heroe.h"
#include "Enemigo.h"
#include "Botella.h"
#include "Bomba.h"
using namespace std;

class ControladoraNivel1
{
private:
	vector<Botella*>botellas;
	vector<Botella*>botellasTiradas;
	Heroe* heroe;
	vector<Enemigo*>enemigos;
	Botella* auxiliar;
	int contadorBotellasMovidas;
	int contadorIteraciones;
	int botellasRecogidas;
	int botellasPasadas;

	//Añadido de bombas
	vector<Bomba*>BombasTiradas;
	Bomba* bombaAuxiliar;

public:
	ControladoraNivel1(Bitmap^ bmpHeroe, Bitmap^ bmpEnemigo) {
		heroe = new Heroe(bmpHeroe->Width / 4, bmpHeroe->Height / 4);
		for (int i = 0; i < 5; i++) {
			enemigos.push_back(new Enemigo(bmpEnemigo->Width / 3, bmpEnemigo->Height / 4));
		}
		contadorBotellasMovidas = 0;
		botellasRecogidas = 0;
		botellasPasadas = 0;
	}
	~ControladoraNivel1() {}

	void agregaBotellas(Botella* b) {
		botellas.push_back(b);
	}

	int getBotellasPasadas() {
		return botellasPasadas;
	}

	void dibujarTodos(Graphics^ g, Bitmap^ bmpHeroe, Bitmap^ bmpEnemigo, Bitmap^ bmpBotella) {
		heroe->dibujar(g, bmpHeroe);

		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->dibujar(g, bmpEnemigo);
		}

	}
	void moverTodos(Graphics^ g, Bitmap^ bmpBotella) {
		for (int i = 0; i < enemigos.size(); i++)
		{
			enemigos[i]->mover(g);
		}

	}
	void moverBotellas(Graphics^ g, Bitmap^ bmpBotella) {
		for (int i = 0; i < botellasTiradas.size(); i++) {
			botellasTiradas[i]->mover(g, bmpBotella);
		}
	}

	void colision() {
		//verificacion
		//Para colision con enemigos
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (heroe->getRectangle().IntersectsWith(enemigos[i]->getRectangle())) {
				enemigos[i]->setVisible(false);
				heroe->setX(heroe->getSpawnX());
				heroe->setY(heroe->getSpawnY());
			}
		}

		//Para Colision con Botellas
		for (int i = 0; i < botellasTiradas.size(); i++)
		{
			if (heroe->getRectangle().IntersectsWith(botellasTiradas[i]->getRectangle())) {
				if (botellasTiradas[i]->getFinal() == false) {
					botellasTiradas[i]->setVisible(false);
					botellasRecogidas = botellasRecogidas + 5;
				}
			}
			if (botellasTiradas[i]->getFinal() == true) {
				botellasPasadas += 1;
				botellasTiradas[i]->setVisible(false);
			}
		}


			//Para Colision con bombas
		for (int i = 0; i < BombasTiradas.size(); i++)
		{
			if (heroe->getRectangle().IntersectsWith(BombasTiradas[i]->getRectangle())) {
				if (BombasTiradas[i]->getFinal() == false) {
					BombasTiradas[i]->setVisible(false);
					//botellasRecogidas += 1;
					heroe->quitarHp();
				}
			}
			if (BombasTiradas[i]->getFinal() == true) {
				//botellasPasadas += 1;
				BombasTiradas[i]->setVisible(false);
			}
		}

		//eliminacion
		//Para enemigos
		for (int i = 0; i < enemigos.size(); i++)
		{
			if (!enemigos[i]->getVisible()) {
				enemigos.erase(enemigos.begin() + i);
			}
		}

		//Para botellas
		for (int i = 0; i < botellasTiradas.size(); i++)
		{
			if (!botellasTiradas[i]->getVisible()) {
				botellasTiradas.erase(botellasTiradas.begin() + i);
			}
		}

		//Para Bombas
		for (int i = 0; i < BombasTiradas.size(); i++)
		{
			if (!BombasTiradas[i]->getVisible()) {
				BombasTiradas.erase(BombasTiradas.begin() + i);
			}
		}
	}
	void todosTiranBasura(Graphics^ g, Bitmap^ bmpBotella) {
		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigos[i]->getDireccion() == 3) {
				auxiliar = enemigos[i]->tirarBasura(g, bmpBotella, botellasTiradas);
				botellasTiradas.push_back(auxiliar);
				enemigos[i]->incrementarIteracion();
			}
		}
	}

	Enemigo* getEnemigo(int j) {
		return enemigos[j];
	}
	Heroe* getHeroe() {
		return heroe;
	}
	int getNumeroEnemigos() {
		return enemigos.size();
	}
	int getNumeroBotellasTiradas() {
		return botellasTiradas.size();
	}
	int getNumeroIteraciones() {
		return contadorIteraciones;
	}
	int getBotellasRecogidas() {
		return botellasRecogidas;
	}


	void moverBombas(Graphics^ g, Bitmap^ bmpBombas) {

		for (int i = 0; i < BombasTiradas.size(); i++) {
			BombasTiradas[i]->mover(g, bmpBombas);
		}
	}
	void todosTiranBombas(Graphics^ g, Bitmap^ bmpBombas) {
		for (int i = 0; i < enemigos.size(); i++) {
			if (enemigos[i]->getDireccion() == 3) {
				bombaAuxiliar = enemigos[i]->tirarBombas(g, bmpBombas, BombasTiradas);
				BombasTiradas.push_back(bombaAuxiliar);
				enemigos[i]->incrementarIteracionBombas();
			}
		}
	}
};