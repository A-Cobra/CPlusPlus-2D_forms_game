#pragma once
#include "Character.h"

class Botella : public Character {
private:
	int direction;
	bool end;

public:
	Botella(int ancho, int alto) : Character(ancho, alto) {
		end = false;
		dx = 7 + rand() % 15;
		dy = 0;
	}

	~Botella() {}

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
		Rectangle zoom = Rectangle(x, y, ancho * 0.12, alto * 0.12);
		g->DrawImage(bmp, zoom, seccionUsar, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.12, alto * 0.12);
	}
	bool getFinal() { return end; }
};