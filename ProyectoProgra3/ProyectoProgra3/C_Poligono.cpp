#include "stdafx.h"
#include "C_Poligono.h"


int C_Poligono::GetCLSID()
{
	return ClassID_Poligono;
}

void C_Poligono::Guardar(ofstream & out)
{
	out << ID << endl;

	out << _lados << endl;
	out << _radio << endl;

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

void C_Poligono::Cargar(ifstream & in)
{
	string str;
	getline(in, str);
	ID = stoi(str);

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
	
}

C_Poligono::C_Poligono()
{
}

C_Poligono::C_Poligono(int lados, float radio)
{
	_shape = sf::CircleShape(radio, lados);
}


C_Poligono::~C_Poligono()
{
}

bool C_Poligono::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0) {
		_posicion = posicion;
		_shape.setPosition(posicion);
		return true;
	}
	return false;
}


bool C_Poligono::HitTest()
{
	return false;
}

void C_Poligono::setColorRelleno(sf::Color color)
{
	_shape.setFillColor(color);
}

void C_Poligono::setColorLinea(sf::Color color)
{
	_shape.setOutlineColor(color);
}

