#pragma once
#include <SFML\Graphics.hpp>
#include "Observer.h"
#include "C_Figura.h"
#include "C_Capa.h"
class InfoBar : public Observer
{
private:
	static InfoBar* _instance;
	sf::Vector2f _ItemsPosition;

	string _positionString;
	string _fillColorString;
	string _borderColorString;
	string _idString;
	sf::Text _idText;
	sf::Text _positionTXT;
	sf::Text _fillColorTXT;
	sf::Text _borderColorTXT;
	sf::Font _font;
	sf::RectangleShape _background;
	sf::Texture _texture;
	C_Figura *_actual;
	C_Capa *_capaActial;
	sf::Vector2f _posicion;
protected:
	InfoBar();
public:
	void Update() override;
	void Draw(sf::RenderWindow&);
	void Inputs(sf::Event& event, sf::RenderWindow& window);
	static InfoBar* Instance();
	~InfoBar();
};

