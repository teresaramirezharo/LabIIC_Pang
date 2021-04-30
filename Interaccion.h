#pragma once
#include "Persona.h"
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "Pared.h"

class Interaccion
{
public:
	static void rebote(Persona& p, Caja c);
	static bool rebote(Esfera& e, Pared p);
	static bool rebote(Esfera& e1, Esfera& e2);
	static void rebote(Esfera& e, Caja c);
};

