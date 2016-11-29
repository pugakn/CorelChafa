#include "stdafx.h"
#include "LayerBar.h"
#include "C_Documento.h"

LayerBar* LayerBar::_instance = 0;

LayerBar * LayerBar::Instance()
{

	if (_instance == 0) {
		_instance = new LayerBar;
	}
	return _instance;

}

void LayerBar::Update()
{
	

	//TODO: Solo si es diferente
	//if (_figuras->size()!= C_Documento::Instance()->_actual->Figuras.size()) {
		_figuras = &C_Documento::Instance()->_actual->Figuras;
		_txtButtons.clear();
		sfTextButton* temp = new sfTextButton("Capa 1", _font);
		temp->_rectangle.setSize(sf::Vector2f(200, 25));
		temp->_rectangle.setPosition(_ItemsPosition);
		temp->_txt.setPosition(_ItemsPosition);
		temp->_txt.setCharacterSize(14);
		temp->_txt.setFillColor(sf::Color::Black);
		temp->Callback = []() {

		};
		_txtButtons.push_back(temp);
		for (auto &it : *_figuras) {
			temp = new sfTextButton(it->getType() + " " + to_string(it->getID()), _font);
			//temp->LoadTexture("Assets/ico_cursor.png");
			temp->_rectangle.setSize(sf::Vector2f(200, 25));
			temp->_rectangle.setPosition(_ItemsPosition.x, _txtButtons.back()->_rectangle.getPosition().y + _txtButtons.back()->_rectangle.getSize().y);
			temp->_txt.setPosition(_ItemsPosition.x, _txtButtons.back()->_rectangle.getPosition().y + _txtButtons.back()->_rectangle.getSize().y);
			temp->_txt.setCharacterSize(14);
			temp->_txt.setFillColor(sf::Color::Black);
			temp->Callback = []() {
			
			};
			_txtButtons.push_back(temp);
		}
	//}
}


LayerBar::LayerBar()
{
	C_Documento::Instance()->Attach(*this);
	_background.setPosition(1166, 124);
	_background.setSize(sf::Vector2f(200, 644));
	_background.setFillColor(sf::Color(250, 208, 166));

	_ItemsPosition = sf::Vector2f(1166, 124);
	_font.loadFromFile("Assets/Calibri.ttf");

	sfTextButton* temp = new sfTextButton("Capa 1",_font);
	temp->_rectangle.setSize(sf::Vector2f(200, 25));
	temp->_rectangle.setPosition(_ItemsPosition);
	temp->_txt.setPosition(_ItemsPosition);
	temp->_txt.setCharacterSize(14);
	temp->_txt.setFillColor(sf::Color::Black);
	temp->Callback = []() {
		
	};
	_txtButtons.push_back(temp);
}


void LayerBar::Draw(sf::RenderWindow &window)
{
	window.draw(_background);
	for (auto& it : _txtButtons) {
		window.draw(it->_rectangle);
		window.draw(it->_txt);
	}
}

void LayerBar::Inputs(sf::Event & event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::MouseMoved) {
		for (auto &item : _buttons)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->onHover();
			}
			else {
				item->onHoverExit();
			}
		}
		for (auto &item : _txtButtons)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->onHover();
			}
			else {
				item->onHoverExit();
			}
		}
	}

	if (event.type == sf::Event::MouseButtonPressed) {
		for (auto &item : _buttons)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->Callback();
			}
		}
		for (auto &item : _txtButtons)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->Callback();
			}
		}
	}
}

LayerBar::~LayerBar()
{
}
