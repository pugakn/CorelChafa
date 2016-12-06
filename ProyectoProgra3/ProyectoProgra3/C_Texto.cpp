#include "stdafx.h"
#include "C_Texto.h"
#include <iostream>
#include "C_Documento.h"


int C_Texto::GetCLSID()
{
	return ClassID_Texto;
}

void C_Texto::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << ID << endl;

	out << _base2 << endl;
	out << _alt2 << endl;
	out << textString << endl;

	out << (int)_colorLinea.r << endl;
	out << (int)_colorLinea.g << endl;
	out << (int)_colorLinea.b << endl;

	out << (int)_colorRelleno.r << endl;
	out << (int)_colorRelleno.g << endl;
	out << (int)_colorRelleno.b << endl;

	out << _posicion.x << endl;
	out << _posicion.y << endl;

	out << _size.x << endl;
	out << _size.y << endl;

	out << _type << endl;

	out << Bloqueado << endl;
	out << Visible << endl;
}

void C_Texto::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	_base2 = stoi(str);
	getline(in, str);
	_alt2 = stoi(str);

	getline(in, str);
	textString = str;

	getline(in, str);
	_colorLinea.r = stoi(str);
	getline(in, str);
	_colorLinea.g = stoi(str);
	getline(in, str);
	_colorLinea.b = stoi(str);

	getline(in, str);
	_colorRelleno.r = stoi(str);
	getline(in, str);
	_colorRelleno.g = stoi(str);
	getline(in, str);
	_colorRelleno.b = stoi(str);

	getline(in, str);
	_posicion.x = stoi(str);
	getline(in, str);
	_posicion.y = stoi(str);

	getline(in, str);
	_size.x = stoi(str);
	getline(in, str);
	_size.y = stoi(str);

	getline(in, str);
	_type = str;

	getline(in, str);
	Bloqueado = stoi(str);
	getline(in, str);
	Visible = stoi(str);

	Inicializar();
}

void C_Texto::Inicializar()
{
	_font.loadFromFile("Assets/calibri.ttf");
	_texto.setFont(_font);
	_texto.setCharacterSize(500);
	_texto.setString("TEXTO");
	_texto.setFillColor(sf::Color::Black);

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);
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
		if (_texto.getGlobalBounds().contains((sf::Vector2f)point))
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

C_Texto::C_Texto()
{
}


C_Texto::~C_Texto()
{
}
