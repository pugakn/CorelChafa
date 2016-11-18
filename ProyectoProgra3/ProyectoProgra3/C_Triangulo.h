#pragma once
#include "C_Figura.h"
#include <SFML\Graphics\VertexArray.hpp>
#define ClassID_Triangulo 9

class C_Triangulo : public C_Figura
{
public:
	sf::VertexArray _shape;
	sf::VertexArray _linea;
	float _l1, _l2;
public:
	C_Triangulo();
	C_Triangulo(float l1, float l2);
	~C_Triangulo();
	bool setPosicion(sf::Vector2f posicion);
	int GetClassID();
	void Guardar();
	void Cargar();
	bool HitTest();
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
};

