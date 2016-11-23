#pragma once
#include "C_Seleccionable.h"
#include "SFML\Graphics.hpp"

class C_Figura : public C_Seleccionable
{
protected:
	bool Seleccionado;
	long ID;
	sf::Color _colorRelleno;
	sf::Color _colorLinea;
	sf::Vector2f _posicion;
public:
	virtual bool setPosicion(sf::Vector2f posicion) = 0;
	virtual sf::Vector2f getPosicion();
	virtual void setColorRelleno(sf::Color) = 0;
	virtual sf::Color getColorRelleno();
	virtual void setColorLinea(sf::Color) = 0;
	virtual sf::Color getColorLinea();
	virtual ~C_Figura();
};

bool HitTestTTriangle(sf::Vector2f v0, sf::Vector2f v1,sf::Vector2f v2, sf::Vector2f point);