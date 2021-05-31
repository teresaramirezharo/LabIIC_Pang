#include "DisparoEspecial.h"
#include "freeglut.h"


void DisparoEspecial::dibujaesp() {

	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(getradio(), 20, 20);
	glPopMatrix();
	glTranslatef(-posicion.x, -posicion.y, 0);
	glTranslatef(posicion.x - 0.5, posicion.y - 0.05, 0);
	estela();
	glTranslatef(1, 0, 0);
	estela();
}