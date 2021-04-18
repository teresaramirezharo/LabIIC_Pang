#include "Persona.h"
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"


class Mundo
{
private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	
	Persona per;
	Caja caj;
	Disparo dis;
	Esfera esf;
	Bonus bon;
	Pared pla;
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
};
