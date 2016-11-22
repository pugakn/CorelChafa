#pragma once
#include "C_Dibujable.h"
#include "C_Capa.h"
class C_Documento : public C_Dibujable
{
private:
	std::list<C_Capa*> _lista;
	C_Capa* _actual;
public:
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	//Guardar Cargar
	C_Documento();
	~C_Documento();
};

