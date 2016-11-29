#pragma once
#include "C_Seleccionable.h"
#include "SFML\Graphics.hpp"

class C_Figura : public C_Seleccionable
{
protected:
	bool Seleccionado;
	long ID;
	string _type;
	sf::Color _colorRelleno;
	sf::Color _colorLinea;
	sf::Vector2f _posicion;
public:
	void setType(string type);
	string getType();
	void setID(long id);
	long getID();
	virtual bool setPosicion(sf::Vector2f posicion) = 0;
	virtual sf::Vector2f getPosicion();
	virtual void setColorRelleno(sf::Color) = 0;
	virtual sf::Color getColorRelleno();
	virtual void setColorLinea(sf::Color) = 0;
	virtual sf::Color getColorLinea();
	virtual void setSize(sf::Vector2f size) = 0;
	virtual ~C_Figura();
};

bool HitTestTTriangle(sf::Vector2f v0, sf::Vector2f v1,sf::Vector2f v2, sf::Vector2f point);