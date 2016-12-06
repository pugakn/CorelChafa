#include "stdafx.h"
#include "C_Texto.h"
#include <iostream>
#include "C_Documento.h"


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
	if (!Bloqueado && Visible) {
		_colorRelleno = color;
		_texto.setFillColor(color);
		C_Documento::Instance()->Notify();
	}
}

void C_Texto::setColorLinea(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorLinea = color;
		_texto.setOutlineThickness(2);
		_texto.setOutlineColor(color);
		C_Documento::Instance()->Notify();
	}
}

bool C_Texto::setPosicion(sf::Vector2f vector)
{
	if (!Bloqueado && Visible) {
		_posicion = vector;
		_texto.setPosition(vector);
		C_Documento::Instance()->Notify();
		return true;
	}
	return false;
}

bool C_Texto::HitTest(sf::Vector2i point)
{
	if (Visible) {
		sf::Vector2f v2 = _texto.getPosition() + _rectangulo2.getSize(); //los _rectangulos no tenian el guion bajo pero daba error si no se los ponia
		if (point.x >= _rectangulo2.getPosition().x && point.x <= _rectangulo2.getPosition().x + _rectangulo2.getSize().x && point.y >= _rectangulo2.getPosition().y && point.y <= _rectangulo2.getPosition().y + _rectangulo2.getSize().y)
		{
			cout << "allahuakbar";
			return true;
		}
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

void C_Texto::setSize(sf::Vector2f size)
{
	if (!Bloqueado && Visible) {
		_size = size;
		if (size.x != 0) {
			_texto.setCharacterSize(size.x);
			C_Documento::Instance()->Notify();
		}
		
	}
}

C_Texto::C_Texto(int size)
{
	_font.loadFromFile("Assets/calibri.ttf");
	_texto.setFont(_font);
	_texto.setCharacterSize(size);
	_texto.setString("TEXTO");
	_texto.setFillColor(sf::Color::Black);

}


C_Texto::~C_Texto()
{
}
