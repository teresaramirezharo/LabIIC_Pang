#include "Bonus.h"
#include"freeglut.h"
#include <stdlib.h>

Bonus::Bonus(){
	Vector2D p(0, 0);
	posicion = p;
	Vector2D v(0, 0);
	velocidad = v;
	Vector2D a(0, 9.81);
	aceleracion = a;
	lado = 0.5;
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio 
	glutSolidCube(lado);
	glPopMatrix();
}
//void Bonus::mueve(float t)
//{
//	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
//	velocidad = velocidad + aceleracion * t;
//}
//void Bonus::setposicion(float px, float py)
//{
//	posicion.x = px;
//	posicion.y = py;
//}