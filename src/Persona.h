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
	void mueve(float t);
};

