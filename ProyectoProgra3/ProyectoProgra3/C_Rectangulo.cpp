#include "stdafx.h"
#include "C_Rectangulo.h"
#include <iostream>


int C_Rectangulo::GetCLSID()
{
	return 0;
}

void C_Rectangulo::Guardar(ofstream & out)
{
}

void C_Rectangulo::Cargar(ifstream & in)
{
}

void C_Rectangulo::Inicializar()
{
}

C_Rectangulo::C_Rectangulo()
{
	//_base1 = base1;
	//_alt1 = alt1;

	//RectangleShape(float base1, float alt1);

	//sf::RectangleShape rectangulo (sf::Vector2f(5, 5));

	sf::RectangleShape rectangulo;
	rectangulo.setSize(sf::Vector2f(100, 50));
	rectangulo.setPosition(10, 20);
}

void C_Rectangulo::setColorRelleno(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		_shape[i].color = color;
	}
}

void C_Rectangulo::setColorLinea(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		_linea[i].color = color;
	}
}

bool C_Rectangulo::setPosicion(sf::Vector2f vector)
{
	rectangulo.setPosition(100, 200);

	return false;
}

bool C_Rectangulo::HitTest(sf::Vector2i point)
{
	sf::Vector2f v1 = rectangulo.getPosition();
	sf::Vector2f v2 = rectangulo.getPosition() + rectangulo.getSize();
	if (point.x >= rectangulo.getPosition().x && point.x <= rectangulo.getPosition().x + rectangulo.getSize().x && point.y >= rectangulo.getPosition().y && point.y <= rectangulo.getPosition().y + rectangulo.getSize().y)
	{
		cout << "allahuakbar";
		return true;
	}
		
	return false;
}

//C_Rectangulo::C_Rectangulo()
//{
//}


C_Rectangulo::~C_Rectangulo()
{
}
