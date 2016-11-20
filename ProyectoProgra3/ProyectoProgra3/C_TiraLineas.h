#pragma once
#include "C_Figura.h"
#define ClassID_TiraLineas 8

class C_TiraLineas : public C_Figura
{
public:
	sf::VertexArray _shape;
	std::vector<sf::Vector2f> _originalPos;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_TiraLineas();
	C_TiraLineas(sf::Vector2f a, sf::Vector2f b);
	void nuevoVertice(sf::Vector2f vertice);
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest();
	~C_TiraLineas();
};

