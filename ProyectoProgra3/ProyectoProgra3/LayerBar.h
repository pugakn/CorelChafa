#pragma once
#include "sfButton.h"
#include "Observer.h"
#include "sfButton.h"
#include "sfTextButton.h"
#include "C_Figura.h"
#include "C_Capa.h"
class LayerBar : public Observer 
{
private:
	static LayerBar* _instance;
	std::vector<sfButton*> _buttons;
	std::vector<sfTextButton> _txtButtons;
	sf::Vector2f _ItemsPosition;
	sf::RectangleShape _background;
	sf::RectangleShape _background2;
	int _capasID = 2;

	bool layerSelected = true;
	list<C_Figura*>* _figuras;
	list<C_Capa*>* _capas;
	sf::Font _font;

	C_Capa *_capaActual;
	C_Figura* _figuraActual;
	bool _reordenado = false;
protected:
	LayerBar();
public:
	static bool _layerSelected;
	int _sliderCounter{0};
	int _maxSlider;
	static LayerBar* Instance();
	void Update() override;
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~LayerBar();
};

