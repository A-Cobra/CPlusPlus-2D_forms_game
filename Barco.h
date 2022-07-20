#pragma once
#include <iostream>
#include "Character.h"
class Barco : public Character
{
public:

	Barco(int ancho, int alto) : Character(ancho, alto) {
		dx = dy = 30;
		this->x = 0;
		this->y = 60;
	}
	~Barco() {}

	void mover(Graphics^ g) {
		int i = 0;

		switch (i)
		{
		case 0: //Horizontal
			if (x + ancho * 1.0 > g->VisibleClipBounds.Width || x < 0) dx *= -1;
			if (dx > 0) {
				indicey = 1;
			}
			else {
				indicey = 0;
			}
			x += dx;
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
		return Rectangle(x, y, ancho * 1.7, alto * 1.7);
	}
};
