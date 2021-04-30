#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() :posicion(0, 0), origen(0,0), velocidad(0, 0), aceleracion(0, 9.81f) {
	radio = 0.25f;
}
void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
	estela();
}
void Disparo::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}
void Disparo::setposicion(Vector2D p)
{
	posicion = p;
	origen.x = -5.0f;
	origen.y = 0.0f;
}
void Disparo::estela() {
	if (posicion.y>0.01){
		glColor3f(110.0f, 0.0f, 100.5f);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y-0.5f, 0);
		glutSolidTeapot(0.15f);
		glPopMatrix();
	}
	if (posicion.y >1.01) {
		glColor3f(110.0f, 1.0f, 0.0f);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y - 1.0f, 0);
		glutSolidTeapot(0.15f);
		glPopMatrix();
	}
	if (posicion.y > 1.51) {
		glColor3f(0.0f, 200.0f, 0.0f);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y - 1.5f, 0);
		glutSolidTeapot(0.15f);
		glPopMatrix();
	}
	if (posicion.y > 2.01) {
		glColor3f(200.0f, 200.0f, 200.0f);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y - 2.0f, 0);
		glutSolidTeapot(0.15f);
		glPopMatrix();
	}
	//estela original
	/*glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2d(origen.x, origen.y);
	glVertex2d(posicion.x, posicion.y);
	glEnd();*/



}
