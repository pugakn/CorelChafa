#include "stdafx.h"
#include "C_Capa.h"


int C_Capa::GetCLSID()
{
	return ClassID_Capa;
}

void C_Capa::Guardar(ofstream & out)
{
	out << ClassID_Capa << endl;
	out << Figuras.size() << endl;
	out << Bloqueado << endl;
	out << Visible << endl;

	for (list<C_Figura*>::iterator it = Figuras.begin(); it != Figuras.end(); ++it)
	{
		(*it)->Guardar(out);
	}

	

	out.close();
}

void C_Capa::Cargar(ifstream & in)
{
	string str;
	int ID = ClassID_Capa;

	getline(in, str);
	ID = stoi(str);
	getline(in, str);
	int size = stoi(str);

	getline(in, str);
	Bloqueado = stoi(str);
	getline(in, str);
	Visible = stoi(str);

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
