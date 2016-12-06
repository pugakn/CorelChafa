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

	out << ID << endl;

	out << _a.x << endl;
	out << _a.y << endl;
	out << _b.x << endl;
	out << _a.y << endl;

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

void C_Linea::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	ID = stoi(str);

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

void C_Linea::Inicializar()
{
	_shape = sf::VertexArray(sf::Lines, 2);
	_shape[0].position = _a;
	_shape[1].position = _b;
	_originalPos.push_back(_a);
	_originalPos.push_back(_b);

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);
}

void C_Linea::setColorRelleno(sf::Color color)
{
	//sf::RectangleShape rectangulo;
	//rectangulo.setPosition(rectangulo.getPosition(), rectangulo.getPosition() + rectangulo.getSize());
}

void C_Linea::setColorLinea(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorLinea = color;
		for (int i = 0; i < 2; i++)
		{
			_shape[i].color = color;
		}
	}
}

bool C_Linea::setPosicion(sf::Vector2f posicion)
{
	if (!Bloqueado && Visible) {
		_posicion = posicion;
		_shape[0].position = _originalPos[0] + posicion;
		_shape[1].position = _originalPos[1] + posicion;
		//_a = _shape[0].position;
		//_b = _shape[1].position;
		return true;
	}
	return false;
}

void C_Linea::setSize(sf::Vector2f size)
{
	if (!Bloqueado && Visible) {
		_size = size;
		_shape[1].position = _originalPos[1] + size;
		_b = _shape[1].position;
		_pendiente = (_b.y - _a.y) / (_b.x - _a.x);
		_angulo = atanf(_pendiente);
		_angulo = _angulo * 180 / 3.141592;
	}
}

void C_Linea::setLastVertexPos(sf::Vector2f pos) {
	if (!Bloqueado && Visible) {
		_b = pos;
		_shape[1].position = pos;
		_originalPos[1] = pos;
		_pendiente = (_b.y - _a.y) / (_b.x - _a.x);
		_angulo = atanf(_pendiente);
		_angulo = _angulo * 180 / 3.141592;
	}
}

bool C_Linea::HitTest(sf::Vector2i point)
{
	if (Visible) {
		bool prueba1 = false, prueba2 = false;
		if (fabs(_angulo) >= 45) //vertical
		{
			sf::Vector2f p1(_a.x - 15, _a.y);
			sf::Vector2f p2(_a.x + 15, _a.y);
			sf::Vector2f p3(_b.x - 15, _b.y);
			sf::Vector2f p4(_b.x + 15, _b.y);
			prueba1 = HitTestTTriangle(p4, p2, p1, (sf::Vector2f)point);
			prueba2 = HitTestTTriangle(p3, p4, p1, (sf::Vector2f)point);
		}
		else //horizontal
		{
			sf::Vector2f p1(_a.x, _a.y - 15);
			sf::Vector2f p2(_a.x, _a.y + 15);
			sf::Vector2f p3(_b.x, _b.y - 15);
			sf::Vector2f p4(_b.x, _b.y + 15);
			prueba1 = HitTestTTriangle(p4, p2, p1, (sf::Vector2f)point);
			prueba2 = HitTestTTriangle(p3, p4, p1, (sf::Vector2f)point);
		}

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
	}
	return false;
}

void C_Linea::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
}

C_Linea::C_Linea(sf::Vector2f a, sf::Vector2f b)
{
	_a = a;
	_b = b;
	_pendiente = (_b.y - _a.y) / (_b.x - _a.x);
	_angulo = atanf(_pendiente);
	_angulo = _angulo * 180 / 3.141592;
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
