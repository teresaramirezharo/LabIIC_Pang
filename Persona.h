#pragma once
#include "Vector2D.h"
class Persona
{
private:
	float altura;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
public:
	Persona();
	void dibuja();
	void setVel(float vx, float vy);
	void mueve(float t);
	Vector2D getposicion();
	void setposicion(float px, float py);
	friend class Interaccion;
};


