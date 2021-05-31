#include "Disparo.h"
#include "freeglut.h"

Disparo::Disparo() : origen(0,0){
	radio = 0.25f;
	Vector2D p(0, 0);
	posicion = p;
	Vector2D v(0, 0);
	velocidad = v;
	Vector2D a(0, 9.8);
	aceleracion = a;
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
//void Disparo::mueve(float t)
//{
//	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
//	velocidad = velocidad + aceleracion * t;
//}
//void Disparo::setposicion(Vector2D p)
//{
//	posicion = p;
//}
//Vector2D Disparo::getposicion()
//{
//	Vector2D p = posicion;
//	return p;
//}
//void Disparo::setvelocidad(float vx, float vy)
//{
//	velocidad.x = vx;
//	velocidad.y = vy;
//}
//void Disparo::setaceleracion(float ax, float ay)
//{
//	aceleracion.x = ax;
//	aceleracion.y = ay;
//}
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