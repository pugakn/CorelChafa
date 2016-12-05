#include "stdafx.h"
#include "C_Capa.h"
#include "C_Documento.h"
#include "OptionsBar.h"

void C_Capa::Eliminar()
{
	if (_figuraActual != nullptr) {
		if (!_figuraActual->Bloqueado) {
			Figuras.remove(_figuraActual);
			delete _figuraActual;
			if (Figuras.size() > 0)
				_figuraActual = Figuras.back();
			else
				_figuraActual = nullptr;
			C_Documento::Instance()->Notify();
		}
	}
}

void C_Capa::Subir()
{
	if (_figuraActual != nullptr) {
		if (!_figuraActual->Bloqueado) {
			auto it = Figuras.begin();
			for (; it != Figuras.end(); ++it) {
				if (*it == _figuraActual) {
					break;
				}
			}
			auto it2 = it;
			if (it2 != Figuras.end()) {
				it2++;
				if (it2 != Figuras.end())
					Figuras.splice(it, Figuras, it2);
			}
			C_Documento::Instance()->Notify();
		}
	}
	
}

void C_Capa::Bajar()
{
	if (_figuraActual != nullptr) {
		if (!_figuraActual->Bloqueado) {
			auto it = Figuras.begin();
			for (; it != Figuras.end(); ++it) {
				if (*it == _figuraActual) {
					break;
				}
			}
			auto it2 = it;
			if (it2 != Figuras.begin()) {
				it2--;
				if (it2 != Figuras.end())
					Figuras.splice(it2, Figuras, it);
			}
			C_Documento::Instance()->Notify();
		}
	}
}

int C_Capa::GetCLSID()
{
	return ClassID_Capa;
}

void C_Capa::Guardar(ofstream & out)
{
	out << GetCLSID() << endl;
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
		if (item->Visible)
			item->Dibujar(window);
	}
}

bool C_Capa::HitTest(sf::Vector2i point)
{
	for (auto &item : Figuras) {
		if (item->HitTest(point)) return true;
	}
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

void C_Capa::InsertarRectangulo(float base, float altura, string type, long id)
{
	Figuras.push_back(new C_Rectangulo(base,altura));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarRectanguloRed(float base, float altura, string type, long id)
{
	Figuras.push_back(new C_RRedondeado(base, altura));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	SetActual(Figuras.back());
	_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarTriangulo(float l1, float l2, string type, long id)
{
	Figuras.push_back(new C_Triangulo(l1,l2));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarLinea(sf::Vector2f a, sf::Vector2f b, string type, long id)
{
	Figuras.push_back(new C_Linea(a, b));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	//_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarTiraDeLineas(sf::Vector2f a, sf::Vector2f b, string type, long id)
{
	Figuras.push_back(new C_TiraLineas(a, b));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	//_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarElipse(float ra, float rb, string type, long id)
{
	Figuras.push_back(new C_Elipse(ra, rb));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarCurva(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f c1, sf::Vector2f c2, string type, long id)
{
	Figuras.push_back(new C_Curva(p1, p2, c1, c2));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	//_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}

void C_Capa::InsertarPoligono(int lados, float radio,  string type, long id)
{
	Figuras.push_back(new C_Poligono(lados, radio));
	Figuras.back()->setType(type);
	Figuras.back()->setID(id);
	_figuraActual = Figuras.back();
	_figuraActual->setColorRelleno(OptionsBar::Instance()->_colorPicker.getFillColor());
	_figuraActual->setColorLinea(OptionsBar::Instance()->_colorPicker.getLineColor());
	C_Documento::Instance()->Notify();
}
// TODO: SetBolqueado para todas las figuras
// TODO: Error al eliminar capa por figura actual
