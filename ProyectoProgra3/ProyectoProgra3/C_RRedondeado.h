#pragma once
#include "C_Rectangulo.h"
#define ClassID_RRedondeado 6

class C_RRedondeado : public C_Rectangulo
{
public:
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_RRedondeado();
	~C_RRedondeado();
};

