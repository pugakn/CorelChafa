#include "stdafx.h"
#include "C_Linea.h"


int C_Linea::GetCLSID()
{
	return 0;
}

void C_Linea::Guardar(ofstream & out)
{
}

void C_Linea::Cargar(ifstream & in)
{
}

void C_Linea::setColorRelleno(sf::Color color)
{
}

void C_Linea::setColorLinea(sf::Color color)
{
}

bool C_Linea::setPosicion(sf::Vector2f vector)
{
	return false;
}

bool C_Linea::HitTest(sf::Vector2i point)
{
	return false;
}

C_Linea::C_Linea(sf::Vector2f a, sf::Vector2f b)
{
	_a = a;
	_b = b;
	_shape = sf::VertexArray(sf::Lines, 2);
	_shape[0].position = a;
	_shape[1].position = b;
}

C_Linea::C_Linea()
{
}


C_Linea::~C_Linea()
{
}
