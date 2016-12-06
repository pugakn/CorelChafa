#include "stdafx.h"
#include "C_Rectangulo.h"
#include <iostream>
#include "C_Documento.h"


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

void C_Rectangulo::setSize(sf::Vector2f size)
{
	if (!Bloqueado && Visible) {
		_size = size;
		_rectangulo.setSize(size);
		C_Documento::Instance()->Notify();
	}
}

C_Rectangulo::C_Rectangulo(float base, float altura)
{
	_base1 = base;
	_alt1 = altura;
	//RectangleShape(float base1, float alt1);
	//sf::RectangleShape rectangulo (sf::Vector2f(5, 5));
	_rectangulo = sf::RectangleShape(sf::Vector2f(base, altura));
	//_rectangulo.setSize(sf::Vector2f(base, altura));
	//_rectangulo.setPosition(10, 20);
	_size = sf::Vector2f(base,altura);
}

C_Rectangulo::C_Rectangulo()
{
}

void C_Rectangulo::setColorRelleno(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorRelleno = color;
		_rectangulo.setFillColor(color);
		C_Documento::Instance()->Notify();
	}
}

void C_Rectangulo::setColorLinea(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorLinea = color;
		_rectangulo.setOutlineThickness(1);
		_rectangulo.setOutlineColor(color);
		C_Documento::Instance()->Notify();
	}
}

bool C_Rectangulo::setPosicion(sf::Vector2f vector)
{
	if (!Bloqueado && Visible) {
		_posicion = vector;
		_rectangulo.setPosition(vector);
		C_Documento::Instance()->Notify();
		return true;
	}
	return false;
}

bool C_Rectangulo::HitTest(sf::Vector2i point)
{
	if (Visible) {
		sf::Vector2f v1 = _rectangulo.getPosition();
		sf::Vector2f v2 = _rectangulo.getPosition() + _rectangulo.getSize();
		if (point.x >= _rectangulo.getPosition().x && point.x <= _rectangulo.getPosition().x + _rectangulo.getSize().x && point.y >= _rectangulo.getPosition().y && point.y <= _rectangulo.getPosition().y + _rectangulo.getSize().y)
		{
			cout << "allahuakbar";
			return true;
		}
	}
	return false;
}

void C_Rectangulo::Dibujar(sf::RenderWindow & window)
{
	window.draw(_rectangulo);
}

//C_Rectangulo::C_Rectangulo()
//{
//}


C_Rectangulo::~C_Rectangulo()
{
}
