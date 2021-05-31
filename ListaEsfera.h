#pragma once
#include "Esfera.h"
#include "Caja.h"
#include "Persona.h"
#include "Interaccion.h"

#define MAX_ESFERAS 100 

class ListaEsfera{
private:
	Esfera* lista[MAX_ESFERAS];
	int numero;

public:
	ListaEsfera();
	//virtual ~ListaEsferas() {}
	bool agregar(Esfera* e);
	void dibuja();
	void mueve(float t);
	void rebote(Caja ca);
	void rebote(Pared p);
	void rebote();
	void destruirContenido();
	void eliminar(int index);
	void eliminar(Esfera* e);
	Esfera* colision(Persona& p);
	Esfera* operator [](int i);
	int getNumero() { return numero; };
};

