#pragma once
#include <list>

using namespace std;

class C_Dibujable
{
public:
	virtual int GetClassID() = 0;
	virtual void Guardar() = 0;
	virtual void Cargar() = 0;
};
