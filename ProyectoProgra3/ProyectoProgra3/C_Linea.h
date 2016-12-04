#pragma once
#include "C_Figura.h"
#define ClassID_Linea 3

class C_Linea : public C_Figura
{
public:
	sf::VertexArray _shape;
	sf::Vector2f _a, _b;
	std::vector<sf::Vector2f> _originalPos;
	float _pendiente, _angulo;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();
	void setColorRelleno(sf::Color color) override;
	void setColorLinea(sf::Color color) override;
	bool setPosicion(sf::Vector2f vector) override;
	bool HitTest(sf::Vector2i point) override;

	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest(sf::Vector2i point);
	void Dibujar(sf::RenderWindow& window);
	C_Linea(sf::Vector2f a, sf::Vector2f b);
	C_Linea();
	~C_Linea();
};

