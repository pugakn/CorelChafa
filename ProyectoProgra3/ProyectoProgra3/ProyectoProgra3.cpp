// ProyectoProgra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "C_Triangulo.h"
#include "C_Curva.h"
#include "C_Elipse.h"
#include "C_Linea.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Tocino hiperespacial");
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);
	C_Linea lineatest(sf::Vector2f(800.f, 600.f),sf::Vector2f(900.f,700.f));
	C_Elipse figuratest(200.f, 100.f);
	C_Triangulo test(200.f,500.f);
	C_Curva testcur(sf::Vector2f(0,100),sf::Vector2f(300,200),sf::Vector2f(0,150),sf::Vector2f(300,150));
	test.setColorRelleno(sf::Color::Red);
	//test.setPosicion(sf::Vector2f(500,500));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(test._shape);
		window.draw(test._linea);
		window.draw(testcur._vertices);
		window.draw(figuratest._shape);
		window.display();
	}
    return 0;
}

