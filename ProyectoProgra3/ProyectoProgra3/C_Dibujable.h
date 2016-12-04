#pragma once
#include <list>
#include <fstream>
#include <SFML\Graphics.hpp>
using namespace std;

class C_Dibujable
{
public:
	virtual int GetCLSID() = 0;
	virtual void Guardar(ofstream &out) = 0;
	virtual void Cargar(ifstream &in) = 0;
	virtual void Inicializar() = 0;
	virtual void Dibujar(sf::RenderWindow& window) = 0;
};
