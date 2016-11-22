#pragma once
#include "C_Figura.h"
#define ClassID_Elipse 2

class C_Elipse : public C_Figura
{
public:
	float _ra, _rb;
	sf::VertexArray _shape;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Elipse(float ra, float rb);
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest(sf::Vector2i point);
	C_Elipse();
	~C_Elipse();
};

std::vector <sf::Vector2f> CaclVertex(float ra, float rb);