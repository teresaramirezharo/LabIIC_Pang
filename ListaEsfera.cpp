#include "ListaEsfera.h"

ListaEsfera::ListaEsfera()
{
	numero = 0;
	for (int i = 0; i < MAX_ESFERAS; i++)
		lista[i] = 0;
}
bool ListaEsfera::agregar(Esfera* e)
{
	if (numero < MAX_ESFERAS )//&& lista[numero]==0 comprueba poder hacer mas esferas y que se creen en un espacio vacio
		lista[numero++] = e;// último puesto sin rellenar 
	else
		return false; // capacidad máxima alcanzada 
	return true;
}
void ListaEsfera::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}
void ListaEsfera::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

void ListaEsfera::rebote(Caja ca)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), ca);
}

void ListaEsfera::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}
void ListaEsfera::rebote()
{
	for (int i = 0; i < numero-1; i++)
	{
		for (int j = i+1; j < numero; j++)
		{
			Interaccion::rebote(*(lista[i]), *(lista[j]));
		}
	}
}
void ListaEsfera::destruirContenido()
{
	for (int i = 0; i < numero; i++) // destrucción de esferas contenidas 
		delete lista[i];
	numero = 0; // inicializa lista 
}
void ListaEsfera::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
}
void ListaEsfera::eliminar(Esfera* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
Esfera* ListaEsfera::colision(Persona& p)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), p))
			return lista[i];
	}
	return nullptr; //no hay colisión 
}
Esfera* ListaEsfera::operator [](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima 
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera 
		i = 0;
	return lista[i];
}