#pragma once
#include "Vector2D.h"
#include "ETSIDI.h"
#include "ObjetoMovil.h"
using ETSIDI::SpriteSequence;

class Persona :public ObjetoMovil
{
private:
	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	float altura;
	/*Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;*/
	
	
public:
	Persona();
	void dibuja();
	void setVel(float vx, float vy);
	/*void mueve(float t);
	Vector2D getposicion();
	void setposicion(float px, float py);*/
	float getaltura();
	friend class Interaccion;
};

