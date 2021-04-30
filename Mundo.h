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
	Esfera esf, esf2;
	Bonus bon;
	Pared plat;
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
};
