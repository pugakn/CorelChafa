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
	void InsertarRectangulo(float base, float altura,string type, long id);
	void InsertarRectanguloRed(float base, float altura, string type, long id);
	void InsertarTriangulo(float l1, float l2, string type, long id);
	void InsertarLinea(sf::Vector2f a, sf::Vector2f b, string type, long id);
	void InsertarTiraDeLineas(sf::Vector2f a, sf::Vector2f b, string type, long id);
	void InsertarElipse(float ra, float rb, string type, long id);
	void InsertarCurva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2, string type, long id);
	void InsertarPoligono(int lados, float radio, string type, long id);
	void InsertarTexto(int size, string type, long id);

	void Eliminar();
	void Subir();
	void Bajar();
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	void Inicializar();
	void Dibujar(sf::RenderWindow& window);

	bool HitTest(sf::Vector2i point);
	void SetActual(C_Figura* actual);
	C_Capa();
	~C_Capa();
};

