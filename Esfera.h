#pragma once
#include "Vector2D.h"
class Esfera
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Esfera();
	void dibuja();
	void mueve(float t);
	void setcolor(unsigned char r, unsigned char v, unsigned char a);
	void setpos(float x, float y);
	void setradio(float r);
};

