#include "ObjetoMovil.h"


void ObjetoMovil::mueve(float t){
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
void ObjetoMovil::setposicion(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}
void ObjetoMovil::setvelocidad(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
void ObjetoMovil::setaceleracion(float ax, float ay)
{
	aceleracion.x = ax;
	aceleracion.y = ay;
}

