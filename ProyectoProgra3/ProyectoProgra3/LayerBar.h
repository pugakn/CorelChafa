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
	std::vector<sfButton> _buttons;
	std::vector<sfTextButton> _txtButtons;
	sf::Vector2f _ItemsPosition;
	sf::RectangleShape _background;

	bool layerSelected = true;
	list<C_Figura*>* _figuras;
	list<C_Capa*>* _capas;

	sf::Font _font;
protected:
	LayerBar();
public:
	static LayerBar* Instance();
	void Update() override;
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~LayerBar();
};

