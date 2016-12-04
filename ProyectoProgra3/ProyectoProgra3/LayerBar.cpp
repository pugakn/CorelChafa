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
	if (Size!= C_Documento::Instance()->_actual->Figuras.size() + C_Documento::Instance()->_lista.size()) {
		Size = C_Documento::Instance()->_actual->Figuras.size() + C_Documento::Instance()->_lista.size();
		_txtButtons.clear();
		sfTextButton temp ("Capa 1", _font);

		//if (_capas->size() == 1) {
			temp._rectangle.setSize(sf::Vector2f(150, 25));
			//temp._rectangle.setPosition(_ItemsPosition - sf::Vector2f(50,50));
			temp._txt.setPosition(_ItemsPosition);
			temp._txt.setCharacterSize(14);
			temp._txt.setFillColor(sf::Color::Black);
			temp.Callback = []() {

			};
			_txtButtons.push_back(temp);
		//}

		for (auto& layer: *_capas)
		{
			//if (_capas->size()>1) { //Inicializar botones de capas
				temp =  sfTextButton("Capa " + to_string(layer->ID), _font);
				//temp->LoadTexture("Assets/ico_cursor.png");
				temp._rectangle.setSize(sf::Vector2f(150, 25));
				temp._rectangle.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
				//temp._txt.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
				temp._txt.setCharacterSize(14);
				temp._txt.setFillColor(sf::Color::Black);
				temp.Callback = [&layer]() {
					LayerBar::Instance()->_layerSelected = true;
					C_Documento::Instance()->SetActual(layer);
				};
				_txtButtons.push_back(temp);
			//}
			// Inicializar botones de figuras
			for (auto &it : layer->Figuras) {
				temp =  sfTextButton(it->getType() + " " + to_string(it->getID()), _font);
				//temp->LoadTexture("Assets/ico_cursor.png");
				temp._rectangle.setSize(sf::Vector2f(150, 25));
				temp._rectangle.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
				//temp._txt.setPosition(_ItemsPosition.x, _txtButtons.back()._rectangle.getPosition().y + _txtButtons.back()._rectangle.getSize().y);
				temp._txt.setCharacterSize(14);
				temp._txt.setFillColor(sf::Color::Black);
				temp.Callback = [&it]() {
					LayerBar::Instance()->_layerSelected = false;
					C_Documento::Instance()->_actual->SetActual(it);
				};
				_txtButtons.push_back(temp);
			}
		}
	}
}


LayerBar::LayerBar()
{
	_figuras = &C_Documento::Instance()->_actual->Figuras;
	_capas = &C_Documento::Instance()->_lista;
	C_Documento::Instance()->Attach(*this);
	_background.setPosition(1166, 124);
	_background.setSize(sf::Vector2f(200, 644));
	_background.setFillColor(sf::Color(250, 208, 166));

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
	sfButton button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(100, 50));
	button._rectangle.setPosition(1166,720-50);
	button.Callback = [this]() { 
		C_Documento::Instance()->Insertar(this->_capasID++);
	};
	_buttons.push_back(button);

	//Delete
	button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(100, 50));
	button._rectangle.setPosition(1266, 720 - 50);
	button.Callback = []() { //TODO: Capa o Figura
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Eliminar();
		else
			C_Documento::Instance()->_actual->Eliminar();
	};
	_buttons.push_back(button);
	//Subir
	button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 50));
	button._rectangle.setPosition(1166, 720);
	button.Callback = []() {
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Subir();
		else
			C_Documento::Instance()->_actual->Subir();
	};
	_buttons.push_back(button);
	//Bajar
	button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 50));
	button._rectangle.setPosition(1166+50, 720);
	button.Callback = []() {
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->Bajar();
		else
			C_Documento::Instance()->_actual->Bajar();
	};
	_buttons.push_back(button);
	//Visible
	button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 50));
	button._rectangle.setPosition(1266, 720);
	button.Callback = []() {
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->_actual->Visible = ! C_Documento::Instance()->_actual->Visible;
		else
			C_Documento::Instance()->_actual->_figuraActual->Visible = !C_Documento::Instance()->_actual->_figuraActual->Visible;
	};
	_buttons.push_back(button);
	//Lock
	button =  sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 50));
	button._rectangle.setPosition(1266 + 50, 720);
	button.Callback = []() {
		if (LayerBar::Instance()->_layerSelected == true)
			C_Documento::Instance()->_actual->Visible = !C_Documento::Instance()->_actual->Bloqueado;
		else
			C_Documento::Instance()->_actual->_figuraActual->Visible = !C_Documento::Instance()->_actual->_figuraActual->Bloqueado;
	};
	_buttons.push_back(button);
	//Up Slider
	button = sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 25));
	button._rectangle.setPosition(1166 + 150, 124);
	button.Callback = [this]() {
		if (_txtButtons.size()>21)
			if (this->_sliderCounter > 0) {
				this->_sliderCounter--;
			}
	};
	_buttons.push_back(button);

	//Down Slider
	button = sfButton();
	button._rectangle.setSize(sf::Vector2f(50, 25));
	button._rectangle.setPosition(1166 + 150, 124+644-123);
	button.Callback = [this]() {
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
		window.draw(it._rectangle);
	}
}

void LayerBar::Inputs(sf::Event & event, sf::RenderWindow & window)
{
	if (event.type == sf::Event::MouseMoved) {
		for (auto &item : _buttons)
		{
			if (item.HitTest(sf::Mouse::getPosition(window)))
			{
				item.onHover();
			}
			else {
				item.onHoverExit();
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
			if (item.HitTest(sf::Mouse::getPosition(window)))
			{
				item.Callback();
			}
		}
		for (auto &item : _txtButtons)
		{
			if (item.HitTest(sf::Mouse::getPosition(window)))
			{
				item.Callback();
			}
		}
	}
}

LayerBar::~LayerBar()
{
}
