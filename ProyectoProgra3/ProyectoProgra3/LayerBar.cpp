#include "stdafx.h"
#include "LayerBar.h"
#include "C_Documento.h"

LayerBar* LayerBar::_instance = 0;
bool LayerBar::_layerSelected = true;

LayerBar * LayerBar::Instance()
{

	if (_instance == 0) {
		_instance = new LayerBar;
	}
	return _instance;
}

void LayerBar::Update()
{
	static int Size;
	if (Size != C_Documento::Instance()->_actual->Figuras.size() + C_Documento::Instance()->_lista.size() || _reordenado ||
		_capaActual != C_Documento::Instance()->_actual) {
		//_capaActual = C_Documento::Instance()->_actual;
		_reordenado = false;
		Size = C_Documento::Instance()->_actual->Figuras.size() + C_Documento::Instance()->_lista.size();
		_txtButtons.clear();
		sfTextButton temp("Capa 1", _font);
		temp._rectangle.setSize(sf::Vector2f(150, 25));
		temp._txt.setPosition(_ItemsPosition);
		temp._txt.setCharacterSize(14);
		temp._txt.setFillColor(sf::Color::Black);
		temp.Callback = []() {
		};
		_txtButtons.push_back(temp);

		for (auto& layer : *_capas)
		{
			temp = sfTextButton("Capa " + to_string(layer->ID), _font);
			temp._rectangle.setSize(sf::Vector2f(150, 25));
			temp._rectangle.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
			temp._txt.setCharacterSize(14);
			temp._txt.setFillColor(sf::Color::Black);
			temp.Callback = [&layer,this]() {
				breakCicle = true;
				LayerBar::Instance()->_layerSelected = true;
				C_Documento::Instance()->SetActual(layer);
				//C_Documento::Instance()->_actual->SetActual(nullptr);
				return;
			};
			_txtButtons.push_back(temp);
			// Inicializar botones de figuras
			for (auto &it : layer->Figuras) {
				temp = sfTextButton(it->getType() + " " + to_string(it->getID()), _font);
				temp._rectangle.setSize(sf::Vector2f(150, 25));
				temp._rectangle.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
				temp._txt.setCharacterSize(14);
				temp._txt.setFillColor(sf::Color::Black);
				temp.Callback = [&it, &layer,this]() {
					breakCicle = true;
					LayerBar::Instance()->_layerSelected = false;
					C_Documento::Instance()->SetActual(layer);
					C_Documento::Instance()->_actual->SetActual(it);
				};
				_txtButtons.push_back(temp);
			}
		}
	}

	/*Actualizar botones*/
	if (_figuraActual != C_Documento::Instance()->_actual->_figuraActual) {
		if (C_Documento::Instance()->_actual->_figuraActual != nullptr) {
			_figuraActual = C_Documento::Instance()->_actual->_figuraActual;
			if (C_Documento::Instance()->_actual->_figuraActual->Bloqueado)
				_buttons[4]->LoadTexture("Assets/M_BLOQU.png");
			else
				_buttons[4]->LoadTexture("Assets/M_DESBLO.png");
			if (C_Documento::Instance()->_actual->_figuraActual->Visible) {
				_buttons[5]->LoadTexture("Assets/M_VISIBL.png");
			}
			else _buttons[5]->LoadTexture("Assets/M_INVIS.png");
		}
	}

	if (_capaActual != C_Documento::Instance()->_actual) {
		_capaActual = C_Documento::Instance()->_actual;
		if (LayerBar::Instance()->_layerSelected == true) {
			if (C_Documento::Instance()->_actual->Bloqueado)
				_buttons[4]->LoadTexture("Assets/M_BLOQU.png");
			else
				_buttons[4]->LoadTexture("Assets/M_DESBLO.png");
			if (C_Documento::Instance()->_actual->Visible) {
				_buttons[5]->LoadTexture("Assets/M_VISIBL.png");
			}
			else _buttons[5]->LoadTexture("Assets/M_INVIS.png");
		}
	}
	/*****************************/
}


