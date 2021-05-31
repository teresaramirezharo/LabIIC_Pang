#pragma once
#include "ColorRGB.h"
#include "Esfera.h"
#include "Vector2D.h"
class Pared
{
private:
	ColorRGB color;
	Vector2D limite1;
	Vector2D limite2;
public:
	Pared();
	void setcolor(Byte r, Byte v, Byte a);
	void setposicion(float x1, float y1, float x2, float y2);
	float getposicion_x1();
	float getposicion_y1();
	float getposicion_x2();
	float getposicion_y2();
	void dibuja();
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;
};

