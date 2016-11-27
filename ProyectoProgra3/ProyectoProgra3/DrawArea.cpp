#include "stdafx.h"
#include "DrawArea.h"

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
	static sf::Vector2f initialPos;
	static sf::Vector2f deltPos;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (_drawAreaLimits.contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
			initialPos = (sf::Vector2f)sf::Mouse::getPosition(window);
			_buttonClicked = true;
			_documento._actual->InsertarPoligono(5, 50);
			_documento._actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
			_documento._actual->Figuras.back()->setColorRelleno(_fillColor);
			_documento._actual->Figuras.back()->setColorLinea(_borderColor);
		}

	}
	if (event.type == sf::Event::MouseButtonReleased) {
		_buttonClicked = false;
	}
	if (event.type == sf::Event::MouseMoved) {
		if (_buttonClicked) {
			deltPos = (sf::Vector2f)sf::Mouse::getPosition(window) - initialPos;
			_documento._actual->Figuras.back()->setSize(deltPos);
		}
	}

}

DrawArea::~DrawArea()
{
}