LayerBar::LayerBar()
{
	_figuras = &C_Documento::Instance()->_actual->Figuras;
	_capas = &C_Documento::Instance()->_lista;
	C_Documento::Instance()->Attach(*this);
	_background.setPosition(1166, 124);
	_background.setSize(sf::Vector2f(200, 644));
	_background.setFillColor(sf::Color(57, 57, 57));

	_background2.setPosition(1316, 124);
	_background2.setSize(sf::Vector2f(50, 644));
	_background2.setFillColor(sf::Color(20, 20, 20));

	_ItemsPosition = sf::Vector2f(1166, 124) - sf::Vector2f(0, 25);
	_font.loadFromFile("Assets/Calibri.ttf");

	sfTextButton temp =  sfTextButton("Capa 1",_font);
	temp._rectangle.setSize(sf::Vector2f(150, 25));
	temp._rectangle.setPosition(_ItemsPosition);
	temp._txt.setPosition(_ItemsPosition);
	temp._txt.setCharacterSize(14);
	temp._txt.setFillColor(sf::Color::Black);
	temp.Callback = []() {
		
	};
	_txtButtons.push_back(temp);

	/************ Botones ***********/
	//New layer
	sfButton *button =  new sfButton();
	button->_rectangle.setSize(sf::Vector2f(100, 50));
	button->LoadTexture("Assets/M_NUECAPA.png");
	button->_rectangle.setPosition(1166,720-50);
	button->Callback = [this]() { 
		C_Documento::Instance()->Insertar(this->_capasID++);
	};
	_buttons.push_back(button);

	//Delete
	button =  new sfButton();
	button->_rectangle.setSize(sf::Vector2f(100, 50));
	button->LoadTexture("Assets/M_ELIMIN.png");
	button->_rectangle.setPosition(1266, 720 - 50);
	button->Callback = []() { //TODO: Capa o Figura
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Eliminar();
		else
			C_Documento::Instance()->_actual->Eliminar();
	};
	_buttons.push_back(button);
	//Subir
	button =  new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 50));
	button->LoadTexture("Assets/M_ARRIBA.png");
	button->_rectangle.setPosition(1166, 720);
	button->Callback = [this]() {
		_reordenado = true;
		breakCicle = true;
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Subir();
		else
			C_Documento::Instance()->_actual->Subir();
	};
	_buttons.push_back(button);
	//Bajar
	button =  new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 50));
	button->LoadTexture("Assets/M_ABAJO.png");
	button->_rectangle.setPosition(1166+50, 720);
	button->Callback = [this]() {
		_reordenado = true;
		breakCicle = true;
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Bajar();
		else
			C_Documento::Instance()->_actual->Bajar();
	};
	_buttons.push_back(button);
	//Lock
	button = new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 50));
	button->LoadTexture("Assets/M_DESBLO.png");
	button->_rectangle.setPosition(1266, 720);
	button->Callback = [button]() {
		if (LayerBar::Instance()->_layerSelected == true) {
			C_Documento::Instance()->_actual->Bloqueado = !C_Documento::Instance()->_actual->Bloqueado;
			if (C_Documento::Instance()->_actual->Bloqueado)
				button->LoadTexture("Assets/M_BLOQU.png");
			else
				button->LoadTexture("Assets/M_DESBLO.png");
		}
		else {
			if (C_Documento::Instance()->_actual->_figuraActual != nullptr) {
				C_Documento::Instance()->_actual->_figuraActual->Bloqueado = !C_Documento::Instance()->_actual->_figuraActual->Bloqueado;
				if (C_Documento::Instance()->_actual->_figuraActual->Bloqueado)
					button->LoadTexture("Assets/M_BLOQU.png");
				else
					button->LoadTexture("Assets/M_DESBLO.png");
			}
		}
	};
	_buttons.push_back(button);
	//Visible
	button =  new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 50));
	button->LoadTexture("Assets/M_VISIBL.png");
	button->_rectangle.setPosition(1266 + 50, 720);
	button->Callback = [button]() {
		if (LayerBar::Instance()->_layerSelected == true) {
			C_Documento::Instance()->_actual->Visible = !C_Documento::Instance()->_actual->Visible;
			if (C_Documento::Instance()->_actual->Visible) {
				button->LoadTexture("Assets/M_VISIBL.png");
			}else button->LoadTexture("Assets/M_INVIS.png");
		}
		else {
			if (C_Documento::Instance()->_actual->_figuraActual != nullptr){
				C_Documento::Instance()->_actual->_figuraActual->Visible = !C_Documento::Instance()->_actual->_figuraActual->Visible;
				if (C_Documento::Instance()->_actual->_figuraActual->Visible) {
					button->LoadTexture("Assets/M_VISIBL.png");
				}
				else button->LoadTexture("Assets/M_INVIS.png");
			}
		}
			
	};
	_buttons.push_back(button);
	//Up Slider
	button = new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 25));
	button->LoadTexture("Assets/SCROLL_1.png");
	button->_rectangle.setPosition(1166 + 150, 124);
	button->Callback = [this]() {
		if (_txtButtons.size()>21)
			if (this->_sliderCounter > 0) {
				this->_sliderCounter--;
			}
	};
	_buttons.push_back(button);

	//Down Slider
	button = new sfButton();
	button->_rectangle.setSize(sf::Vector2f(50, 25));
	button->LoadTexture("Assets/SCROLL_2.png");
	button->_rectangle.setPosition(1166 + 150, 124+644-123);
	button->Callback = [this]() {
		if (_txtButtons.size()>21)
			//if (this->_sliderCounter < this->_maxSlider) {
				this->_sliderCounter++;
			//}
	};
	_buttons.push_back(button);

	/********************************/
}


void LayerBar::Draw(sf::RenderWindow &window)
{

	window.draw(_background);
	window.draw(_background2);
	//auto it = _txtButtons.begin();
	int i = 0;
	if(_txtButtons.size()>21)
		for ( ; i < _sliderCounter; i++) {
			//it++;
		}
	bool first = true;
	for (; i < _txtButtons.size();i++) {
		if (first) {
			_txtButtons[i]._rectangle.setPosition(_ItemsPosition);
			_txtButtons[i]._txt.setPosition(_ItemsPosition);
			first = false;
		}
		else {
			_txtButtons[i]._rectangle.setPosition(_ItemsPosition.x, _txtButtons[i-1]._rectangle.getPosition().y + _txtButtons[i]._rectangle.getSize().y);
			_txtButtons[i]._txt.setPosition(_ItemsPosition.x, _txtButtons[i-1]._rectangle.getPosition().y + _txtButtons[i]._rectangle.getSize().y);
		}

		window.draw(_txtButtons[i]._rectangle);
		window.draw(_txtButtons[i]._txt);
	}
	for (auto& it : _buttons) {
		window.draw(it->_rectangle);
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
			if (item.HitTest(sf::Mouse::getPosition(window)))
			{
				item.onHover();
			}
			else {
				item.onHoverExit();
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
		for (auto item = _txtButtons.begin() ; item !=  _txtButtons.end(); item++)
		{
			if (item->HitTest(sf::Mouse::getPosition(window)))
			{
				item->Callback();
				if (breakCicle) {
					breakCicle = false;
					item = _txtButtons.begin();
					break;
				}
			}
		}
	}
}

LayerBar::~LayerBar()
{
}
