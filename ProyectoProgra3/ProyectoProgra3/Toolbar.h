#pragma once
#include "sfButton.h"
#include <vector>
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
	static Toolbar* Instance();
	void Draw(sf::RenderWindow&);
	void Update(sf::Event& event, sf::RenderWindow& window);
	~Toolbar();
};

