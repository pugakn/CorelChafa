#include "stdafx.h"
#include "C_Poligono.h"
#include "VECTOR.h"

#include <iostream>


int C_Poligono::GetCLSID()
{
	return ClassID_Poligono;
}

void C_Poligono::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << _lados << endl;
	out << _radio << endl;

	out << (int)_colorLinea.r << endl;
	out << (int)_colorLinea.g << endl;
	out << (int)_colorLinea.b << endl;

	out << (int)_colorRelleno.r << endl;
	out << (int)_colorRelleno.g << endl;
	out << (int)_colorRelleno.b << endl;

	out << _posicion.x << endl;
	out << _posicion.y << endl;
	out << Bloqueado << endl;
	out << Visible << endl;
}

void C_Poligono::Cargar(ifstream & in)
{
	string str;

	getline(in, str);
	_lados = stoi(str);
	getline(in, str);
	_radio = stoi(str);

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

void C_Poligono::Inicializar()
{
	_shape = sf::CircleShape(_radio, _lados);
	_originalPos.clear();
	_originalPos.resize(_lados);
	for (int i = 0; i < _lados; i++) {
		float rad = (3.141592f) * 2 / _lados * i;
		_vertices.push_back(sf::Vector2f(_radio + (_radio*cosf(rad + 1.570796f)), _radio - (_radio*sinf(rad + 1.570796f))));
		std::cout << _vertices.back().x << " " << _vertices.back().y << "                        ";
		_originalPos[i] = _vertices[i];
	}

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
}

C_Poligono::C_Poligono()
{
}

C_Poligono::C_Poligono(int lados, float radio)
{
	_lados = lados;
	_radio = radio;
	ID = 9;
	_shape = sf::CircleShape(radio, lados);
	_originalPos.clear();
	_originalPos.resize(_lados);
	for (int i = 0; i < _lados;i++) {
		float rad = (3.141592f )* 2 / _lados * i;
		_vertices.push_back(sf::Vector2f(_radio+(_radio*cosf(rad + 1.570796f)),_radio-(_radio*sinf(rad + 1.570796f))));
		std::cout << _vertices.back().x <<" " <<_vertices.back().y <<"                        ";
		_originalPos[i] = _vertices[i];
	}
}


C_Poligono::~C_Poligono()
{
}

bool C_Poligono::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0) {
		_posicion = posicion;
		_shape.setPosition(posicion);
		for (int i = 0; i < _lados; i++) {
			_vertices[i] = _originalPos[i] + posicion;
		}
		return true;
	}
	return false;
}


bool C_Poligono::HitTest(sf::Vector2i point)
{
	
	std::vector<sf::Vector3f> c;
	for (int i = 0; i < _lados-1;i++) {
		c.push_back( Cross(_vertices[i + 1] - _vertices[i], (sf::Vector2f)point - _vertices[i]));
		if (c[i].z > 0) return false;
	}
	c.push_back( Cross(_vertices[0] - _vertices[_lados -1], (sf::Vector2f)point - _vertices[_lados -1]));
	if (c[_lados-1].z > 0) return false;
	std::cout << "YEI";
	return true;
}

void C_Poligono::setColorRelleno(sf::Color color)
{
	_colorRelleno = color;
	_shape.setFillColor(color);
}

void C_Poligono::setColorLinea(sf::Color color)
{
	_colorLinea = color;
	_shape.setOutlineColor(color);
	_shape.setOutlineThickness(1);
}

