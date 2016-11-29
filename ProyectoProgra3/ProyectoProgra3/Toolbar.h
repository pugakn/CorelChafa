#pragma once
#include "sfButton.h"
#include <vector>
enum Tools
{
	CURSOR,
	CURVA,
	ELIPSE,
	LINEA,
	POLIGONO,
	RECTANGULO,
	RREDONDEADO,
	TEXTO,
	TIRA,
	TRIANGULO
};

class Toolbar
{
private:
	static Toolbar* _instance;
	std::vector<sfButton*> _buttons;
	sf::RectangleShape _background;
	sf::Vector2f _ItemsPosition;
protected:
	Toolbar();
public:
	static Tools _actualTool;
	static Toolbar* Instance();
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~Toolbar();
};


