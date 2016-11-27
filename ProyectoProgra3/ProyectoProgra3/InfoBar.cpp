#include "stdafx.h"
#include "InfoBar.h"


InfoBar::InfoBar()
{
	_background.setPosition(50, 668);
	_background.setSize(sf::Vector2f(1400, 100));
	_background.setFillColor(sf::Color(115, 108, 121));
}


InfoBar::~InfoBar()
{
}
