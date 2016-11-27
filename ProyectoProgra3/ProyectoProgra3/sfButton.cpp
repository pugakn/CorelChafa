#include "stdafx.h"
#include "sfButton.h"


void sfButton::onDown()
{

	Callback();
}

void sfButton::onHover()
{
	//_rectangle.setTexture(&_hoverTexture);
	_rectangle.setFillColor(sf::Color::Red);
}

void sfButton::onHoverExit()
{
	//_rectangle.setTexture(&_texture);
	_rectangle.setFillColor(sf::Color::White);
}

bool sfButton::HitTest(sf::Vector2i mousePos)
{
	if (mousePos.x > _rectangle.getPosition().x && mousePos.y > _rectangle.getPosition().y
		&& mousePos.x < _rectangle.getPosition().x + _rectangle.getSize().x
		&&  mousePos.y < _rectangle.getPosition().y + _rectangle.getSize().y) {
		return true;
	}
	return false;
}

bool sfButton::LoadTexture(std::string src)
{
	_texture.loadFromFile(src);
	_rectangle.setTexture(&_texture,true);
	return true; //
}

bool sfButton::LoadHoverTexture(std::string src)
{
	return _hoverTexture.loadFromFile(src);
}

sfButton::sfButton()
{

}


sfButton::~sfButton()
{
}
