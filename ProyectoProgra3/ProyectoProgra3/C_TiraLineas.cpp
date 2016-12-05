#include "stdafx.h"
#include "C_TiraLineas.h"
#include "VECTOR.h"
#include <iostream>
#include "C_Documento.h"


int C_TiraLineas::GetCLSID()
{
	return ClassID_TiraLineas;
}

void C_TiraLineas::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;

	out << _a.x << endl;
	out << _a.y << endl;
	out << _b.x << endl;
	out << _b.y << endl;

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

void C_TiraLineas::Cargar(ifstream & in)
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

void C_TiraLineas::Inicializar()
{
	_shape = sf::VertexArray(sf::LinesStrip, 2);
	_shape[0].position = _a;
	_shape[1].position = _b;
	_originalPos.push_back(_shape[0].position - _shape[0].position);
	_originalPos.push_back(_shape[1].position - _shape[0].position);

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
	setPosicion(_posicion);
}

C_TiraLineas::C_TiraLineas()
{
}

C_TiraLineas::C_TiraLineas(sf::Vector2f a, sf::Vector2f b)
{
	_a = a;
	_b = b;
	_shape = sf::VertexArray(sf::LinesStrip, 2);
	_shape[0].position = a;
	_shape[1].position = b;
	_originalPos.push_back(_shape[0].position - _shape[0].position);
	_originalPos.push_back(_shape[1].position - _shape[0].position);
	
}

void C_TiraLineas::nuevoVertice(sf::Vector2f vertice)
{
	int i = _shape.getVertexCount();
	_shape.append(vertice);
	_originalPos.push_back(vertice - _shape[0].position);
	float pendiente = (_shape[i-1].position.y - _shape[i-2].position.y) / (_shape[i-1].position.x - _shape[i-2].position.x);
	float angulo = atanf(pendiente);
	angulo = angulo * 180 / 3.141592;
	_angulos.push_back(angulo);
	_angulos.resize(i-1);
}

void C_TiraLineas::setColorRelleno(sf::Color color)
{
}

void C_TiraLineas::setColorLinea(sf::Color color)
{
	_colorLinea = color;
	for (unsigned i = 0; i < _shape.getVertexCount(); i++) {
		_shape[i].color = color;
	}
	C_Documento::Instance()->Notify();
}

bool C_TiraLineas::setPosicion(sf::Vector2f vector)
{
	_posicion = vector;
	if (vector.x > 0 && vector.y > 0) {
		for (unsigned i = 0; i < _shape.getVertexCount(); i++)
		{
			_shape[i].position = _originalPos[i] + vector;
		}
		C_Documento::Instance()->Notify();
		return true;
	}
	return false;
}

void C_TiraLineas::setSize(sf::Vector2f size)
{
	std::vector<sf::Vector2f> pos;
	for (unsigned i = 0; i < _shape.getVertexCount(); i++)
		pos.push_back(_shape[i].position);
	for (unsigned i = 1; i < _shape.getVertexCount(); i++)
	{
		_shape[i].position = pos[i] + sf::Vector2f(size.x/50,_shape[i].position.y);
	}
	C_Documento::Instance()->Notify();
}

bool C_TiraLineas::HitTest(sf::Vector2i point)
{
	for (int i = 0; i < _shape.getVertexCount()-2;i++) 
	{
		if (fabs(_angulos[i]) >= 45) //vertical
		{
			if (HitTestTTriangle(_shape[i].position + sf::Vector2f(15, 0), _shape[i + 1].position + sf::Vector2f(15, 0), _shape[i].position - sf::Vector2f(15, 0), (sf::Vector2f)point))
				return true;
			if (HitTestTTriangle(_shape[i + 1].position + sf::Vector2f(15, 0), _shape[i + 1].position - sf::Vector2f(15, 0), _shape[i].position - sf::Vector2f(15, 0), (sf::Vector2f)point))
				return true;
		}
		else //horizontal
		{
			if (HitTestTTriangle(_shape[i].position + sf::Vector2f(0, 15), _shape[i + 1].position + sf::Vector2f(0, 15), _shape[i].position - sf::Vector2f(0, 15), (sf::Vector2f)point))
				return true;
			if (HitTestTTriangle(_shape[i + 1].position + sf::Vector2f(0, 15), _shape[i + 1].position - sf::Vector2f(0, 15), _shape[i].position - sf::Vector2f(0, 15), (sf::Vector2f)point))
				return true;
		}
	}
	return false;
}

void C_TiraLineas::Dibujar(sf::RenderWindow & window)
{
	window.draw(_shape);
}

void C_TiraLineas::SetLastPointPosition(sf::Vector2f size)
{
	_shape[_shape.getVertexCount() - 1].position = size;
	C_Documento::Instance()->Notify();
}


C_TiraLineas::~C_TiraLineas()
{
}
