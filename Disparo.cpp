#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() {
	radio = 0.25f;
	posicion = origen = {};
	velocidad = {};
	aceleracion.y=9.81f;
}
void Disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}
void Disparo::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
	estela();
}
void Disparo::setvalores(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
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

	/*estela original 
	//estela
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2d(origen.x,origen.y);
	glVertex2d(posicion.x, posicion.y);
	glEnd();*/


}
