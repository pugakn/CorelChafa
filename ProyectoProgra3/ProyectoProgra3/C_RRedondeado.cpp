#include "stdafx.h"
#include "C_RRedondeado.h"


int C_RRedondeado::GetCLSID()
{
	return ClassID_RRedondeado;
}

void C_RRedondeado::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << _base << endl;
	out << _altura << endl;

	out << _colorLinea.r << endl;
	out << _colorLinea.g << endl;
	out << _colorLinea.b << endl;

	out << _colorRelleno.r << endl;
	out << _colorRelleno.g << endl;
	out << _colorRelleno.b << endl;

	out << _posicion.x << endl;
	out << _posicion.y << endl;
	out << Bloqueado << endl;
	out << Visible << endl;
}

void C_RRedondeado::Cargar(ifstream & in)
{
	string str;

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
	Bloqueado = stoi(str);
	getline(in, str);
	Visible = stoi(str);

	Inicializar();
}

void C_RRedondeado::Inicializar()
{
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

	/*float radio = _altura*0.2;
	float rad1 = 3.141592 / 20;
	// define the points
	for (int i = 0; i < 10; i++)
	{
		_shape.setPoint(i, sf::Vector2f(radio*(cos(rad1))+500, radio*(sin(rad1))+500));
		rad1 += 3.141592 / 20;
	}
	sf::Vector2f A = _shape.getPoint(9);
	A.x -= _base;
	_shape.setPoint(10, A);

	//rad1 = 3.141592 / 20;
	for (int i = 0; i < 9; i++)
	{
		_shape.setPoint(i+11, sf::Vector2f(radio*(cos(rad1)) + 500 -A.x*2, radio*(sin(rad1)) + 500));
		rad1 += 3.141592 / 20;
	}*/

	
}

void C_RRedondeado::setColorRelleno(sf::Color color)
{
	
	_shape.setFillColor(color);
	
}

void C_RRedondeado::setColorLinea(sf::Color color)
{
	_shape.setOutlineColor(color);
	_shape.setOutlineThickness(1);
}

bool C_RRedondeado::setPosicion(sf::Vector2f vector)
{
	if (vector.x > 0 && vector.y > 0)
	{
		_posicion = vector;
		for (int i = 0; i < 40; i++)
		{
			_shape.setPoint(i, _originalpos[i] + vector - sf::Vector2f((_base / 2), (_altura / 2)));
		}
		return true;
	}
	
	return false;
}
#include <iostream>
bool C_RRedondeado::HitTest(sf::Vector2i point)
{
	if (point.x < (_shape.getPoint(0).x + radius) && point.y > (_shape.getPoint(0).y)
		&& (point.x > _shape.getPoint(0).x + radius - _base) && (point.y < _shape.getPoint(0).y + _altura))
	{
		return true;
	}
	return false;
}

void C_RRedondeado::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
}

void C_RRedondeado::setSize(sf::Vector2f size)
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
