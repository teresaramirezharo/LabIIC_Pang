#include "Mundo.h"
#include "freeglut.h"
#include <math.h>

void Mundo::inicializa()
{
	Vector2D p(-2, 4);
	Vector2D v(5, 15);
	x_ojo = 0;
	y_ojo = 7.5;
	z_ojo = 30;
	bon.setposicion(5.0f, 5.0f);
	dis.setposicion(per.getposicion());
	plat.setposicion(-5.0f, 9.0f, 5.0f, 9.0f);
	esferapulsante.setposicion(p);
	esferapulsante.setvelocidad(v);
	dispesp.setposicion(p*-0.5);
	dispesp.setvelocidad(0,v.y*0.5);
	for (int i = 0; i < 4; i++)
	{
		Esfera* aux = new Esfera(0.5 + i * 0.25, 1.5+i, 2.5 + i, i, i);
		esferas.agregar(aux);
	}

	for (int i = 0; i < esferas.getNumero(); i++){
		if ((esferas[i]->getradio()) > 1.5)
			esferas[i]->setcolor(0, 255, 0);
		else
			esferas[i]->setcolor(255, 255, 255);
	}

	Esfera* e1 = new Esfera(1, -7,10, 5, 15); // esfera1 
	e1->setcolor(200, 0, 0);
	esferas.agregar(e1); // esfera1 a la lista 
	Esfera* e2 = new Esfera(2, -2, 5, -5, 15); // esfera2 
	e2->setcolor(50, 0, 255);
	esferas.agregar(e2); //esfera2 a la lista 

}


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
	
	caj.dibuja();
	dis.dibuja();
	bon.dibuja();
	per.dibuja();
	plat.dibuja();
	esferas.dibuja();
	disparos.dibuja();
	esferapulsante.dibuja();
	dispesp.dibujaesp();
	//dibujo del suelo
/*	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);
	glEnd();*/

	glEnable(GL_LIGHTING);
}

void Mundo::mueve()
{
	per.mueve(0.025f);
	bon.mueve(0.025f);
	dis.mueve(0.025f);

	esferas.mueve(0.025f);
	esferas.rebote(caj);
	esferas.rebote(plat);
	esferas.rebote();
	
	Esfera* aux = esferas.colision(per);
	if (aux != 0)//si alguna esfera ha chocado 
	{
		esferas.eliminar(aux);
		ETSIDI::play("sonidos/impacto.wav"); //linea agregada 
	}

	disparos.mueve(0.025f);
	disparos.colision(caj);

	esferapulsante.mueve(0.025f);
	dispesp.mueve(0.025f);

	Interaccion::rebote(esferapulsante, plat);
	Interaccion::rebote(esferapulsante, caj);

	for (int i = 0; i < esferas.getNumero(); i++) {
		Interaccion::rebote(esferapulsante, *esferas[i]);
	};

	Interaccion::rebote(per, caj);
	Interaccion::rebote(dis, caj);
	Interaccion::rebote(dispesp, caj);
	
}

void Mundo::tecla(unsigned char key)
{
	switch (key) {
	case '1':
		esferas.agregar(new Esfera(0.5f, 2, 10,3,3));
		break;
	case '2':
		esferas.agregar(new Esfera(1.0f, 2, 8,5,5));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5f, 0, 10,5,5));
		break;
	case '4':
		esferas.agregar(new Esfera(2.0f, 0, 8,5,5));
		break;
	}
	switch (key) {
	case ' ':
	{
		Disparo* d = new Disparo();
		Vector2D pos = per.getposicion();
		d->setposicion(pos);
		disparos.agregar(d);
		if (disparos.agregar(d))
			per.setVel(0, 0);
		break;
	}
	}
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

Mundo::~Mundo()
{
	esferas.destruirContenido();
	disparos.destruirContenido();
}