#pragma once
#include "C_Figura.h"
#define ClassID_Curva 1

class C_Curva : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Curva();
	~C_Curva();
};

