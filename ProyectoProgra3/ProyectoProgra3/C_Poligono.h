#pragma once
#include "C_Figura.h"
#define ClassID_Poligono 4

class C_Poligono : public C_Figura
{
private:
	int _lados;
	float _radio;
	sf::CircleShape _shape;
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Poligono();
	C_Poligono(int lados, float radio);
	~C_Poligono();
	bool setPosicion(sf::Vector2f posicion);
	bool HitTest();
	void setColorRelleno(sf::Color color);
	void setColorLinea(sf::Color color);
};

