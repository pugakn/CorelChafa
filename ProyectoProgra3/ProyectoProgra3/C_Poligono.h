#pragma once
#include "C_Figura.h"
#define ClassID_Poligono 4

class C_Poligono : public C_Figura
{
private:
	std::size_t  _lados;
	float _radio;
	sf::CircleShape _shape;
public:
	C_Poligono();
	C_Poligono(std::size_t  lados, float radio);
	~C_Poligono();
	bool setPosicion(sf::Vector2f posicion);
	int GetClassID();
	void Guardar();
	void Cargar();
	bool HitTest();
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
};

