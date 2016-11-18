#pragma once
#include "C_Figura.h"
#define ClassID_TiraLineas 8

class C_TiraLineas : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_TiraLineas();
	~C_TiraLineas();
};

