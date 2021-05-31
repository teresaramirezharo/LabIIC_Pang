#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Bonus :public ObjetoMovil
{
private:
	float lado;
	/*Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;*/
public:
	Bonus();
	void dibuja();
	//void mueve(float t);
	//void setposicion(float px, float py);
};

