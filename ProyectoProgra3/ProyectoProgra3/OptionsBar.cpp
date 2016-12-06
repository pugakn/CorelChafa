#include "stdafx.h"
#include "OptionsBar.h"
#include "C_Documento.h"

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

//	_background.setFillColor(sf::Color(18, 49, 62));
	_texture.loadFromFile("Assets/toolbar.png");
	_background.setTexture(&_texture);
	/*Botones********************/

	//Guardar/Cargar
	_ItemsPosition = sf::Vector2f(50,2);

	sfButton* temp = new sfButton;
	temp->LoadTexture("Assets/B_GUARD1.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(sf::Vector2f(40,20));
	temp->Callback = []() {
		
	};
	_buttons.push_back(temp);

	temp = new sfButton;
	temp->LoadTexture("Assets/B_CARGA1.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(100,20);
	temp->Callback = []() {
		
	};
	_buttons.push_back(temp);

	//Mover
		//Derecha/Izquierda
	temp = new sfButton;
	temp->LoadTexture("Assets/B_RIGHT.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(360, 63);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setPosicion(C_Documento::Instance()->_actual->_figuraActual->getPosicion() + sf::Vector2f(10,0));
	};
	_buttons.push_back(temp);
	temp = new sfButton;
	temp->LoadTexture("Assets/B_LEFT.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(240, 63);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setPosicion(C_Documento::Instance()->_actual->_figuraActual->getPosicion() - sf::Vector2f(10, 0));
	};
	_buttons.push_back(temp);

		//Arriba/Abajo
	temp = new sfButton;
	temp->LoadTexture("Assets/B_UP.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(300, 20);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setPosicion(C_Documento::Instance()->_actual->_figuraActual->getPosicion() - sf::Vector2f(0, 10));
	};
	_buttons.push_back(temp);
	temp = new sfButton;
	temp->LoadTexture("Assets/B_DOWN.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(300, 63);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setPosicion(C_Documento::Instance()->_actual->_figuraActual->getPosicion() + sf::Vector2f(0, 10));
	};
	_buttons.push_back(temp);

	//Resize
		//X
	temp = new sfButton;
	temp->LoadTexture("Assets/B_01.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(495, 17);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setSize(C_Documento::Instance()->_actual->_figuraActual->getSize()+ sf::Vector2f(10,0));
	};
	_buttons.push_back(temp);
	temp = new sfButton;
	temp->LoadTexture("Assets/B_03.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(550, 17);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setSize(C_Documento::Instance()->_actual->_figuraActual->getSize() - sf::Vector2f(10, 0));
	};
	_buttons.push_back(temp);

		//Y
	temp = new sfButton;
	temp->LoadTexture("Assets/B_02.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(495, 65);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setSize(C_Documento::Instance()->_actual->_figuraActual->getSize() + sf::Vector2f(0, 10));
	};
	_buttons.push_back(temp);
	temp = new sfButton;
	temp->LoadTexture("Assets/B_04.png");
	temp->_rectangle.setSize(sf::Vector2f(40, 40));
	temp->_rectangle.setPosition(550, 65);
	temp->Callback = []() {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr)
			C_Documento::Instance()->_actual->_figuraActual->setSize(C_Documento::Instance()->_actual->_figuraActual->getSize() - sf::Vector2f(0, 10));
	};
	_buttons.push_back(temp);

	_colorPicker.SetPosition(_ItemsPosition + sf::Vector2f(625, 25));
}


void OptionsBar::Draw(sf::RenderWindow &window)
{
	window.draw(_background);
	for (auto &item : _buttons)
		window.draw(item->_rectangle);
	_colorPicker.Draw(window);
}

void OptionsBar::Inputs(sf::Event & event, sf::RenderWindow & window)
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
	_colorPicker.Inputs(event,window);
}

OptionsBar::~OptionsBar()
{
}
