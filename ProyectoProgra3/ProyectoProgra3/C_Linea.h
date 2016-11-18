#pragma once
#include "C_Figura.h"
#define ClassID_Linea 3

class C_Linea : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Linea();
	~C_Linea();
};

