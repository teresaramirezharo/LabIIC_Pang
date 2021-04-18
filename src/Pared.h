#pragma once
#include "Vector2D.h"
class Pared
{
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared();
	void setvalores(unsigned char r, unsigned char v, unsigned char a, float x1, float y1, float x2, float y2);
	void dibuja();
};

