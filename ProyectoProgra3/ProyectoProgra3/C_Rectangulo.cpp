#include "stdafx.h"
#include "C_Rectangulo.h"
#include <iostream>


int C_Rectangulo::GetCLSID()
{
	return ClassID_Rectangulo;
}

void C_Rectangulo::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << ID << endl;

	out << _base1 << endl;
	out << _alt1 << endl;

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

void C_Rectangulo::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	_base1 = stoi(str);
	getline(in, str);
	_alt1 = stoi(str);

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

void C_Rectangulo::Inicializar()
{
	_rectangulo = sf::RectangleShape(sf::Vector2f(_base1, _alt1));

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);

}

void C_Rectangulo::setSize(sf::Vector2f size)
{
	if (!Bloqueado && Visible) {
		_size = size;
		_rectangulo.setSize(size);
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
	}
}

void C_Rectangulo::setColorLinea(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorLinea = color;
		_rectangulo.setOutlineThickness(1);
		_rectangulo.setOutlineColor(color);
	}
}

bool C_Rectangulo::setPosicion(sf::Vector2f vector)
{
	if (!Bloqueado && Visible) {
		_posicion = vector;
		_rectangulo.setPosition(vector);

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
