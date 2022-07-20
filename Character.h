#pragma once
using namespace System::Drawing;
class Character
{
protected:
	int direccion;
	int ancho, alto;
	int dx, dy;
	int x;
	int y;
	int indicex, indicey;
	bool visible;
public:
	Character(int ancho, int alto) {
		this->ancho = ancho;
		this->alto = alto;
		indicex = indicey = 0;
		visible = true;
	}

	~Character() {}

	virtual void dibujar() {}
	virtual void mover() {}
	int getX() { return x; }
	int getY() { return y; }
	int getAlto() { return alto; }
	int getAncho() { return ancho; }

	int getDireccion() { return direccion; }
	int setDireccion(int direccion) { this->direccion = direccion; }

	void setVisible(bool v) { visible = v; }
	bool getVisible() { return visible; }
	int getIndiceY() { return indicey; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};
