#pragma once
#include "C_Figura.h"
#define ClassID_TiraLineas 8

class C_TiraLineas : public C_Figura
{
public:
	sf::Vector2f _a, _b;
	sf::VertexArray _shape;
	std::vector<sf::Vector2f> _originalPos;
	std::vector<float> _angulos;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();

	C_TiraLineas();
	C_TiraLineas(sf::Vector2f a, sf::Vector2f b);
	void nuevoVertice(sf::Vector2f vertice);
	//void setLastVertexPos(sf::Vector2f vertice);
	void setColorRelleno(sf::Color color) override;
	void setColorLinea(sf::Color color) override;
	bool setPosicion(sf::Vector2f vector) override;
	void setSize(sf::Vector2f size) override;
	bool HitTest(sf::Vector2i point) override;
	void Dibujar(sf::RenderWindow& window) override;
	void SetLastPointPosition(sf::Vector2f size);
	~C_TiraLineas();
};

