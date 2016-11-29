#include "stdafx.h"
#include "C_Figura.h"
#include "VECTOR.h"




void C_Figura::setType(string type)
{
	_type = type;
}

string C_Figura::getType()
{
	return _type;
}

void C_Figura::setID(long id)
{
	ID = id;
}

long C_Figura::getID()
{
	return ID;
}

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

bool HitTestTTriangle(sf::Vector2f v0, sf::Vector2f v1, sf::Vector2f v2, sf::Vector2f point)
{
	sf::Vector2f u = v1 - v0;
	sf::Vector2f p = (sf::Vector2f)point - v0;
	sf::Vector3f c1 = Cross(u, p);

	u = v2 - v1;
	p = (sf::Vector2f)point - v1;
	sf::Vector3f c2 = Cross(u, p);

	u = v0 - v2;
	p = (sf::Vector2f)point - v2;
	sf::Vector3f c3 = Cross(u, p);
	return (((c1.z < 0) && (c2.z < 0) && (c3.z < 0)) || ((c1.z > 0) && (c2.z > 0) && (c3.z > 0)));
}
