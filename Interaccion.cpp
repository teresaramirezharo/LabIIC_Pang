#include "Interaccion.h"

void Interaccion::rebote(Persona& p, Caja c)
{	
	float xmax = c.suelo.getposicion_x2();
	float xmin = c.suelo.getposicion_x1();
	if (p.getposicion().x > xmax)p.setposicion(xmax, p.getposicion().y);
	if (p.getposicion().x < xmin)p.setposicion(xmin, p.getposicion().y);
}
void Interaccion::rebote(Disparo& d, Caja c)
{
	float xmax = c.suelo.getposicion_x2();
	float xmin = c.suelo.getposicion_x1();
	float ymax = c.techo.getposicion_y1();
	Vector2D limx1(xmax, d.getposicion().y);
	Vector2D limx2(xmin, d.getposicion().y);
	Vector2D limy(d.getposicion().x,ymax);
	if (d.getposicion().x > xmax)d.setposicion(limx1);
	if (d.getposicion().x < xmin)d.setposicion(limx2);
	if (d.getposicion().y > xmax)d.setposicion(limy);

}



bool Interaccion::rebote(Esfera& e, Pared p)
{

	Vector2D dir(0, 0);
	float dif = p.distancia(e.getposicion(), &dir) - e.getradio();
	if (dif <= 0.0f)
	{
		Vector2D v_inicial = e.getvelocidad();
		e.setvelocidad(v_inicial - dir * 2.0 * (v_inicial * dir));
		e.setposicion(e.getposicion() - dir * dif);
		return true;
	}
	return false;
}

void Interaccion::rebote(Esfera& e, Caja c) 
{
	rebote(e, c.suelo);
	rebote(e, c.techo);
	rebote(e, c.pared_dcha);
	rebote(e, c.pared_izq);

}
bool Interaccion::rebote(Esfera& e1, Esfera& e2)
{
	Vector2D dir(0,0);

	float dif = (e1.distancia(e1.getposicion(),e2.getposicion())) - (e1.getradio() + e2.getradio());
	if (dif <= 0.0f)
	{
		Vector2D v_inicial1 = e1.getvelocidad();
		Vector2D v_inicial2 = e2.getvelocidad();

		e1.setvelocidad((v_inicial1 * (e1.getradio() * e1.getradio() - e2.getradio() * e2.getradio()) + v_inicial2 * (e1.getradio() * e1.getradio() + e2.getradio() * e2.getradio())) * (1 / (e1.getradio() * e1.getradio() + e2.getradio() * e2.getradio())));
		e2.setvelocidad( v_inicial1 + e1.getvelocidad() - v_inicial2);

		return true;
	}

	return false;
}

bool Interaccion::colision(Esfera e, Persona p)
{
	Vector2D pos = p.getposicion(); //la posicion de la base del hombre
	pos.y += p.getaltura() / 2.0f; //posicion del centro 
	float distancia = (e.getposicion() - pos).modulo();
	if (distancia < e.getradio())
		return true;
	return false;
}
bool Interaccion::colision(Disparo d, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(d.getposicion(), &dir) - d.getradio();
	if (dif <= 0.05f)//Se coloca 0.05f porque con menos dá error
	{
		Vector2D aux = (d.getposicion() - dir * dif);
		d.setposicion(aux);
		d.setvelocidad(0.0f, 0.0f);
		d.setaceleracion(0.0f, 0.0f);
		return true;
	}
	return false;
	
}
bool Interaccion::colision(Disparo d, Caja c)
{
	if (colision(d, c.techo))
		return true;

	if (colision(d, c.pared_izq))
		return true;

	if (colision(d, c.pared_dcha))
		return true;

	return false;
}
