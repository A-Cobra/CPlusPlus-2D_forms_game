#pragma once
#include "character.h"

class Bomba : public Character {
private:
	int direction;
	bool end;

public:
	Bomba(int ancho, int alto) : Character(ancho, alto) {
		end = false;

		dx = 7 + rand() % 15;;
		dy = 0;

	}

	~Bomba() {}

	void mover(Graphics^ g, Bitmap^ bmp) {
		if (x - dx >= 0) {
			x -= dx;
		}
		else {
			end = true;
		}
		indicex++;
		if (indicex > 3) {
			indicex = 0;
		}
		dibujar(g, bmp);
	}
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle seccionUsar = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		g->DrawImage(bmp, this->getRectangle(), seccionUsar, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.5, alto * 0.5);
	}
	bool getFinal() { return end; }
};