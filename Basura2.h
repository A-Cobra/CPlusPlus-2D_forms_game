#pragma once
#include "Character.h"

class Basura2 : public Character {
private:
	bool land;

public:
	Basura2(int ancho, int alto) : Character(ancho, alto) {
		land = false;
		x = rand() % 800;
		y = 160;
		dx = dy = 8;
	}

	~Basura2() {}

	void mover(Graphics^ g) {
		if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
			y += dy;
			indicex++;
			if (indicex > 3)indicex = 0;
		}
		else {
			land = true;
		}
	}

	bool getLand() { return land; }
	void dibujar(Graphics^ g, Bitmap^ bmp) {
		Rectangle seccionUsar = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		//Rectangle zoom = Rectangle(x, y, ancho * 1.0, alto * 1.0);
		g->DrawImage(bmp, this->getRectangle(), seccionUsar, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};