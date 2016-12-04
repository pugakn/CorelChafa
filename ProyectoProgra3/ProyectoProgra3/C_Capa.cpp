#include "stdafx.h"
#include "C_Capa.h"
#include "C_Documento.h"



void C_Capa::Eliminar()
{
	Figuras.remove(_figuraActual);
	delete _figuraActual;
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
	it2++; 
	if (it2 != Figuras.end())
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
	it2--;
	if (it2 != Figuras.end())
		Figuras.splice(it2, Figuras, it);
}

int C_Capa::GetCLSID()
{
	return ClassID_Capa;
}

void C_Capa::Guardar(ofstream & out)
{
	out << ID << endl;
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
	int size;

	getline(in, str);
	ID = stoi(str);

	getline(in, str);
	size = stoi(str);

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

void C_Capa::Inicializar()
{
}

void C_Capa::Dibujar(sf::RenderWindow & window)
{
	for (auto &item : Figuras) {
		item->Dibujar(window);
	}
}

bool C_Capa::HitTest(sf::Vector2i point)
{
	return false;
}

void C_Capa::SetActual(C_Figura * actual)
{
	_figuraActual = actual;
	C_Documento::Instance()->Notify();
}

C_Capa::C_Capa()
{
}


C_Capa::~C_Capa()
{
}

void C_Capa::InsertarTriangulo(float l1, float l2, string type, long id)
{
	Figuras.push_back(new C_Triangulo(l1,l2));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarTiraDeLineas(sf::Vector2f a, sf::Vector2f b, string type, long id)
{
	Figuras.push_back(new C_TiraLineas(a, b));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarElipse(float ra, float rb)
{
	Figuras.push_back(new C_Elipse(ra, rb));
}

void C_Capa::InsertarCurva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2, string type, long id)
{
	Figuras.push_back(new C_Curva(p1, p2, c1, c2));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarPoligono(int lados, float radio,  string type, long id)
{
	Figuras.push_back(new C_Poligono(lados, radio));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	C_Documento::Instance()->Notify();
}
