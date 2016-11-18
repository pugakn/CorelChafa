#pragma once
#include "C_Figura.h"
#define ClassID_Triangulo 9

class C_Triangulo : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Triangulo();
	~C_Triangulo();
};

