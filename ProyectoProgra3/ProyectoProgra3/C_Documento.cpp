#include "stdafx.h"
#include "C_Documento.h"

C_Documento* C_Documento::_instance = 0;

void C_Documento::Inicializar()
{
	Insertar(1);
	_actual = _lista.back();
}

void C_Documento::Dibujar(sf::RenderWindow & window)
{
	for (auto &item : _lista) {
		if (item->Visible)
			item->Dibujar(window);
	}
}

void C_Documento::SetActual(C_Capa *actual)
{
	_actual = actual;
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

void C_Documento::Insertar(int ID)
{
	_lista.push_back(new C_Capa());
	_lista.back()->ID = ID;
	//_actual = _lista.back();
	Notify();
}

void C_Documento::Eliminar()
{
	if (_lista.size()>1) {
		_lista.remove(_actual);
		delete _actual;
		_actual = _lista.back();
		Notify();
	}

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
	if (it2 != _lista.end()) {
		it2++;
		if (it2 != _lista.end())
			_lista.splice(it, _lista, it2);
		Notify();
	}

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
	if (it2 != _lista.begin()) {
		it2--;
		if (it2 != _lista.end())
			_lista.splice(it2, _lista, it);
		Notify();
	}

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
