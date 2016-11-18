#pragma once
#include "C_Figura.h"
#define ClassID_Elipse 2

class C_Elipse : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Elipse();
	~C_Elipse();
};

