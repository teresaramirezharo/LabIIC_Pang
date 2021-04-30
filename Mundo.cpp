#include "Mundo.h"
#include"Interaccion.h"
#include "Persona.h"
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "freeglut.h"
#include <math.h>

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	esf.dibuja();
	esf2.dibuja();
	caj.dibuja();
	dis.dibuja();
	bon.dibuja();
	per.dibuja();
	plat.dibuja();

	//dibujo del suelo
/*	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);*/
	glEnd();
	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{
	esf.mueve(0.025f);
	esf2.mueve(0.025f);
	dis.mueve(0.025f);
	bon.mueve(0.025f);
	per.mueve(0.025f);
	Interaccion::rebote(per, caj);
	Interaccion::rebote(esf, caj);
	Interaccion::rebote(esf, plat);
	Interaccion::rebote(esf2, caj);
	Interaccion::rebote(esf2, plat);
	Interaccion::rebote(esf, esf2);
}

void Mundo::inicializa()
{
	Vector2D p(2, 4);
	Vector2D p2(-2, 4);
	Vector2D v(5, 15);
	Vector2D v2(-5, 15);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	esf.setcolor(255, 0, 255);
	esf.setradio(1.5f);
	esf.setposicion(p);
	esf.setvelocidad(v);
	esf2.setradio(2);
	esf2.setposicion(p2);
	esf2.setvelocidad(v2);
	bon.setposicion(5.0f, 5.0f);
	dis.setposicion(per.getposicion());
	plat.setposicion(-5.0f, 9.0f, 5.0f, 9.0f);
	
}

void Mundo::tecla(unsigned char key)
{
	
}
void Mundo::teclaEspecial(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		per.setVel(-5.0f, 0.0f);
		break;
	case GLUT_KEY_RIGHT:
		per.setVel(5.0f, 0.0f);
		break;
	}
}
