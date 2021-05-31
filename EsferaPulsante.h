#pragma once
#include "Esfera.h"
class EsferaPulsante : public Esfera
{
protected:
	float radio_max=1;
	float radio_min=0.1f;
	float pulso=0.5f;
public:
	void mueve(float t);
};

