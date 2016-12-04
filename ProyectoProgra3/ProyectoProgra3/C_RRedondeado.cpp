#include "stdafx.h"
#include "C_RRedondeado.h"


int C_RRedondeado::GetCLSID()
{
	return 0;
}

void C_RRedondeado::Guardar(ofstream & out)
{
}

void C_RRedondeado::Cargar(ifstream & in)
{
}

C_RRedondeado::C_RRedondeado()
{
	sf::ConvexShape convex;
	convex.setPointCount(12);
	convex.setPoint(0,sf::Vector2f(0, 0));
	convex.setPoint(1, sf::Vector2f(150, 0));
	convex.setPoint(2, sf::Vector2f(150, 75));
	convex.setPoint(3, sf::Vector2f(0, 75));
	//convex.setPoint(4, sf::Vector2f(0, 0));

}


C_RRedondeado::~C_RRedondeado()
{
}
