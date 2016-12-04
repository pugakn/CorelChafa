#pragma once
#include "C_Rectangulo.h"
#define ClassID_RRedondeado 6

class C_RRedondeado : public C_Rectangulo
{
public: //private
	float _base, _altura;
	float radius;
	sf::ConvexShape _shape;
	std::vector<sf::Vector2f> _originalpos;
public:
	sf::RectangleShape _shape;
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();

	C_RRedondeado(float base, float altura);
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
	bool setPosicion(sf::Vector2f vector);
	bool HitTest(sf::Vector2i point);
	C_RRedondeado();
	~C_RRedondeado();
};
