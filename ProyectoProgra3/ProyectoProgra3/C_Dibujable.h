#pragma once
#include <list>
#include <fstream>

using namespace std;

class C_Dibujable
{
public:
	virtual int GetCLSID() = 0;
	virtual void Guardar(ofstream &out) = 0;
	virtual void Cargar(ifstream &in) = 0;
};
