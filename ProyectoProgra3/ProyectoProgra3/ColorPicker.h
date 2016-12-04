#pragma once
#include "SFML\Graphics.hpp"
#include "sfButton.h"
class ColorPicker
{
private:
	//sfButton _lineColorB;
	//sfButton _fillColorB;
	sf::RectangleShape _lineColorB;
	sf::RectangleShape _fillColorB;
	sf::RectangleShape _spectrum;
	sf::Color _lineColor{sf::Color::Red};
	sf::Color _fillColor{sf::Color::Black};
	sf::Texture _spectrumTexture;
	sf::Image _image;
	bool _fillColorSelected = true;
public:
	sf::Color getLineColor();
	sf::Color getFillColor();
	void Draw(sf::RenderWindow& window);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	void SetPosition(sf::Vector2f position);
	ColorPicker();
	~ColorPicker();
};

