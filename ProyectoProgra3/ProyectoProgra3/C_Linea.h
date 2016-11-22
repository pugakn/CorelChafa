#pragma once
#include "C_Figura.h"
#define ClassID_Linea 3

class C_Linea : public C_Figura
{
public:
	sf::VertexArray _shape;
	sf::Vector2f _a, _b;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest(sf::Vector2i point);
	C_Linea(sf::Vector2f a, sf::Vector2f b);
	C_Linea();
	~C_Linea();
};

