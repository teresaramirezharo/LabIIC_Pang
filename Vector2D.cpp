#include "Vector2D.h"
#include "math.h"

Vector2D::Vector2D() {
	x = y = 0.0f;
}

float Vector2D::modulo()
{
	float resultado;
	return resultado = sqrt((x * x)+(y * y));
}
float Vector2D::argumento()
{
	float resultado;
	return resultado = atan(x / y);
}
Vector2D Vector2D::unitario()
{
	Vector2D resultado;
	resultado.x = x / modulo();
	resultado.y = y / modulo();
	return resultado;
}

Vector2D Vector2D::operator+(Vector2D op)
{
	Vector2D resultado;
	resultado.x = x + op.x;
	resultado.y = y + op.y;
	return resultado;
}
Vector2D Vector2D::operator-(Vector2D op)
{
	Vector2D resultado;
	resultado.x = x - op.x;
	resultado.y = y - op.y;
	return resultado;
}
float Vector2D::operator *(Vector2D op)
{
	float resultado;
	resultado = (x * op.x) + (y * op.y);
	return resultado;
}
Vector2D Vector2D::operator *(float n)
{
	Vector2D resultado;
	resultado.x = x * n;
	resultado.y = y * n;
	return resultado;
}
