#include "stdafx.h"
#include "InfoBar.h"
#include "C_Documento.h"

InfoBar* InfoBar::_instance = 0;

InfoBar * InfoBar::Instance()
{

	if (_instance == 0) {
		_instance = new InfoBar;
	}
	return _instance;

}


void InfoBar::Update()
{
	//TODO: Sólo cuando haya cambios en posicion, color,etc...
	if (_actual != C_Documento::Instance()->_actual->_figuraActual && C_Documento::Instance()->_actual->_figuraActual != nullptr) {
		_actual = C_Documento::Instance()->_actual->_figuraActual;
		_positionString = "POSICION: [" + to_string(_actual->getPosicion().x)
			+ "," + to_string(_actual->getPosicion().y) + "]";
		_positionTXT.setString(_positionString);
		_idString = "FIGURA: " + _actual->getType() +" " + to_string(_actual->getID());
		_idText.setString(_idString);

	}
}

void InfoBar::Draw(sf::RenderWindow &window)
{
	window.draw(_background);
	window.draw(_positionTXT);
	window.draw(_idText);
}

void InfoBar::Inputs(sf::Event & event, sf::RenderWindow & window)
{
}

InfoBar::InfoBar()
{
	C_Documento::Instance()->Attach(*this); //Attach to subject
	_ItemsPosition = sf::Vector2f(60, 690);
	_background.setPosition(50, 668);
	_background.setSize(sf::Vector2f(1400, 100));
	_background.setFillColor(sf::Color(115, 108, 121));
	_font.loadFromFile("Assets/Calibri.ttf");

	_idText.setFont(_font);
	_idText.setString(_positionString);
	_idText.setFillColor(sf::Color::White);
	_idText.setCharacterSize(24);
	_idText.setPosition(_ItemsPosition);

	_positionTXT.setFont(_font);
	_positionTXT.setString(_positionString);
	_positionTXT.setFillColor(sf::Color::White);
	_positionTXT.setCharacterSize(24);
	_positionTXT.setPosition(_ItemsPosition + sf::Vector2f(0,25));


}


InfoBar::~InfoBar()
{
}
