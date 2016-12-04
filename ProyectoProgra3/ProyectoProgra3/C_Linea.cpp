#include "stdafx.h"
#include "C_Linea.h"
#include <iostream>


int C_Linea::GetCLSID()
{
	return ClassID_Linea;
}

void C_Linea::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << _a.x << endl;
	out << _a.y << endl;
	out << _b.x << endl;
	out << _a.y << endl;

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

void C_Linea::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	_a.x = stoi(str);
	getline(in, str);
	_a.y = stoi(str);
	getline(in, str);
	_b.x = stoi(str);
	getline(in, str);
	_b.y = stoi(str);

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

void C_Linea::Inicializar()
{
	sf::RectangleShape rectangulo;
	_shape = sf::VertexArray(sf::Lines, 2);
	_shape[0].position = _a;
	_shape[1].position = _b;

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
}

void C_Linea::setColorRelleno(sf::Color color)
{
	//sf::RectangleShape rectangulo;
	//rectangulo.setPosition(rectangulo.getPosition(), rectangulo.getPosition() + rectangulo.getSize());
}

void C_Linea::setColorLinea(sf::Color color)
{

	_colorLinea = color;
	for (int i = 0; i < 2; i++) 
	{
		_shape[i].color = color;              
	}
}

bool C_Linea::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0)
	{
		_posicion = posicion;
		_shape[0].position = _originalPos[0] + posicion;
		_shape[1].position = _originalPos[1] + posicion;
		_a = _shape[0].position;
		_b = _shape[1].position;
		return true;
	}
	return false;
}

bool C_Linea::HitTest(sf::Vector2i point)
{
	sf::Vector2f p1, p2, p3, p4;
	if (angulo <= 45 && angulo >= -45)
	{
		sf::Vector2f p1(_a.x - 15, _a.y);
		sf::Vector2f p2(_a.x + 15, _a.y);
		sf::Vector2f p3(_b.x - 15, _b.y);
		sf::Vector2f p4(_b.x + 15, _b.y);
	}
	else
	{
		sf::Vector2f p1(_a.x, _a.y-15);
		sf::Vector2f p2(_a.x, _a.y+15);
		sf::Vector2f p3(_b.x, _b.y-15);
		sf::Vector2f p4(_b.x, _b.y+15);
	}


	bool prueba1 = HitTestTTriangle(p4, p2, p1, (sf::Vector2f)point);
	bool prueba2 = HitTestTTriangle(p3, p4, p1, (sf::Vector2f)point);
	if (prueba1 == true) 
	{
		cout << "allahu akbar";
		return true;
	}

	if (prueba2 == true) 
	{
		cout << "allahu akbar";
		return true;
	}


	return false;
}




C_Linea::C_Linea(sf::Vector2f a, sf::Vector2f b)
{
	_a = a;
	_b = b;
	pendiente = (_b.y - _a.y) / (_b.x - _a.x);
	angulo = atanf(pendiente);
	angulo = angulo * 180 / 3.141592;
	cout << angulo;

	_shape = sf::VertexArray(sf::Lines, 2);
	_shape[0].position = a;
	_shape[1].position = b;
	_originalPos.push_back(a);
	_originalPos.push_back(b);

//	rectangulo.setSize(sf::Vector2f(10, 0));
}

C_Linea::C_Linea()
{
}


C_Linea::~C_Linea()
{
}
