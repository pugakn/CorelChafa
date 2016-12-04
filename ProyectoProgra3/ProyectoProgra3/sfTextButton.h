#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include "sfButton.h"
class sfTextButton :
	public sfButton
{
private:
	std::string _string;
	sf::Font _font;
public:
	sf::Text _txt;
	sfTextButton(std::string text, sf::Font& font);
	~sfTextButton();
};

