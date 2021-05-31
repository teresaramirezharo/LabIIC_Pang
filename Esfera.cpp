#include "Esfera.h"
#include "ColorRGB.h"
#include "freeglut.h"

Esfera::Esfera(){
	Vector2D p(0, 0);
	posicion = p;
	Vector2D v(0, 0);
	velocidad = v;
	Vector2D a(0, -9.81f);
	aceleracion = a;
	color= 255;
	radio = 0.01;
}

Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
	color.set(255,255,100);
	aceleracion.y = -9.8;

}

void Esfera::setcolor(Byte r, Byte v, Byte a) {
	color.set(r,v,a);
}

void Esfera::setradio(float r) {
	radio = r;
}

//void Esfera::setposicion(Vector2D p) {
//	posicion = p;
//}
//
//void Esfera::setvelocidad(Vector2D v) {
//	velocidad = v;
//}

//Vector2D Esfera::getposicion()
//{
//	Vector2D p = posicion;
//	return p;
//}

float Esfera::getradio() {
	return radio;
}
//Vector2D Esfera::getvelocidad()
//{
//	Vector2D v = velocidad;
//	return v;
//}

void Esfera::dibuja()
{
	glColor3ub(color.r,color.g,color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

//void Esfera::mueve(float t)
//{
//	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t); 
//	velocidad=velocidad+aceleracion*t;
//}

float Esfera::distancia(Vector2D punto1, Vector2D punto2)
{
	Vector2D u = punto2 - punto1;
	float distancia = u.modulo();

	return distancia;
}