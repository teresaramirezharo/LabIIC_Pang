#include "Pared.h"
#include "freeglut.h"
Pared::Pared() {
	rojo =verde =azul = 255;
	limite1 = {};
	limite2 = {};
};

void Pared::setvalores(unsigned char r, unsigned char v, unsigned char a, float x1, float y1,float x2, float y2) {
	rojo = r;
	verde=v;
    azul=a;
	limite1.x =x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
void Pared::dibuja()
{
	glDisable(GL_LIGHTING);
	glColor3ub(rojo, verde, azul);
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y, 10);
	glVertex3d(limite2.x, limite2.y, 10);
	glVertex3d(limite2.x, limite2.y, -10);
	glVertex3d(limite1.x, limite1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

