#pragma once
#include "Vector2D.h"
class ObjetoMovil
{
public:
	void mueve(float t);
	void setvelocidad(Vector2D v) { velocidad = v; };
	void setposicion(Vector2D p) { posicion = p; };
	void setposicion(float px, float py);
	void setvelocidad(float vx, float vy);
	void setaceleracion(float ax, float ay);
	void setaceleracion(Vector2D a) { aceleracion = a; };
	Vector2D getposicion() { return posicion; };
	Vector2D getvelocidad() { return velocidad; };
	Vector2D getaceleracion() { return aceleracion; };

protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;
	
};

