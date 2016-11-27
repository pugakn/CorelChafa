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
#include "sfButton.h"
#include "Toolbar.h"
#include "OptionsBar.h"
#include "LayerBar.h"
#include "InfoBar.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Tocino hiperespacial");
	Toolbar* toolbar = Toolbar::Instance();
	OptionsBar optionsBar;
	LayerBar layerBar;
	InfoBar infoBar;

	
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			toolbar->Update(event, window);

			if (event.type == sf::Event::MouseMoved) {

			}
			if (event.type == sf::Event::MouseButtonPressed) {

			}
		}
		window.clear(sf::Color::White);
		window.draw(optionsBar._background);
		window.draw(layerBar._background);
		window.draw(infoBar._background);

		toolbar->Draw(window);
		window.display();
		}
    return 0;
}

