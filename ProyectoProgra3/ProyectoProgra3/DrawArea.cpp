#include "stdafx.h"
#include "DrawArea.h"
#include "Toolbar.h"

DrawArea* DrawArea::_instance = 0;
DrawArea::DrawArea()
{
	_drawAreaLimits.top = 136;
	_drawAreaLimits.left = 50;
	_drawAreaLimits.height = 600;
	_drawAreaLimits.width = 1024;

	//Inicializar documento
	_documento.Inicializar();


}


DrawArea * DrawArea::Instance()
{
	if (_instance == 0) {
		_instance = new DrawArea;
	}
	return _instance;
}

void DrawArea::Draw(sf::RenderWindow & window)
{
	_documento.Dibujar(window);
}

void DrawArea::Update(sf::Event & event, sf::RenderWindow & window)
{
	static bool first = true;//TODO: Fix
	static sf::Vector2f initialPos;
	static sf::Vector2f deltPos;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (_drawAreaLimits.contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
			switch (Toolbar::_actualTool)
			{
			case Tools::CURSOR:
				break;
			case Tools::CURVA:
				break;
			case Tools::ELIPSE:
				_documento._actual->InsertarElipse(50,50);
				break;
			case Tools::LINEA:
				break;
			case Tools::POLIGONO:
				_documento._actual->InsertarPoligono(5, 50);
				break;
			case Tools::RECTANGULO:
				break;
			case Tools::RREDONDEADO:
				break;
			case Tools::TEXTO:
				break;
			case Tools::TIRA:
			{
				if (first) {
					_documento._actual->InsertarTiraDeLineas((sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window));
					first = false;
				}
				else {
					((C_TiraLineas*)_documento._actual->Figuras.back())->nuevoVertice((sf::Vector2f)sf::Mouse::getPosition(window));
				}
			}
				break;
			case Tools::TRIANGULO:
				_documento._actual->InsertarTriangulo(50, 50);
				break;
			default:
				break;
			}
			if (Toolbar::_actualTool != Tools::CURSOR) {
				
				_buttonClicked = true;
				_documento._actual->Figuras.back()->setColorRelleno(_fillColor);
				_documento._actual->Figuras.back()->setColorLinea(_borderColor);
				if (Toolbar::_actualTool != Tools::TIRA) {
					initialPos = (sf::Vector2f)sf::Mouse::getPosition(window);
					_documento._actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
				}
			}
		}

	}
	if (event.type == sf::Event::MouseButtonReleased) {
		_buttonClicked = false;
	}
	if (event.type == sf::Event::MouseMoved) {
		if (Toolbar::_actualTool == Tools::TIRA && !first) {
			_documento._actual->Figuras.back()->setSize((sf::Vector2f)sf::Mouse::getPosition(window));
		}
		else
		if (_buttonClicked) {
			deltPos = (sf::Vector2f)sf::Mouse::getPosition(window) - initialPos;
			_documento._actual->Figuras.back()->setSize(deltPos);
			//_documento._actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
		}
	}

}

DrawArea::~DrawArea()
{
}
