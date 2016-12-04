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
	std::vector<sf::Vector2f> _originalPos;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();

	C_Triangulo();
	C_Triangulo(float l1, float l2);
	~C_Triangulo();
	bool setPosicion(sf::Vector2f posicion);
	bool HitTest(sf::Vector2i point);
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	void setSize(sf::Vector2f size);
	void Dibujar(sf::RenderWindow& window);
};

