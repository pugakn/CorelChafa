#pragma once
#include "C_Figura.h"
#define ClassID_Rectangulo 5

class C_Rectangulo : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Rectangulo();
	~C_Rectangulo();
};

