#include "stdafx.h"
#include "sfTextButton.h"




sfTextButton::sfTextButton(std::string text, sf::Font& font)
{
	_string = text;
	_font = font;
	_txt.setFont(font);
	_txt.setString(_string);
}

sfTextButton::~sfTextButton()
{
}
