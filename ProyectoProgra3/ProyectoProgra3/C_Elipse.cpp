#include "stdafx.h"
#include "C_Elipse.h"
#include "C_Documento.h"
#include <iostream>
#define Pi 3.141592

int C_Elipse::GetCLSID()
{
	return ClassID_Elipse;
}

void C_Elipse::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << ID << endl;

	out << _ra << endl;
	out << _rb << endl;

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

void C_Elipse::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	_ra = stoi(str);
	getline(in, str);
	_rb = stoi(str);

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

void C_Elipse::Inicializar()
{
	_centro = sf::Vector2f(0, 0);
	_shape = sf::VertexArray(sf::TrianglesFan, 0);
	std::vector<sf::Vector2f> points = CaclVertex(_ra, _rb);
	_shape.append(sf::Vertex(sf::Vector2f(0, 0)));
	for (auto it = points.begin(); it != points.end(); ++it)
	{
		_shape.append(sf::Vertex(*it));
	}

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);
}

C_Elipse::C_Elipse(float ra, float rb)
{

	_ra = ra;
	_rb = rb;
	_centro = sf::Vector2f(0,0);
	_shape = sf::VertexArray(sf::TrianglesFan,0);
	std::vector<sf::Vector2f> points = CaclVertex(ra, rb);
	_shape.append(sf::Vertex(sf::Vector2f(0, 0)));
	for (auto it = points.begin(); it != points.end(); ++it)
	{
		_shape.append(sf::Vertex(*it));
	}

	//_shape[0].position.x += ra;
}

void C_Elipse::setColorRelleno(sf::Color color)
{
	for ( unsigned it = 0; it < _shape.getVertexCount(); ++it)
	{
		_shape[it].color = color;
	}
	C_Documento::Instance()->Notify();
}

void C_Elipse::setColorLinea(sf::Color color)
{

	std::vector<sf::Vector2f> temp;
	//sf::VertexArray(sf::LinesStrip, /**/);
	for (int i = 0; i < 40; i++)
	{
		float rad = (3.141592f * 2 / 40 * i);
		_shape[i].color = color;  //?
		//temp.push_back(sf::Vector2f(ra*cosf(rad), rb*sinf(rad)));
	}
	C_Documento::Instance()->Notify();
	
}

bool C_Elipse::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0)
	{
		if (!Bloqueado)
		{
			int i = 0;
			_centro += posicion;
			for (i = 0; i <= 40; i++)
			{
				_shape[i].position.x += posicion.x;
				_shape[i].position.y += posicion.y;
			}
			C_Documento::Instance()->Notify();
			return true;
		}
	}
	return false;
}

void C_Elipse::setSize(sf::Vector2f size)
{
	if (!Bloqueado)
	{
		_centro = sf::Vector2f(_posicion.x, _posicion.y);
		_shape = sf::VertexArray(sf::TrianglesFan, 0);
		std::vector<sf::Vector2f> points = CaclVertex(size.x, size.y);
		_shape.append(sf::Vertex(sf::Vector2f(0, 0)));
		for (auto it = points.begin(); it != points.end(); ++it)
		{
			_shape.append(sf::Vertex(*it));
		}
		C_Documento::Instance()->Notify();
	}
}

bool C_Elipse::HitTest(sf::Vector2i point)
{
	if (!Visible)
		return false;

	//sf::Vector2f _centro;
	sf::Vector2f foco1(_centro.x - abs( sqrt((_ra*_ra) - (_rb*_rb))),abs(_centro.y));
	sf::Vector2f foco2(_centro.x + abs(sqrt((_ra*_ra) - (_rb*_rb))), abs(_centro.y));
	sf::Vector2f v1 = (sf::Vector2f) point - foco1;
	sf::Vector2f v2 = (sf::Vector2f) point - foco2;
	float distancia = sqrt((v1.x*v1.x) + (v1.y*v1.y))+ sqrt((v2.x*v2.x) + (v2.y*v2.y));
	if (distancia < _ra)
	{
		std::cout << "allahu akbar";
		return true;
	}
	return false;
}

void C_Elipse::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
}

C_Elipse::C_Elipse()
{
}


C_Elipse::~C_Elipse()
{
}


std::vector <sf::Vector2f> CaclVertex(float ra, float rb)
{
	std::vector<sf::Vector2f> temp;
	float rad;

	for (int i = 0; i < 40; i++)
	{
		rad = (Pi * 2 / 40)*i;
		temp.push_back(sf::Vector2f(ra*cosf(rad), rb*sinf(rad)));
	}
	return temp;

}