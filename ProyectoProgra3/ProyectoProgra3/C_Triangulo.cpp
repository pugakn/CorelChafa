#include "stdafx.h"
#include "C_Triangulo.h"

sf::Vector2f operator*(sf::Vector2f A, sf::Vector2f B) {
	return sf::Vector2f(A.x*B.x, A.y*B.y);
}
sf::Vector2f operator/(sf::Vector2f A, sf::Vector2f B) {
	return sf::Vector2f(A.x/B.x, A.y/B.y);
}

int C_Triangulo::GetCLSID()
{
	return 0;
}

void C_Triangulo::Guardar(ofstream & out)
{
	out << ID << endl;

	out << _l1 << endl;
	out << _l2 << endl;

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

void C_Triangulo::Cargar(ifstream & in)
{
	string str;
	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	_l1 = stoi(str);
	getline(in, str);
	_l2 = stoi(str);

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

C_Triangulo::C_Triangulo()
{
}

C_Triangulo::C_Triangulo(float l1, float l2)
{
	_l1 = l1;
	_l2 = l2;
	sf::Vector2f origen(500,500);

	_posicion = sf::Vector2f(0,0);
	_shape = sf::VertexArray(sf::Triangles, 3);
	_shape[0].position = sf::Vector2f(l1 * -.5f,0);
	_shape[1].position = sf::Vector2f(l1 * .5f, 0);
	_shape[2].position = sf::Vector2f(l1 * .5f, -l2);
	//Centrar en el origen
	_shape[0] = sf::Vector2f( _shape[0].position.x, _shape[0].position.y - _shape[2].position.y *0.5f);
	_shape[1] = sf::Vector2f(_shape[1].position.x, _shape[1].position.y - _shape[2].position.y *0.5f);
	_shape[2] = sf::Vector2f(_shape[2].position.x, _shape[2].position.y - _shape[2].position.y *0.5f);

	//LINEA
	_linea = sf::VertexArray(sf::LinesStrip, 4);
	_linea[0].position = _shape[0].position;
	_linea[1].position = _shape[1].position;
	_linea[2].position = _shape[2].position;
	_linea[3] = _linea[0];


	this->setPosicion(origen);

}


C_Triangulo::~C_Triangulo()
{
}

bool C_Triangulo::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0) {
		_posicion = posicion;
		_shape[0].position += posicion;
		_shape[1].position += posicion;
		_shape[2].position += posicion;

		_linea[0].position += posicion;
		_linea[1].position += posicion;
		_linea[2].position += posicion;
		_linea[3].position += posicion;
		return true;
	}
	return false;
}


bool C_Triangulo::HitTest()
{
	return false;
}

void C_Triangulo::setColorRelleno(sf::Color color)
{
	for (int i = 0; i < 3;i++) {
		_shape[i].color = color;
	}
	
}

void C_Triangulo::setColorLinea(sf::Color color)
{
	for (int i = 0; i < 4; i++) {
		_linea[i].color = color;
	}
}

