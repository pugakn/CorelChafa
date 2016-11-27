#include "stdafx.h"
#include "Toolbar.h"

Toolbar* Toolbar::_instance = 0;
Tools Toolbar::_actualTool = Tools::CURSOR;

Toolbar * Toolbar::Instance()
{

	if (_instance == 0) {
		_instance = new Toolbar;
	}
	return _instance;

}

void Toolbar::Draw(sf::RenderWindow &window)
{
	window.draw(_background);
	for (auto &item : _buttons) {
		window.draw(item->_rectangle);
	}

}

Toolbar::Toolbar()
{
	_ItemsPosition = sf::Vector2f(0,164);
	_background.setPosition(0,124);
	_background.setSize(sf::Vector2f(50,644));
	_background.setFillColor(sf::Color(18,49,62));

	//BOTONES
	sfButton* temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition);
	temp->Callback = []() {
		_actualTool = Tools::CURSOR;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::CURVA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::ELIPSE;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::LINEA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::POLIGONO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::RECTANGULO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::RREDONDEADO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TEXTO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TIRA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/ico_cursor.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TRIANGULO;
	};
	_buttons.push_back(temp);






}

void Toolbar::Update(sf::Event & event, sf::RenderWindow& window)
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
	}

	if (event.type == sf::Event::MouseButtonPressed) {
		for (auto &item : _buttons)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->Callback();
			}
		}
	}
}


Toolbar::~Toolbar()
{
}
