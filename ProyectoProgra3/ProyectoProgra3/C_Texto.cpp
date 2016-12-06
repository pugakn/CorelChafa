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
	//for (int i = 0; i < 4; i++) {
	//	_shape[i].color = color;
	//}
	//trans
}

void C_Texto::setColorLinea(sf::Color color)
{
	/*_colorLinea = color;
	_text.setOutlineThickness(1);
	_text.setOutlineColor(color);*/
	for (int i = 0; i < 4; i++) {
		_linea[i].color = color;
	}
}

bool C_Texto::setPosicion(sf::Vector2f vector)
{
	//_posicion = vector;
	//_rectangulo.setPosition(vector);

	//	rectangulo.setPosition(_posicion.x, _posicion.y); //?
	return false;
}

bool C_Texto::HitTest(sf::Vector2i point)
{
	//sf::Vector2f v1 = rectangulo.getPosition();
	sf::Vector2f v2 = _rectangulo2.getPosition() + _rectangulo2.getSize(); //los _rectangulos no tenian el guion bajo pero daba error si no se los ponia
	if (point.x >= _rectangulo2.getPosition().x && point.x <= _rectangulo2.getPosition().x + _rectangulo2.getSize().x && point.y >= _rectangulo2.getPosition().y && point.y <= _rectangulo2.getPosition().y + _rectangulo2.getSize().y)
	{
		cout << "allahuakbar";
		return true;
	}
	return false;
}

void C_Texto::Dibujar(sf::RenderWindow & window)
{
	window.draw(_texto);
}

void C_Texto::Inicializar()
{
}

C_Texto::C_Texto(float base2, float altura2)
{

	_base2 = base2;
	_alt2 = altura2;
	//RectangleShape(float base1, float alt1);
	//sf::RectangleShape rectangulo (sf::Vector2f(5, 5));
	_rectangulo2 = sf::RectangleShape(sf::Vector2f(base2, altura2));
	//_rectangulo.setSize(sf::Vector2f(base, altura));
	//_rectangulo.setPosition(10, 20);
	_size = sf::Vector2f(base2, altura2);
	//sf::RectangleShape rectangulo;
	//rectangulo.setSize(sf::Vector2f(100, 50));
	//rectangulo.setPosition(10, 20);
	////sf::Text::getRect()
	//sf::String Text = "allahu akbar";

}


C_Texto::~C_Texto()
{
}
