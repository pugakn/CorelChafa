#include "stdafx.h"
#include "C_Texto.h"
#include <iostream>


int C_Texto::GetCLSID()
{
	return 0;
}

void C_Texto::Guardar(ofstream & out)
{
}

void C_Texto::Cargar(ifstream & in)
{
}

void C_Texto::setColorRelleno(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		_shape[i].color = color;
	}
}

void C_Texto::setColorLinea(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		_linea[i].color = color;
	}
}

bool C_Texto::setPosicion(sf::Vector2f vector)
{
	rectangulo.setPosition(100, 200);
	return false;
}

bool C_Texto::HitTest(sf::Vector2i point)
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

C_Texto::C_Texto()
{
	sf::RectangleShape text;
	sf::Text texto;
	text.setSize(sf::Vector2f(100, 50));
	//texto.setPosition = rectangulo.setPosition;

}


C_Texto::~C_Texto()
{
}
