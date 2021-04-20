#include "Caja.h"
#include "freeglut.h"

Caja::Caja() {
	suelo.setposicion(-10,0,10,0);
	suelo.setcolor(0.0f, 105.0f, 0.0f);
	
	techo.setposicion(-10, 15, 10, 15);
	techo.setcolor(0.0f, 105.0f, 0.0f);
	
	pared_dcha.setposicion(-10, 0, -10, 15);
	pared_dcha.setcolor(0.0f, 255.0f, 100.0f);
	
	pared_izq.setvalores( 10, 0, 10, 15);
	pared_izq.setcolor(0.0f, 255.0f,100.0f);
}
void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}
