#include "stdafx.h"
#include "OptionsBar.h"

OptionsBar* OptionsBar::_instance = 0;

OptionsBar * OptionsBar::Instance()
{

	if (_instance == 0) {
		_instance = new OptionsBar;
	}
	return _instance;

}
void OptionsBar::Update()
{
}
OptionsBar::OptionsBar()
{
	_background.setSize(sf::Vector2f(1366, 124));
	_background.setFillColor(sf::Color(18, 49, 62));
}


void OptionsBar::Draw(sf::RenderWindow &window)
{
	window.draw(_background);
}

void OptionsBar::Inputs(sf::Event & event, sf::RenderWindow & window)
{
}

OptionsBar::~OptionsBar()
{
}
