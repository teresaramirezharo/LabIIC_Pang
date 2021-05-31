#include "ListaDisparos.h"
#include "Interaccion.h"
#include "ObjetoMovil.h"
ListaDisparos::ListaDisparos()
{
	numero = 0;
	for (int i = 0; i < MAX_DISPAROS; i++)
		lista[i] = 0;

}

bool ListaDisparos::agregar(Disparo* d)
{
	if (numero < MAX_DISPAROS)
		lista[numero++] = d; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;

}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de disparos 
		delete lista[i];
	numero = 0; // inicializa lista
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);

}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaDisparos::colision(Pared p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), p) == true)
			lista[i]->setvelocidad(0, 0);
	}
}
void ListaDisparos::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), c) == true){
			Interaccion::rebote(*(lista[i]), c);
			lista[i]->setvelocidad(0, 0);
		}
	}
}

