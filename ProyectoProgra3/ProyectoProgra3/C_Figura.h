#pragma once
#include "C_Seleccionable.h"

class C_Figura : public C_Seleccionable
{
public:
	bool Seleccionado;
	long ID;
	C_Figura();
	~C_Figura();
	//RBG_Triple Color_Relleno;
	//Point Posicion;
	//RGB_Triple Color_Linea;
	//Set o Get Accesores necesarios
};