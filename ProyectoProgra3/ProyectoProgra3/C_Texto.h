#pragma once
#include "C_Figura.h"
#define ClassID_Texto 7

class C_Texto : public C_Figura
{
public:
	sf::VertexArray _shape;
	sf::VertexArray _linea;
	sf::Text _texto;
	float _base2, _alt2;
	//Guardar Cargar
	sf::RectangleShape _rectangulo2;
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
	C_Texto(float base, float altura);
	~C_Texto();
};

