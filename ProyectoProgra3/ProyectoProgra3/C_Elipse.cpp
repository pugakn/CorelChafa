#include "stdafx.h"
#include "C_Elipse.h"
#define Pi 3.141592

int C_Elipse::GetCLSID()
{
	return 0;
}

void C_Elipse::Guardar(ofstream & out)
{
	out << ID << endl;

	out << _ra << endl;
	out << _rb << endl;

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
	Bloqueado = stoi(str);
	getline(in, str);
	Visible = stoi(str);

	Inicializar();
}

void C_Elipse::Inicializar()
{
	_shape = sf::VertexArray(sf::TrianglesFan, 0);
	std::vector<sf::Vector2f> points = CaclVertex(_ra, _rb);
	_shape.append(sf::Vertex(sf::Vector2f(0, 0)));
	for (auto it = points.begin(); it != points.end(); ++it)
	{
		_shape.append(sf::Vertex(*it));
	}

	setColorLinea(_colorLinea);
	setColorRelleno(_colorRelleno);
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
	//std::vector<sf::Vector2f> temp;
	//sf::VertexArray(sf::LinesStrip, /**/);
	//for (int i = 0; i < 40; i++)
	//{
	//	float rad = (3.141592f * 2 / 40 * i);
	//	temp.push_back(sf::Vector2f(ra*cosf(rad), rb*sinf(rad)));
	//}
	
}

bool C_Elipse::setPosicion(sf::Vector2f posicion)
{
	int i = 0;
	for (i = 0; i <= 40; i++)
	{
		_shape[i].position.x += posicion.x;
		_shape[i].position.y += posicion.y;
	} 
	if (i == 39)
	{
	return true;

	}
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
	float rad;

	for (int i = 0; i < 40; i++)
	{
		rad = (Pi * 2 / 40)*i;
		temp.push_back(sf::Vector2f(ra*cosf(rad), rb*sinf(rad)));
	}
	return temp;

}