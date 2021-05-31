#include "Persona.h"
#include "Bonus.h"
#include "Caja.h"
#include "Disparo.h"
#include "Esfera.h"
#include "ListaEsfera.h"
#include"Interaccion.h"
#include "ListaDisparos.h"
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"

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
	//Esfera esf2,esf3, esf4;
	Bonus bon;
	Pared plat;
	ListaEsfera esferas;
	ListaDisparos disparos;
	EsferaPulsante esferapulsante;
	DisparoEspecial dispesp;
public: 
	void tecla(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	void teclaEspecial(unsigned char key);
	virtual ~Mundo();
};
