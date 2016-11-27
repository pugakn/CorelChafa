#include "stdafx.h"
#include "C_Linea.h"


int C_Linea::GetCLSID()
{
	return 0;
}

void C_Linea::Guardar(ofstream & out)
{
	out << ID << endl;

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

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
}

void C_Linea::setColorRelleno(sf::Color color)
{
}

void C_Linea::setColorLinea(sf::Color color)
{
}

bool C_Linea::setPosicion(sf::Vector2f vector)
{
	return false;
}

void C_Linea::setSize(sf::Vector2f size)
{
}

bool C_Linea::HitTest(sf::Vector2i point)
{
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
	_shape = sf::VertexArray(sf::Lines, 2);
	_shape[0].position = a;
	_shape[1].position = b;
}

C_Linea::C_Linea()
{
}


C_Linea::~C_Linea()
{
}
