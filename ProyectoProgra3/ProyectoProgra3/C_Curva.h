#pragma once
#include "C_Figura.h"
#define ClassID_Curva 1

class C_Curva : public C_Figura
{
public: //private
	sf::Vector2f _p1, _p2;
	sf::Vector2f _c1, _c2;
	sf::VertexArray _vertices;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);

	C_Curva();
	C_Curva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2);
	~C_Curva();
	bool HitTest();
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f posicion);
};

std::vector<sf::Vector2f> CalcCubicBezier(
	sf::Vector2f &start,
	sf::Vector2f &end,
	sf::Vector2f &startControl,
	sf::Vector2f &endControl,
	int numSegments);

