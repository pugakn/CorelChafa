#pragma once
#include <SFML\Graphics.hpp>
#include "C_Documento.h"
class DrawArea
{
protected:
	DrawArea();
	sf::FloatRect _drawAreaLimits;
private:
	long _triangleID = 0;
	long _elipseID = 0;
	long _tlineasID = 0;
	long _curvaID = 0;
	long _poligonoID = 0;
	long _rectID = 0;
	long _rRectID = 0;
	long _lineaID = 0;
	C_Documento* _documento;
	sf::Color _fillColor = sf::Color::Black;
	sf::Color _borderColor = sf::Color::Red;
	static DrawArea* _instance;
	bool _buttonClicked{false};
public:
	static DrawArea* Instance();
	void Draw(sf::RenderWindow& window);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~DrawArea();
};

