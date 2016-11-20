#include "stdafx.h"
#include "C_Capa.h"


void C_Capa::Insertar(int ClsID)
{
	Figuras.push_back(FigurasFactoy(ClsID));
}

void C_Capa::Eliminar(C_Figura* item)
{
	Figuras.remove(item);
	delete item;
}

void C_Capa::Subir()
{
	auto it = Figuras.begin();
	for (; it != Figuras.end(); ++it) {
		if (*it == _figuraActual) {
			break;
		}
	}
	auto it2 = it;
	it2++; //Puede dar error
	Figuras.splice(it2, Figuras, it);
}

void C_Capa::Bajar()
{
	auto it = Figuras.begin();
	for (; it != Figuras.end(); ++it) {
		if (*it == _figuraActual) {
			break;
		}
	}
	auto it2 = it;
	it2--; //Puede dar error
	Figuras.splice(it2, Figuras, it);
}

int C_Capa::GetCLSID()
{
	return ClassID_Capa;
}

void C_Capa::Guardar(ofstream & out)
{
	out << ClassID_Capa << endl;

	for (list<C_Figura*>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
	{
		(*it)->Guardar(out);
	}

	out.close();
}

void C_Capa::Cargar(ifstream & in)
{
	string str;
	getline(in, str);
	int size = stoi(str);
	for (int i = 0; i < size; i++)
	{
		getline(in, str);
		C_Figura *newItem;
		newItem = FigurasFactoy(stoi(str));
		if (newItem)
		{
			newItem->Cargar(in);
			Figuras.push_back(newItem);
		}

	}
}

C_Capa::C_Capa()
{
}


C_Capa::~C_Capa()
{
}
