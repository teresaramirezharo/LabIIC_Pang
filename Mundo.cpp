#include "Mundo.h"
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
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	esf.dibuja();
	caj.dibuja();
	dis.dibuja();
	bon.dibuja();
	per.dibuja();
	pla.dibuja();
	dis.estela();
	//dibujo del suelo
	/*glDisable(GL_LIGHTING);
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
	dis.mueve(0.025f);
	bon.mueve(0.025f);
	per.mueve(0.025f);
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=10;
	z_ojo=25;
		//x_ojo = 0;
		//y_ojo = 7.5;
		//z_ojo = 30;
		esf.setvalores(255, 0, 255, 1.5f, 2, 4);
		bon.setvalores(5.0f, 5.0f);
		dis.setvalores(-5.0f, 0.0f);
		pla.setvalores(255, 255, 255, -5.0f, 9.0f, 5.0f, 9.0f);
		
}

void Mundo::tecla(unsigned char key)
{

}
