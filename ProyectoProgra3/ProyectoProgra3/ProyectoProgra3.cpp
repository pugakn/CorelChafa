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
#include "C_RRedondeado.h"
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tocino hiperespacial");
	
	/*C_Poligono piligonotest(5, 50);
	piligonotest.setColorLinea(sf::Color::Red);
	piligonotest.setColorRelleno(sf::Color::Blue);
	piligonotest.setPosicion(sf::Vector2f(500, 500));*/
	C_RRedondeado Rtest(300, 500);
	Rtest.setColorRelleno(sf::Color::Red);
	Rtest.setColorLinea(sf::Color::Blue);
	Rtest.setPosicion(sf::Vector2f(500, 400));
	


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(Rtest._shape);
		Rtest.HitTest(sf::Mouse::getPosition(window));
		window.display();
		}
    return 0;
}

