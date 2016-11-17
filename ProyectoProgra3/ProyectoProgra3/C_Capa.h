#pragma once
#include <list>
#include "C_Seleccionable.h"
#include "C_Figura.h"

class C_Capa : public C_Seleccionable
{
	list<C_Figura *> Figuras;
	C_Figura * Figura_Actual;
public:
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();
	C_Capa();
	~C_Capa();
};

