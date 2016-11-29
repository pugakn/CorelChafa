#include "stdafx.h"
#include "C_Documento.h"

C_Documento* C_Documento::_instance = 0;

void C_Documento::Inicializar()
{
	Insertar();
	_actual = _lista.back();
}

void C_Documento::Dibujar(sf::RenderWindow & window)
{
	for (auto &item : _lista) {
		item->Dibujar(window);
	}
}

void C_Documento::Attach(Observer & observer)
{
	_observers.push_back(&observer);
}

void C_Documento::Detach(Observer & observer)
{
	_observers.remove(&observer);
}

void C_Documento::Notify()
{
	for (auto &it : _observers) {
		it->Update();
	}
}

C_Documento::C_Documento()
{
}


C_Documento::~C_Documento()
{
}

C_Documento * C_Documento::Instance()
{
	if (_instance == 0) {
		_instance = new C_Documento;
	}
	return _instance;
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
