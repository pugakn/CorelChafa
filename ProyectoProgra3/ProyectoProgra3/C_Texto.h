#pragma once
#include "C_Figura.h"
#define ClassID_Texto 7

class C_Texto : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Texto();
	~C_Texto();
};

