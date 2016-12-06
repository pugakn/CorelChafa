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
#include <iostream>
Toolbar::Toolbar()
{
	_ItemsPosition = sf::Vector2f(0,164);
	_background.setPosition(0,124);
	_background.setSize(sf::Vector2f(50,644));
	//_background.setFillColor(sf::Color(18,49,62));
	_backgroundTexture.loadFromFile("Assets/H_BARRA.png");
	_background.setTexture(&_backgroundTexture);

	//BOTONES
	sfButton* temp = new sfButton;
	temp->LoadTexture("Assets/H_SELEC.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition);
	temp->Callback = []() {
		_actualTool = Tools::CURSOR;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_CURVA.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::CURVA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_CIRCULO.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::ELIPSE;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_LINEA.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::LINEA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_POLIGO.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	
	temp->Callback = [this]() {
		_polilados = Poliwindow();
		_actualTool = Tools::POLIGONO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_RECT.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::RECTANGULO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_REDON.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::RREDONDEADO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_TEXTO.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TEXTO;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_TIRALIN.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TIRA;
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/H_TRIAN.png");
	temp->_rectangle.setSize(sf::Vector2f(50, 50));
	temp->_rectangle.setPosition(_ItemsPosition.x, _buttons.back()->_rectangle.getPosition().y + _buttons.back()->_rectangle.getSize().y);
	temp->Callback = []() {
		_actualTool = Tools::TRIANGULO;
	};
	_buttons.push_back(temp);
}


int Toolbar::Poliwindow()
{
	sf::RenderWindow window(sf::VideoMode(400, 200), "Poligono");
	std::string s = "";
	int realNum;
	sf::Font Fuente;
	Fuente.loadFromFile("Assets/calibri.ttf");
	sf::Text Texto;
	Texto.setString("Número de Lados:");
	Texto.setCharacterSize(50);
	Texto.setFont(Fuente);
	Texto.setPosition(10,0);
	sf::Text PoliTexto;
	PoliTexto.setFont(Fuente);
	PoliTexto.setCharacterSize(90);
	PoliTexto.setPosition(160,70);
	while (window.isOpen()) {
		//Event processing.

		sf::Event event;
		window.clear(sf::Color(102, 102, 102, 255));
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 5;
			}
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 128) {
					s.push_back((char)event.text.unicode);
					PoliTexto.setString(s);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				window.close();
			}
		}
		window.draw(PoliTexto);
		window.draw(Texto);
		window.display();

	}
	realNum = atoi(s.c_str());
	std::cout << realNum;
	realNum = abs(realNum);
	if (realNum <= 2 && realNum >= 0)
		return 5;
	if (realNum >= -30 && realNum <= 30)
		return realNum;
	else
		return 5;
}

void Toolbar::Inputs(sf::Event & event, sf::RenderWindow& window)
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
