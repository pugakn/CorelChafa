#pragma once
#include "sfButton.h"
#include "Observer.h"
#include "ColorPicker.h"
class OptionsBar : public Observer
{
private:
	static OptionsBar* _instance;
	std::vector<sfButton*> _buttons;
	sf::Vector2f _ItemsPosition;
	sf::RectangleShape _background;
	ColorPicker _colorPicker;
protected:
	OptionsBar();
public:
	static OptionsBar* Instance();
	void Update() override;
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	~OptionsBar();
};

