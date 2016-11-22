#include "stdafx.h"
#include "C_Elipse.h"


int C_Elipse::GetCLSID()
{
	return 0;
}

void C_Elipse::Guardar(ofstream & out)
{
}

void C_Elipse::Cargar(ifstream & in)
{
}

C_Elipse::C_Elipse(float ra, float rb)
{
	_ra = ra;
	_rb = rb;
	_shape = sf::VertexArray(sf::TrianglesFan,0);
	std::vector<sf::Vector2f> points = CaclVertex(ra, rb);
	_shape.append(sf::Vertex(sf::Vector2f(0, 0)));
	for (auto it = points.begin(); it != points.end(); ++it)
	{
		_shape.append(sf::Vertex(*it));
	}
}

void C_Elipse::setColorRelleno(sf::Color color)
{
	for ( unsigned it = 0; it < _shape.getVertexCount(); ++it)
	{
		_shape[it].color = color;
	}
}

void C_Elipse::setColorLinea(sf::Color color)
{
}

bool C_Elipse::setPosicion(sf::Vector2f vector)
{
	return false;
}

bool C_Elipse::HitTest(sf::Vector2i point)
{
	return false;
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
	
	for (int i = 0; i < 40; i++)
	{
		float rad = (3.141592f * 2 / 40*i);
		temp.push_back(sf::Vector2f(ra*cosf(rad), rb*sinf(rad)));
	}
	return temp;

}