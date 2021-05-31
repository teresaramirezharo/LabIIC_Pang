#pragma once
#include "Disparo.h"
class DisparoEspecial : public Disparo
{
	Vector2D velocidadesp = velocidad * 1.5;
	float radioesp = getradio() * 1.5;
public:
	void dibujaesp();
};

