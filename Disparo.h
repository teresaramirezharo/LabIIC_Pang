#pragma once
#include "ObjetoMovil.h"

class Disparo :public ObjetoMovil
{
private:
	float radio;
	/*Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;*/
	Vector2D origen;
public:
	Disparo();
	void dibuja();
	/*void mueve(float  t);
	void setposicion(Vector2D p);
	Vector2D getposicion();
	void setvelocidad(float vx, float vy);
	void setaceleracion(float ax, float ay);*/
	float getradio() {return radio;}
	void estela();
};

