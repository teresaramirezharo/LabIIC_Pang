#include "Pared.h"
#include "ColorRGB.h"
#include "freeglut.h"
Pared::Pared():limite1(0,0),limite2(0,0) {
	color = 255;
};

void Pared::setcolor(Byte r, Byte v,Byte a) {
	color.set(r,v,a);
}
void Pared::setposicion(float x1, float y1, float x2, float y2) {
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}

float Pared::getposicion_x1()
{
	float px1;
	px1=limite1.x ;
	return px1;
}

float Pared::getposicion_y1()
{
	float py1;
	py1 =limite1.y;
	return py1;
}

float Pared::getposicion_x2()
{
	float px2;
	px2 =limite2.x;
	return px2;
}

float Pared::getposicion_y2()
{
	float py2;
	py2 =limite2.y;
	return py2;
}

void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(color.r,color.g,color.b);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir(0,0);
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector… 
		*direccion = dir.unitario();
	return distancia;
}

