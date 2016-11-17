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

class C_Seleccionable : public C_Dibujable
{
public:
	bool Bloqueado;
	bool Visible;
	virtual bool HitTest() = 0;
};

class C_Figura : public C_Seleccionable
{
public:
	bool Seleccionado;
	long ID;
	//RBG_Triple Color_Relleno;
	//Point Posicion;
	//RGB_Triple Color_Linea;
	//Set o Get Accesores necesarios
};

class C_Capa : public C_Seleccionable
{
	list<C_Figura> Figuras;
	C_Figura * Figura_Actual;
public:
	void Insertar();
	void Eliminar();
	void Subir();
	void Bajar();
};

class C_Documento : public C_Dibujable
{
	list<C_Capa> Capas;
	C_Capa * Capa_Actual;
	int ClassID;
};