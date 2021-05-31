#include "Caja.h"
#include "freeglut.h"
#include "ETSIDI.h"

Caja::Caja() {
	
	suelo.setposicion(-10, 0, 10, 0);
	suelo.setcolor(0.0f, 105.0f, 0.0f);

	techo.setposicion(-10, 15, 10, 15);
	techo.setcolor(0.0f, 105.0f, 0.0f);

	pared_dcha.setposicion(-10, 0, -10, 15);
	pared_dcha.setcolor(0.0f, 255.0f, 100.0f);

	pared_izq.setposicion(10, 0, 10, 15);
	pared_izq.setcolor(0.0f, 255.0f, 100.0f);

}
void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();

	//dibujo del fondo 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0,1); glVertex2f(-10,0); 
	glTexCoord2d(1,1); glVertex2f(10,0); 
	glTexCoord2d(1,0); glVertex2f(10,15); 
	glTexCoord2d(0,0); glVertex2f(-10,15); 
	glEnd(); 
	glEnable(GL_LIGHTING); 
	glDisable(GL_TEXTURE_2D); 

}
