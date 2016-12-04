#include "stdafx.h"
#include "ColorPicker.h"
#include "C_Documento.h"


sf::Color ColorPicker::getLineColor()
{
	return _lineColor;
}

sf::Color ColorPicker::getFillColor()
{
	return _fillColor;
}

void ColorPicker::Draw(sf::RenderWindow& window)
{
	window.draw(_lineColorB);
	window.draw(_fillColorB);
	window.draw(_spectrum);
}

void ColorPicker::Inputs(sf::Event & event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::MouseButtonPressed) {

		if (_lineColorB.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
		{
			_fillColorSelected = false;
			_lineColorB.setOutlineThickness(2);
			_lineColorB.setOutlineColor(sf::Color::Red);
			_fillColorB.setOutlineThickness(0);
		}
		if (_fillColorB.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
		{
			_fillColorSelected = true;
			_fillColorB.setOutlineThickness(2);
			_fillColorB.setOutlineColor(sf::Color::Red);
			_lineColorB.setOutlineThickness(0);
		}
		if (_spectrum.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
			if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
				if (_fillColorSelected) {
					C_Documento::Instance()->_actual->_figuraActual->setColorRelleno(_image.getPixel(sf::Mouse::getPosition(window).x - _spectrum.getPosition().x, sf::Mouse::getPosition(window).y - _spectrum.getPosition().y));
					_fillColorB.setFillColor(_image.getPixel(sf::Mouse::getPosition(window).x - _spectrum.getPosition().x, sf::Mouse::getPosition(window).y - _spectrum.getPosition().y));
				}
				else {
					C_Documento::Instance()->_actual->_figuraActual->setColorLinea(_image.getPixel(sf::Mouse::getPosition(window).x - _spectrum.getPosition().x, sf::Mouse::getPosition(window).y - _spectrum.getPosition().y));
					_lineColorB.setFillColor(_image.getPixel(sf::Mouse::getPosition(window).x - _spectrum.getPosition().x, sf::Mouse::getPosition(window).y - _spectrum.getPosition().y));
				}
		}
	}

}

void ColorPicker::SetPosition(sf::Vector2f position)
{
	_lineColorB.setPosition(sf::Vector2f(position.x, position.y ));
	_fillColorB.setPosition(sf::Vector2f(position.x, position.y + 45));
	_spectrum.setPosition(sf::Vector2f(position.x + 30, position.y));
}

ColorPicker::ColorPicker()
{
	_spectrumTexture.loadFromFile("Assets/spectrum.png");
	_spectrum.setTexture(&_spectrumTexture,true);
	_spectrum.setSize(sf::Vector2f(641,71));
	_fillColorB.setSize(sf::Vector2f(25,25));
	_lineColorB.setSize(sf::Vector2f(25, 25));
	//_lineColorB.LoadTexture
	_image.loadFromFile("Assets/spectrum.png");
	SetPosition(sf::Vector2f(0,0));
	_fillColorB.setOutlineThickness(2);
	_fillColorB.setOutlineColor(sf::Color::Red);
}


ColorPicker::~ColorPicker()
{
}
