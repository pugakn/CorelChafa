#include "stdafx.h"
#include "C_Figura.h"




sf::Vector2f C_Figura::getPosicion()
{
	return _posicion;
}

sf::Color C_Figura::getColorRelleno()
{
	return _colorRelleno;
}

sf::Color C_Figura::getColorLinea()
{
	return _colorLinea;
}

C_Figura::~C_Figura()
{
}
