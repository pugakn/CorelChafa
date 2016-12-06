#pragma once
#include "C_Dibujable.h"
#include "C_Capa.h"
#include "Subject.h"
#define ClassID_Documento 11
class C_Documento : public Subject
{
private:
	static C_Documento* _instance;
	friend class LayerBar;
	friend class InfoBar;
	friend class DrawArea;
	friend class OptionsBar;
	friend class ColorPicker;
	friend class C_Capa;
	std::list<C_Capa*> _lista;
	C_Capa* _actual;
protected:
	C_Documento();
public:
	void Insertar(int ID);
	void Eliminar();
	void Subir();
	void Bajar();
	//Guardar Cargar
	int GetCLSID();
	void Guardar(ofstream &out);
	void Cargar(ifstream &in);
	std::list<C_Capa*> _lista;
	C_Capa* _actual;

	void Inicializar();
	void Dibujar(sf::RenderWindow& window);
	void SetActual(C_Capa*);

	void Attach(Observer& observer);
	void Detach(Observer& observer);
	void Notify();
	~C_Documento();

	static C_Documento* Instance();
	
};

