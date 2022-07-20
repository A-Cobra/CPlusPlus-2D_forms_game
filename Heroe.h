#pragma once
#include "Character.h"

class Heroe : public Character
{
private:
	int hp;
	int spawnX, spawnY;
	int x, y;
public:
	Heroe(int ancho, int alto) : Character(ancho, alto) {
		this->hp = 5;
		dx = dy = 15;
		x = 0;
		y = 500;
		spawnX = x;
		spawnY = y;
	}
	~Heroe() {}

	void mover(Graphics^ g, char i) {
		switch (i)
		{
		case'S':
			if (x > 0) {
				x -= dx;
				indicey = 1;
			}
			break;
		case'W':
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				indicey = 2;
			}
			break;
		case'A':
			if (y > 460) {
				y -= dy;
				indicey = 2;
			}
			break;
		case'D':
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				y += dy;
				indicey = 2;
			}
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
