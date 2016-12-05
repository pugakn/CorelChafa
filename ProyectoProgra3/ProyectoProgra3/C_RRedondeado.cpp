#include "stdafx.h"
#include "C_RRedondeado.h"
#include "C_Documento.h"


int C_RRedondeado::GetCLSID()
{
	return ClassID_RRedondeado;
}

void C_RRedondeado::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << ID << endl;

	out << _base << endl;
	out << _altura << endl;

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

void C_RRedondeado::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	_base = stoi(str);
	getline(in, str);
	_altura = stoi(str);

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
	_type = stoi(str);

	getline(in, str);
	Bloqueado = stoi(str);
	getline(in, str);
	Visible = stoi(str);

	Inicializar();
}

void C_RRedondeado::Inicializar()
{
	_shape.setPointCount(40);
	radius = _base*.1;
	float X = 0, Y = 0;
	for (int i = 0; i<10; i++)
	{
		X += radius / 10;
		Y = sqrt(radius*radius - X*X);
		_shape.setPoint(i, sf::Vector2f(X + 0 + _base - radius, 0 - Y + radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	Y = 0;
	for (int i = 10; i<20; i++)
	{
		Y += radius / 10;
		X = sqrt(radius*radius - Y*Y);
		_shape.setPoint(i, sf::Vector2f(X + 0 + _base - radius, Y + 0 + _altura - radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	X = 0;
	for (int i = 20; i<30; i++)
	{
		X += radius / 10;
		Y = sqrt(radius*radius - X*X);
		_shape.setPoint(i, sf::Vector2f(0 + radius - X, 0 + _altura + Y - radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	Y = 0;
	for (int i = 30; i<40; i++)
	{
		Y += radius / 10;
		X = sqrt(radius*radius - Y*Y);
		_shape.setPoint(i, sf::Vector2f(0 - X + radius, 0 + radius - Y));
		_originalpos.push_back(_shape.getPoint(i));
	}
	_size = sf::Vector2f(_base, _altura);
	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);
}

C_RRedondeado::C_RRedondeado(float base, float altura)
{
	_base = base;
	_altura = altura;
	_shape.setPointCount(40);
	radius = _base*.1;
	float X = 0, Y = 0;
	for (int i = 0; i<10; i++)
	{
		X += radius / 10;
		Y = sqrt(radius*radius - X*X);
		_shape.setPoint(i, sf::Vector2f(X + 0 + _base - radius, 0 - Y + radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	Y = 0;
	for (int i = 10; i<20; i++)
	{
		Y += radius / 10;
		X = sqrt(radius*radius - Y*Y);
		_shape.setPoint(i, sf::Vector2f(X + 0 + _base - radius, Y + 0 + _altura - radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	X = 0;
	for (int i = 20; i<30; i++)
	{
		X += radius / 10;
		Y = sqrt(radius*radius - X*X);
		_shape.setPoint(i, sf::Vector2f(0 + radius - X, 0 + _altura + Y - radius));
		_originalpos.push_back(_shape.getPoint(i));
	}
	Y = 0;
	for (int i = 30; i<40; i++)
	{
		Y += radius / 10;
		X = sqrt(radius*radius - Y*Y);
		_shape.setPoint(i, sf::Vector2f(0 - X + radius, 0 + radius - Y));
		_originalpos.push_back(_shape.getPoint(i));
	}
	_size = sf::Vector2f(base,altura);
}

void C_RRedondeado::setColorRelleno(sf::Color color)
{
	if (!Bloqueado)
	{
		_shape.setFillColor(color);
		C_Documento::Instance()->Notify();
	}
}

void C_RRedondeado::setColorLinea(sf::Color color)
{
	if (!Bloqueado)
	{
		_shape.setOutlineColor(color);
		_shape.setOutlineThickness(1);
		C_Documento::Instance()->Notify();
	}
}

bool C_RRedondeado::setPosicion(sf::Vector2f vector)
{
	if (vector.x > 0 && vector.y > 0)
	{
		if (!Bloqueado)
		{
			_posicion = vector;
			for (int i = 0; i < 40; i++)
			{
				_shape.setPoint(i, _originalpos[i] + vector - sf::Vector2f((_base / 2), (_altura / 2)));
			}

			C_Documento::Instance()->Notify();
			return true;
		}
	}
	
	return false;
}
#include <iostream>
bool C_RRedondeado::HitTest(sf::Vector2i point)
{
	if (!Visible)
		return false;

	if (point.x < (_shape.getPoint(0).x + radius) && point.y > (_shape.getPoint(0).y)
		&& (point.x > _shape.getPoint(0).x + radius - _base) && (point.y < _shape.getPoint(0).y + _altura))
	{
		C_Documento::Instance()->Notify();
		return true;
	}
	return false;
}

void C_RRedondeado::setSize(sf::Vector2f size)
{
	if (size.x > 10 && size.y > 10) {
		if (!Bloqueado)
		{
			_size = size;
			float X = 0, Y = 0;
			for (int i = 0; i<10; i++)
			{
				X += radius / 10;
				Y = sqrt(radius*radius - X*X);
				_shape.setPoint(i, sf::Vector2f(X + 0 + _size.x - radius, 0 - Y + radius));
				_originalpos[i] = (_shape.getPoint(i));
			}
			Y = 0;
			for (int i = 10; i<20; i++)
			{
				Y += radius / 10;
				X = sqrt(radius*radius - Y*Y);
				_shape.setPoint(i, sf::Vector2f(X + 0 + _size.x - radius, Y + 0 + _size.y - radius));
				_originalpos[i] = (_shape.getPoint(i));
			}
			X = 0;
			for (int i = 20; i<30; i++)
			{
				X += radius / 10;
				Y = sqrt(radius*radius - X*X);
				_shape.setPoint(i, sf::Vector2f(0 + radius - X, 0 + _size.y + Y - radius));
				_originalpos[i] = (_shape.getPoint(i));
			}
			Y = 0;
			for (int i = 30; i<40; i++)
			{
				Y += radius / 10;
				X = sqrt(radius*radius - Y*Y);
				_shape.setPoint(i, sf::Vector2f(0 - X + radius, 0 + radius - Y));
				_originalpos[i] = (_shape.getPoint(i));
			}

			setPosicion(_posicion);

			C_Documento::Instance()->Notify();
		}
	}
	

}

void C_RRedondeado::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
}

C_RRedondeado::C_RRedondeado()
{
	/*sf::ConvexShape convex;
	convex.setPointCount(12);
	convex.setPoint(0,sf::Vector2f(0, 0));
	convex.setPoint(1, sf::Vector2f(150, 0));
	convex.setPoint(2, sf::Vector2f(150, 75));
	convex.setPoint(3, sf::Vector2f(0, 75));
	//convex.setPoint(4, sf::Vector2f(0, 0));*/
}


C_RRedondeado::~C_RRedondeado()
{
}
