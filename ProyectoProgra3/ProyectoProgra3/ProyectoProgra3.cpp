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
#include "DrawArea.h"
#include "C_Documento.h"
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Tocino hiperespacial",sf::Style::Close);
	window.setFramerateLimit(60);
	C_Documento* document = C_Documento::Instance();

	Toolbar* toolbar = Toolbar::Instance();
	DrawArea* drawArea = DrawArea::Instance();
	InfoBar* infoBar = InfoBar::Instance();
	OptionsBar* optionsBar = OptionsBar::Instance();
	LayerBar* layerBar = LayerBar::Instance();;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			//if (event.type == sf::Event::Resized)
				//window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			if (event.type == sf::Event::Closed)
				window.close();
			/********************* Inputs********************/
			toolbar->Inputs(event, window);
			drawArea->Inputs(event, window);
			optionsBar->Inputs(event,window);
			layerBar->Inputs(event,window);
			/***********************************************/
		}
		window.clear(sf::Color::White);
		/**********Dibijar**********/
		drawArea->Draw(window);
		toolbar->Draw(window);
		infoBar->Draw(window);
		layerBar->Draw(window);
		optionsBar->Draw(window);
		/***************************/
		window.display();
		}
    return 0;
}

