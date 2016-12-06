#include "stdafx.h"
#include "DrawArea.h"
#include "Toolbar.h"
#include "LayerBar.h"

DrawArea* DrawArea::_instance = 0;
DrawArea::DrawArea()
{
	_drawAreaLimits.top = 124;
	_drawAreaLimits.left = 50;
	_drawAreaLimits.height = 600;
	_drawAreaLimits.width = 1092;
	
	//Inicializar documento
	_documento = C_Documento::Instance();
	_documento->Inicializar();

}


DrawArea * DrawArea::Instance()
{
	if (_instance == 0) {
		_instance = new DrawArea;
	}
	return _instance;
}

void DrawArea::Draw(sf::RenderWindow & window)
{
	_documento->Dibujar(window);
}

void DrawArea::Inputs(sf::Event & event, sf::RenderWindow & window)
{
	static bool first = true;//TODO: Fix
	static int curvaStep=0;
	static bool textActive = false;
	static sf::Vector2f initialPos;
	static sf::Vector2f deltPos;
	static string text;
	if (textActive)
		if (event.type == sf::Event::TextEntered) {
			if (event.text.unicode == 13) {
				textActive = false;
				text.clear();
			}
			else {
				text += event.text.unicode;
				((C_Texto*)_documento->_actual->Figuras.back())->textString = text;
				((C_Texto*)_documento->_actual->Figuras.back())->_texto.setString(((C_Texto*)_documento->_actual->Figuras.back())->textString);
			}
		}
	if (event.type == sf::Event::MouseButtonPressed) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) //ojala que no arruine otras cosas
		return;
	//if (event.type == sf::Event::MouseButtonPressed) 
	//{
		if (_drawAreaLimits.contains((sf::Vector2f)sf::Mouse::getPosition(window))) {
			switch (Toolbar::_actualTool)
			{
			case Tools::CURSOR:
				curvaStep = 0;
				for (auto& it : C_Documento::Instance()->_lista) {
					for (auto& item : it->Figuras) {
						if (item->HitTest(sf::Mouse::getPosition(window)) && !item->Bloqueado  && item->Visible) {
							C_Documento::Instance()->_actual->SetActual(item);
							LayerBar::Instance()->_layerSelected = false;
						}
					}
				}
				break;
			case Tools::CURVA:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (curvaStep == 0) {
						_documento->_actual->InsertarCurva((sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window), "Curva", _curvaID++);
						curvaStep++;
					}else
					if (curvaStep == 1) {
						((C_Curva*)_documento->_actual->Figuras.back())->setP2((sf::Vector2f)sf::Mouse::getPosition(window));
						curvaStep++;
					}else
					if (curvaStep == 2) {
						((C_Curva*)_documento->_actual->Figuras.back())->setC1((sf::Vector2f)sf::Mouse::getPosition(window));
						curvaStep++;
					}else
					if (curvaStep == 3) {
						((C_Curva*)_documento->_actual->Figuras.back())->setC2((sf::Vector2f)sf::Mouse::getPosition(window));
						curvaStep = 0;
					}
				}

				break;
			case Tools::ELIPSE:
				curvaStep = 0;
				if (event.mouseButton.button == sf::Mouse::Left)
					_documento->_actual->InsertarElipse(50,50,"Elipse", _elipseID++);
				break;
			case Tools::LINEA:
				if (event.mouseButton.button == sf::Mouse::Left)
					if (first) {
						first = false;
						_documento->_actual->InsertarLinea((sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window), "Linea", _lineaID++);
					}
					else {
						first = true;
					}
				break;
			case Tools::POLIGONO:
				curvaStep = 0;
				if (event.mouseButton.button == sf::Mouse::Left)
					_documento->_actual->InsertarPoligono(Toolbar::Instance()->_polilados, 50, "Poligono", _poligonoID++);
				break;
			case Tools::RECTANGULO:
				curvaStep = 0;
				if (event.mouseButton.button == sf::Mouse::Left) 
					_documento->_actual->InsertarRectangulo(50, 50, "Rectangulo", _rectID++);
				break;
			case Tools::RREDONDEADO:
				curvaStep = 0;
				if (event.mouseButton.button == sf::Mouse::Left) 
					_documento->_actual->InsertarRectanguloRed(50, 50, "Rectangulo Red", _rRectID++);
				break;
			case Tools::TEXTO:
				curvaStep = 0;
				if (!textActive) {
					textActive = true;
					_documento->_actual->InsertarTexto(35, "Texto", _textID++);
				}

				break;
			case Tools::TIRA:
				curvaStep = 0;
			{
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (first) {
						_documento->_actual->InsertarTiraDeLineas((sf::Vector2f)sf::Mouse::getPosition(window), (sf::Vector2f)sf::Mouse::getPosition(window), "Tira Lineas", _tlineasID++);
						_documento->_actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
						first = false;
					}
					else {
						((C_TiraLineas*)_documento->_actual->Figuras.back())->nuevoVertice((sf::Vector2f)sf::Mouse::getPosition(window));
					}
				}
				else {
					first = true;
					((C_TiraLineas*)_documento->_actual->Figuras.back())->SetLastPointPosition(((C_TiraLineas*)_documento->_actual->Figuras.back())->_shape[((C_TiraLineas*)_documento->_actual->Figuras.back())->_shape.getVertexCount()-2].position);
				}

			}
				break;
			case Tools::TRIANGULO:
				curvaStep = 0;
				if (event.mouseButton.button == sf::Mouse::Left)
					_documento->_actual->InsertarTriangulo(50, 50, "Triangle",_triangleID++);
				break;
			default:
				break;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (Toolbar::_actualTool != Tools::CURSOR) {

					_buttonClicked = true;
					//_documento->_actual->Figuras.back()->setColorRelleno(_fillColor);
					//_documento->_actual->Figuras.back()->setColorLinea(_borderColor);
					if (Toolbar::_actualTool != Tools::TIRA && Toolbar::_actualTool != Tools::LINEA && Toolbar::_actualTool != Tools::CURVA) {
						initialPos = (sf::Vector2f)sf::Mouse::getPosition(window);
						_documento->_actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
					}
				}
			}
		}
	}
	if (event.type == sf::Event::MouseButtonReleased) {
		_buttonClicked = false;
	}
	if (event.type == sf::Event::MouseMoved) {
		if (Toolbar::_actualTool == Tools::TIRA && !first) {
			((C_TiraLineas*)_documento->_actual->Figuras.back())->SetLastPointPosition((sf::Vector2f)sf::Mouse::getPosition(window));
		}
		else if (Toolbar::_actualTool == Tools::LINEA && !first) {
			((C_Linea*)_documento->_actual->Figuras.back())->setLastVertexPos((sf::Vector2f)sf::Mouse::getPosition(window));
		}else
		if (_buttonClicked) {
			deltPos = (sf::Vector2f)sf::Mouse::getPosition(window) - initialPos;
			_documento->_actual->Figuras.back()->setSize(deltPos);
			//_documento._actual->Figuras.back()->setPosicion((sf::Vector2f)sf::Mouse::getPosition(window));
		}
	}

}

DrawArea::~DrawArea()
{
}
