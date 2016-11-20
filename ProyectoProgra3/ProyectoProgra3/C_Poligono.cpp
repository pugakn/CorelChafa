#include "stdafx.h"
#include "C_Poligono.h"


int C_Poligono::GetCLSID()
{
	return 0;
}

void C_Poligono::Guardar(ofstream & out)
{
}

void C_Poligono::Cargar(ifstream & in)
{
}

C_Poligono::C_Poligono()
{
}

C_Poligono::C_Poligono(std::size_t  lados, float radio)
{
	_shape = sf::CircleShape(radio, lados);
}


C_Poligono::~C_Poligono()
{
}

bool C_Poligono::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0) {
		_posicion = posicion;
		_shape.setPosition(posicion);
		return true;
	}
	return false;
}


bool C_Poligono::HitTest()
{
	return false;
}

void C_Poligono::setColorRelleno(sf::Color color)
{
	_colorRelleno = color;
	_shape.setFillColor(color);
}

void C_Poligono::setColorLinea(sf::Color color)
{
	_colorLinea = color;
	_shape.setOutlineColor(color);
}

