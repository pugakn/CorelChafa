#include "stdafx.h"
#include "C_Capa.h"



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

bool C_Capa::HitTest()
{
	return false;
}

C_Capa::C_Capa()
{
}


C_Capa::~C_Capa()
{
}

void C_Capa::InsertarTriangulo(float l1, float l2)
{
	Figuras.push_back(new C_Triangulo(l1,l2));
}

void C_Capa::InsertarTiraDeLineas(sf::Vector2f a, sf::Vector2f b)
{
	Figuras.push_back(new C_TiraLineas(a, b));
}

void C_Capa::InsertarElipse(float ra, float rb)
{
	Figuras.push_back(new C_Elipse(ra, rb));
}

void C_Capa::InsertarCurva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2)
{
	Figuras.push_back(new C_Curva(p1, p2, c1, c2));
}

void C_Capa::InsertarPoligono(int lados, float radio)
{
	Figuras.push_back(new C_Poligono(lados, radio));
}
