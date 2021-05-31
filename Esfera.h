#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
class Esfera :public ObjetoMovil
{
protected:
	ColorRGB color;
	float radio;
	/*Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;*/
public:
	Esfera();
	Esfera(float rad, float x = 0.0f, float y = 0.0f,
		float vx = 0.0f, float vy = 0.0f);
	virtual ~Esfera() {};
	void dibuja();
	//void mueve(float t);
	void setcolor(Byte r, Byte v, Byte a);
	/*void setvelocidad(Vector2D v);
	void setposicion(Vector2D p);*/
	void setradio(float r);
	//Vector2D getposicion();
	float getradio();
	//Vector2D getvelocidad();
	float distancia(Vector2D punto1, Vector2D punto2);

	friend class Interaccion;
};

