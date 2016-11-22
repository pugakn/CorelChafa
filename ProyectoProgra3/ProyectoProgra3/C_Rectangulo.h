#pragma once
#include "C_Figura.h"
#define ClassID_Rectangulo 5

class C_Rectangulo : public C_Figura
{
public:
	//C_rectangulo();
	float _base1, _alt1;
	sf::VertexArray _shape;
	sf::VertexArray _linea;
public:
	//Guardar Cargar
	sf::RectangleShape rectangulo;
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	//C_Rectangulo(); //float base1, float alt1
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest();
	C_Rectangulo();
	//{
	//	sf::RectangleShape rectangulo;
	//	rectangulo.setSize(sf::Vector2f(100, 50));
	//	rectangulo.setPosition(10, 20); 
	//}
	~C_Rectangulo();
};

