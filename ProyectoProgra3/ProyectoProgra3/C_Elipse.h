#pragma once
#include "C_Figura.h"
#define ClassID_Elipse 2

class C_Elipse : public C_Figura
{
public:
	float _ra, _rb;
	sf::VertexArray _shape;
	sf::Vector2f _centro;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();

	C_Elipse(float ra, float rb);
	void setColorRelleno(sf::Color color) override;
	void setColorLinea(sf::Color color) override;
	bool setPosicion(sf::Vector2f vector) override;
	void setSize(sf::Vector2f size) override;
	bool HitTest(sf::Vector2i point) override;
	void Dibujar(sf::RenderWindow& window) override;
	C_Elipse();
	~C_Elipse();
};

std::vector <sf::Vector2f> CaclVertex(float ra, float rb);