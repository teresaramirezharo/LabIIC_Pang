#include "Esfera.h"
#include "freeglut.h"

Esfera::Esfera() {
	verde = rojo = azul = 255;
	radio = 0.1;
	posicion = {};
	velocidad = {};
	aceleracion.x=0.0f;
	aceleracion.y = -9.81f;
}
void Esfera::setcolor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;

}
void Esfera::setradio(float r) {
	radio = r;
}
void Esfera::setpos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}
void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}
void Esfera::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}
