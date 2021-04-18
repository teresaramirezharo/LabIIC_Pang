#include "Caja.h"
#include "freeglut.h"

Caja::Caja() {
	suelo.setvalores(0.0f, 105.0f, 0.0f,-10,0,10,0);
	techo.setvalores(0.0f, 105.0f, 0.0f,-10, 15, 10, 15);
	pared_dcha.setvalores(0.0f, 255.0f, 100.0f, -10, 0, -10, 15);
	pared_izq.setvalores(0.0f, 255.0f,100.0f, 10, 0, 10, 15);
}
void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
}
