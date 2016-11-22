#include "stdafx.h"
#include "C_Documento.h"


C_Documento::C_Documento()
{
}


C_Documento::~C_Documento()
{
}

void C_Documento::Insertar()
{
	_lista.push_back(new C_Capa());
}

void C_Documento::Eliminar()
{
	_lista.remove(_actual);
	delete _actual;
}

void C_Documento::Subir()
{
	auto it = _lista.begin();
	for (; it != _lista.end(); ++it) {
		if (*it == _actual) {
			break;
		}
	}
	auto it2 = it;
	it2++;
	if (it2 != _lista.end())
		_lista.splice(it2, _lista, it);
}

void C_Documento::Bajar()
{
	auto it = _lista.begin();
	for (; it != _lista.end(); ++it) {
		if (*it == _actual) {
			break;
		}
	}
	auto it2 = it;
	it2--;
	if (it2 != _lista.end())
		_lista.splice(it2, _lista, it);
}

int C_Documento::GetCLSID()
{
	return 0;
}

void C_Documento::Guardar(ofstream & out)
{
}

void C_Documento::Cargar(ifstream & in)
{
}
