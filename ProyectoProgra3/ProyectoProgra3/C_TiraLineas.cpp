#include "stdafx.h"
#include "C_TiraLineas.h"


int C_TiraLineas::GetCLSID()
{
	return 0;
}

void C_TiraLineas::Guardar(ofstream & out)
{
}

void C_TiraLineas::Cargar(ifstream & in)
{
}

C_TiraLineas::C_TiraLineas()
{
}

C_TiraLineas::C_TiraLineas(sf::Vector2f a, sf::Vector2f b)
{
	_shape = sf::VertexArray(sf::LinesStrip, 2);
	_shape[0].position = a;
	_shape[1].position = b;
	_originalPos.push_back(_shape[0].position - _shape[0].position);
	_originalPos.push_back(_shape[1].position - _shape[0].position);
	
}

void C_TiraLineas::nuevoVertice(sf::Vector2f vertice)
{
	_shape.append(vertice);
	_originalPos.push_back(vertice - _shape[0].position);
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
}

bool C_TiraLineas::setPosicion(sf::Vector2f vector)
{
	_posicion = vector;
	if (vector.x > 0 && vector.y > 0) {
		for (unsigned i = 0; i < _shape.getVertexCount(); i++)
		{
			_shape[i].position = _originalPos[i] + vector;
		}
		
		return true;
	}
	return false;
}

bool C_TiraLineas::HitTest()
{
	return false;
}


C_TiraLineas::~C_TiraLineas()
{
}
