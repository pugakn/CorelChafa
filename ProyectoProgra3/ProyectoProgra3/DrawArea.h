#pragma once
#include <SFML\Graphics.hpp>
#include "C_Documento.h"
class DrawArea
{
protected:
	DrawArea();
	sf::FloatRect _drawAreaLimits;
private:
	C_Documento _documento;
	sf::Color _fillColor = sf::Color::Black;
	sf::Color _borderColor = sf::Color::Black;
	static DrawArea* _instance;
	bool _buttonClicked{false};
public:
	static DrawArea* Instance();
	void Draw(sf::RenderWindow& window);
	void Update(sf::Event& event, sf::RenderWindow& window);
	~DrawArea();
};

