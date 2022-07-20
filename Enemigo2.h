#pragma once
#include "Character.h"
#include "Heroe2.h"
class Enemigo2 : public Character
{
private:
	Heroe2* heroe;
public:

	Enemigo2(int ancho, int alto) : Character(ancho, alto) {
		dx = dy = 10;
		this->x = 0 + rand() % 1333;
		this->y = 130 + rand() % 300;
	}
	~Enemigo2() {}

	void mover(Graphics^ g) {
		int i = rand() % 2;

		switch (i)
		{
		case 0://A
			if (x > 0) {
				x -= dx;
				indicey = 1;
			}
			break;

		case 1://D
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				x += dx;
				indicey = 0;
			}
			break;
		case 2://Persigue
			if (x == heroe->getX()) {
				x += 0;
			}
			else if (x > heroe->getX()) {
				x -= dx;
				indicey = 1;
			}
			else if (x < heroe->getX()) {
				x += dx;
				indicey = 0;
			}

			if (y == heroe->getY()) {
				y += 0;
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
		g->DrawImage(bmp, this->getRectangle(), seccionUsar, GraphicsUnit::Pixel);
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.6, alto * 1.6);
	}
	int getX() { return x; }
	int getY() { return y; }
	int getIndiceY() { return indicey; }
};
