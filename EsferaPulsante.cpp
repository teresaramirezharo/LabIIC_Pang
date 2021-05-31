#pragma once
#include "EsferaPulsante.h"

void EsferaPulsante::mueve(float t)
{
	Esfera::mueve(t);
	if (radio > radio_max)
		pulso = -pulso;
	if (radio < radio_min)
		pulso = -pulso;
	radio += pulso * t;
	color.r = radio * 255;
	color.g = 255 - radio * 100;
	color.b = 100 + radio * 50;
}