#pragma once
#include <list>
#include "C_Seleccionable.h"
#include "C_Figura.h"
#include "Factory.h"
#define ClassID_Capa 10

class C_Capa : public C_Seleccionable
{
	list<C_Figura *> Figuras;
	C_Figura * Figura_Actual;
public:
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Capa();
	~C_Capa();
};

