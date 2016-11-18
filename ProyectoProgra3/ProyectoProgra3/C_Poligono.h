#pragma once
#include "C_Figura.h"
#define ClassID_Poligono 4

class C_Poligono : public C_Figura
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Poligono();
	~C_Poligono();
};

