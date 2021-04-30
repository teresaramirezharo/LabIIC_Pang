#include "Persona.h"
#include "freeglut.h"
Persona::Persona():posicion(0,0), velocidad(0,0), aceleracion(0,0) {
	altura = 1.8f;
}
void Persona::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(altura, 20, 20);
	glPopMatrix();
}
void Persona::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
void Persona::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

Vector2D Persona::getposicion()
{
	Vector2D p = posicion;
	return p;
}
void Persona::setposicion(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}
