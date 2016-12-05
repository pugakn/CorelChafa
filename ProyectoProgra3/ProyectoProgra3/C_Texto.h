#pragma once
#include "C_Figura.h"
#define ClassID_Texto 7

class C_Texto : public C_Figura
{
public:
	sf::VertexArray _shape;
	sf::VertexArray _linea;
	//Guardar Cargar
	sf::RectangleShape rectangulo;
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest(sf::Vector2i point);
	void Dibujar(sf::RenderWindow& window) override;
	void Inicializar() override;
	C_Texto();
	~C_Texto();
};

