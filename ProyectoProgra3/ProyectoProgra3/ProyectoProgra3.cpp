// ProyectoProgra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "C_Triangulo.h"
#include "C_Curva.h"
#include "C_Elipse.h"
#include "C_Linea.h"
#include "C_TiraLineas.h"
#include "C_Capa.h"
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tocino hiperespacial");
	/*sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	//C_Linea lineatest(sf::Vector2f(800.f, 600.f),sf::Vector2f(900.f,700.f));
	C_Elipse figuratest(200.f, 100.f);
	C_Triangulo test(200.f,500.f);
	C_Curva testcur(sf::Vector2f(0,100),sf::Vector2f(300,200),sf::Vector2f(0,150),sf::Vector2f(300,150));
	test.setColorRelleno(sf::Color::Red);
	//test.setPosicion(sf::Vector2f(500,500));
	C_TiraLineas tiralineas(sf::Vector2f(800.f, 600.f), sf::Vector2f(900.f, 700.f));
	tiralineas.nuevoVertice(sf::Vector2f(10, 10));
	tiralineas.setColorLinea(sf::Color::Red);
	testcur.setPosicion(sf::Vector2f(500,500));
	tiralineas.setPosicion(sf::Vector2f(100,100));
	C_Poligono poli(5,50);
	C_Capa cpa;
	cpa.InsertarTriangulo(200.f, 500.f);
	/*cpa.InsertarTriangulo(150, 600);
	cpa._figuraActual = cpa.Figuras.back();
	cpa.InsertarTriangulo(100, 800);
	cpa._figuraActual = cpa.Figuras.back();
	cpa.Figuras.back()->setColorRelleno(sf::Color::Red);
	//cpa.Subir();
	//cpa.Eliminar();
	C_TiraLineas tiral(sf::Vector2f(0,0), sf::Vector2f(500,500));
	tiral.nuevoVertice(sf::Vector2f(200,800));
	poli.setPosicion(sf::Vector2f(500, 500));
	C_Curva testcur(sf::Vector2f(0, 100), sf::Vector2f(300, 200), sf::Vector2f(0, 150), sf::Vector2f(300, 150));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		for (auto &item : cpa.Figuras) {
			window.draw(((C_Triangulo*)item)->_shape);
			item->HitTest(sf::Mouse::getPosition(window));
		}
		window.draw(tiral._shape);
		window.draw(testcur._vertices);
		testcur.HitTest(sf::Mouse::getPosition(window));
		//tiral.HitTest(sf::Mouse::getPosition(window));
		/*window.draw(test._shape);
		window.draw(test._linea);
		window.draw(testcur._vertices);
		window.draw(figuratest._shape);
		window.draw(tiralineas._shape);
		window.display();
	}*/

	C_Capa capa1;
	//ofstream File("Archivo.txt");
	ifstream Cargar;
	Cargar.open("Archivo.txt", ios::in);
	string str;
	
	/*C_Poligono piligonotest(5, 50);
	piligonotest.setColorLinea(sf::Color::Red);
	piligonotest.setColorRelleno(sf::Color::Blue);
	piligonotest.setPosicion(sf::Vector2f(500, 500));*/
	/*capa1.Visible = true;
	capa1.Bloqueado = false;
	capa1.InsertarPoligono(5, 50);
	capa1.Figuras.back()->setColorLinea(sf::Color::Red);
	capa1.Figuras.back()->setColorRelleno(sf::Color::Blue);
	capa1.Figuras.back()->setPosicion(sf::Vector2f(500, 500));
	capa1.Figuras.back()->Visible = true;
	capa1.Figuras.back()->Bloqueado = false;*/

	while (getline(Cargar, str))
	{
		cout << str << endl;

		if (stoi(str) == ClassID_Capa)
		{
			capa1.Cargar(Cargar);
		}
	}
	

	/*if (File.is_open())
	{
		capa1.Guardar(File);
		File.close();
	}*/


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(((C_Poligono*)capa1.Figuras.back())->_shape);
		
		window.display();
		}
    return 0;
}

