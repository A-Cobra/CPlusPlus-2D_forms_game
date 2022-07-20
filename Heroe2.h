#pragma once
#include "Character.h"

class Heroe2 : public Character
{
private:
	int hp;
	int spawnX, spawnY;
	int x, y;
public:
	Heroe2(int ancho, int alto) : Character(ancho, alto) {
		this->hp = 5;
		dx = dy = 15;
		x = 0;
		y = 400;
		spawnX = x;
		spawnY = y;
	}
	~Heroe2() {}

	void mover(Graphics^ g, char i) {
		switch (i)
		{
		case 'A'://A
			if (x > 0) {
				x -= dx;
				indicey = 1;
			}
			break;

		case 'D'://D
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				indicey = 0;
			}
			break;

		case 'W'://W
			if (y > 190) {
				y -= dy;
				indicey = 2;
			}
			break;

		case 'S'://S
			if (y + alto * 1.0 < 500) {
				y += dy;
				indicey = 3;
			}
			break;
		}
		indicex++;
		if (indicex > 3)
		{
			indicex = 0;
		}
	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle seccionUsar = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		//Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, this->getRectangle(), seccionUsar, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}
	int getSpawnX() { return spawnX; }
	int getSpawnY() { return spawnY; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getHp() { return hp; }
	void quitarHp() { hp--; }
};
