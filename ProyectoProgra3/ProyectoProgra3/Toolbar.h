#pragma once
#include "sfButton.h"
#include <vector>
#include "DrawArea.h"
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
	sf::Texture _backgroundTexture;
protected:
	Toolbar();
public:
	static int Poliwindow();
	int _polilados;
	static Tools _actualTool;
	static Toolbar* Instance();
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~Toolbar();
};


