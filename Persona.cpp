#include "Persona.h"
#include "freeglut.h"

Persona::Persona(){
	Vector2D p(0, 0);
	posicion = p;
	Vector2D v(0, 0);
	velocidad = v;
	Vector2D a(0, 0);
	aceleracion = a;
	altura = 1.8f;
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
	//altura = 1.8f;
}
void Persona::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y, 1);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20); 
	//gestion de direccion y animacion 
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();
}
void Persona::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
//void Persona::mueve(float t)
//{
//	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
//	velocidad = velocidad + aceleracion * t;
//	sprite.loop(); 
//}

//Vector2D Persona::getposicion()
//{
//	Vector2D p = posicion;
//	return p;
//}
//void Persona::setposicion(float px, float py) {
//	posicion.x = px;
//	posicion.y = py;
//}
float Persona::getaltura() {
	return altura;
}