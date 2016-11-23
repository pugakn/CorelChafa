#pragma once
#include <list>
#include "C_Seleccionable.h"
#include "C_Figura.h"
#include "Factory.h"
#define ClassID_Capa 10

class C_Capa : public C_Seleccionable
{
public: //private
	int ID;
	list<C_Figura *> Figuras;
	C_Figura * _figuraActual;
public:
	//void InsertarRectangulo();
	//void InsertarRectanguloRed();
	void InsertarTriangulo(float l1, float l2);
	//void InsertarLinea();
	void InsertarTiraDeLineas(sf::Vector2f a, sf::Vector2f b);
	void InsertarElipse(float ra, float rb);
	void InsertarCurva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2);
	void InsertarPoligono(int lados, float radio);
	//void InsertarTexto();

	void Eliminar();
	void Subir();
	void Bajar();
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();

	bool HitTest(sf::Vector2i point);
	C_Capa();
	~C_Capa();
};

