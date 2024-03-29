#include "stdafx.h"
#include "C_Triangulo.h"
#include "VECTOR.h"
#include "C_Documento.h"

#include <iostream>

int C_Triangulo::GetCLSID()
{
	return ClassID_Triangulo;
}

void C_Triangulo::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << ID << endl;

	out << _l1 << endl;
	out << _l2 << endl;

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

void C_Triangulo::Inicializar()
{
	sf::Vector2f origen(500, 500);

	_shape = sf::VertexArray(sf::Triangles, 3);
	_shape[0].position = sf::Vector2f(_l1 * -.5f, 0);
	_shape[1].position = sf::Vector2f(_l1 * .5f, 0);
	_shape[2].position = sf::Vector2f(_l1 * .5f, -_l2);

	_originalPos.resize(3);
	_originalPos[0] = _shape[0].position - _shape[0].position;
	_originalPos[1] = _shape[1].position - _shape[0].position;
	_originalPos[2] = _shape[2].position - _shape[0].position;
	//Centrar en el origen
	_shape[0] = sf::Vector2f(_shape[0].position.x, _shape[0].position.y - _shape[2].position.y *0.5f);
	_shape[1] = sf::Vector2f(_shape[1].position.x, _shape[1].position.y - _shape[2].position.y *0.5f);
	_shape[2] = sf::Vector2f(_shape[2].position.x, _shape[2].position.y - _shape[2].position.y *0.5f);

	//LINEA
	_linea = sf::VertexArray(sf::LinesStrip, 4);
	_linea[0].position = _shape[0].position;
	_linea[1].position = _shape[1].position;
	_linea[2].position = _shape[2].position;
	_linea[3] = _linea[0];

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
	setID(ID);
	setSize(_size);
	setType(_type);
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

	_originalPos.clear();
	_originalPos.resize(3);
	_originalPos[0] = _shape[0].position - _shape[0].position;
	_originalPos[1] = _shape[1].position - _shape[0].position;
	_originalPos[2] = _shape[2].position - _shape[0].position;
	//Centrar en el origen
	//_shape[0] = sf::Vector2f( _shape[0].position.x, _shape[0].position.y - _shape[2].position.y *0.5f);
	//_shape[1] = sf::Vector2f(_shape[1].position.x, _shape[1].position.y - _shape[2].position.y *0.5f);
	//_shape[2] = sf::Vector2f(_shape[2].position.x, _shape[2].position.y - _shape[2].position.y *0.5f);

	//LINEA
	_linea = sf::VertexArray(sf::LinesStrip, 4);
	_linea[0].position = _shape[0].position;
	_linea[1].position = _shape[1].position;
	_linea[2].position = _shape[2].position;
	_linea[3] = _linea[0];
	_size = sf::Vector2f(l1,l2);

}


C_Triangulo::~C_Triangulo()
{
}

bool C_Triangulo::setPosicion(sf::Vector2f posicion)
{
	if (posicion.x > 0 && posicion.y > 0) {
		if (!Bloqueado && Visible) {
			_posicion = posicion;
			C_Documento::Instance()->Notify();
			_shape[0].position = _originalPos[0] + posicion;
			_shape[1].position = _originalPos[1] + posicion;
			_shape[2].position = _originalPos[2] + posicion;

			_linea[0].position = _originalPos[0] + posicion;
			_linea[1].position = _originalPos[1] + posicion;
			_linea[2].position = _originalPos[2] + posicion;
			_linea[3].position = _originalPos[0] + posicion;

			return true;
		}
	}
	return false;
}


bool C_Triangulo::HitTest(sf::Vector2i point)
{
	/*sf::Vector2f u = _shape[1].position - _shape[0].position;
	sf::Vector2f p = (sf::Vector2f)point - _shape[0].position;
	sf::Vector3f c1 = Cross(u, p);

	u =_shape[2].position - _shape[1].position;
	p = (sf::Vector2f)point - _shape[1].position;
	sf::Vector3f c2 = Cross(u, p);

	u = _shape[0].position -_shape[2].position;
	p = (sf::Vector2f)point - _shape[2].position;
	sf::Vector3f c3 = Cross(u, p);
	if ((c1.z < 0) && (c2.z < 0) && (c3.z < 0)) { //DEBUG
		std::cout << "YEI";
	}
	return ((c1.z < 0) && (c2.z < 0) && (c3.z < 0));*/
	if (!Visible)
		return false;
	if (HitTestTTriangle(_shape[0].position, _shape[1].position, _shape[2].position, (sf::Vector2f) point)) {
		std::cout << "YEI";
		return true;
	}
	return false;
}

void C_Triangulo::setColorRelleno(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorRelleno = color;
		C_Documento::Instance()->Notify();
		for (int i = 0; i < 3; i++) {
			_shape[i].color = color;
		}

		C_Documento::Instance()->Notify();
	}
}

void C_Triangulo::setColorLinea(sf::Color color)
{
	if (!Bloqueado && Visible) {
		_colorLinea = color;
		C_Documento::Instance()->Notify();
		for (int i = 0; i < 4; i++) {
			_linea[i].color = color;
		}

		C_Documento::Instance()->Notify();
	}
}

void C_Triangulo::setSize(sf::Vector2f size)
{
	if (!Bloqueado && Visible) {
		_size = size;
		//size.y = size.y;
		//_l1 = size.x;
		//_l2 = size.y;
		C_Documento::Instance()->Notify();
		_shape[1].position = sf::Vector2f(_shape[0].position.x + size.x, _shape[1].position.y);
		_shape[2].position = sf::Vector2f(_shape[0].position.x + size.x * .5f, _shape[0].position.y + size.y);

		_linea[1].position = sf::Vector2f(_linea[0].position.x + size.x, _linea[1].position.y);
		_linea[2].position = sf::Vector2f(_linea[0].position.x + size.x * .5f, _linea[0].position.y + size.y);

		_originalPos[1] = sf::Vector2f(_originalPos[0].x + size.x, _originalPos[1].y);
		_originalPos[2] = sf::Vector2f(_originalPos[0].x + size.x * .5f, _originalPos[0].y + size.y);

		C_Documento::Instance()->Notify();
	}
}

void C_Triangulo::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
	window.draw(_linea);
}

