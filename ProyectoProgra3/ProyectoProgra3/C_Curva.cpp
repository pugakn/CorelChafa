#include "stdafx.h"
#include "C_Curva.h"


int C_Curva::GetCLSID()
{
	return 0;
}

void C_Curva::Guardar(ofstream & out)
{
	out << ID << endl;

	out << _p1.x << endl;
	out << _p1.y << endl;
	out << _p2.x << endl;
	out << _p2.y << endl;
	out << _c1.x << endl;
	out << _c1.y << endl;
	out << _c2.x << endl;
	out << _c2.y << endl;

	out << _colorLinea.r << endl;
	out << _colorLinea.g << endl;
	out << _colorLinea.b << endl;

	out << _colorRelleno.r << endl;
	out << _colorRelleno.g << endl;
	out << _colorRelleno.b << endl;

	out << _posicion.x << endl;
	out << _posicion.y << endl;
}

void C_Curva::Cargar(ifstream & in)
{
}

C_Curva::C_Curva()
{
}

C_Curva::C_Curva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2)
{
	_p1 = p1;
	_p2 = p2;
	_c1 = c1;
	_c2 = c2;
	_vertices = sf::VertexArray (sf::LinesStrip, 0);
	std::vector<sf::Vector2f> points =
		CalcCubicBezier(p1,p2,c1,c2,40);
	for (auto it = points.begin(); it != points.end(); ++it)
		_vertices.append(sf::Vertex(*it));
}


C_Curva::~C_Curva()
{
}

std::vector<sf::Vector2f> CalcCubicBezier(
	sf::Vector2f &inicio,
	sf::Vector2f &fin,
	sf::Vector2f &control1,
	sf::Vector2f &control2,
	int nSegmentos)
{
	std::vector<sf::Vector2f> ret;
	ret.push_back(inicio);
	float p = 1.f / nSegmentos;
	float q = p;
	for (int i = 1; i < nSegmentos; i++, p += q) 
		ret.push_back(p * p * p * (fin + 3.f * (control1 - control2) - inicio) +
			3.f * p * p * (inicio - 2.f * control1 + control2) +
			3.f * p * (control1 - inicio) + inicio);
	ret.push_back(fin);
	return ret;
}

bool C_Curva::HitTest()
{
	return false;
}

void C_Curva::setColorRelleno(sf::Color color)
{

}

void C_Curva::setColorLinea(sf::Color color)
{
}

bool C_Curva::setPosicion(sf::Vector2f posicion)
{
	return false;
}
