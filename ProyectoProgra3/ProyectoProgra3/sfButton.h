#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <functional>
class sfButton
{
private:

	sf::Texture _texture;
	sf::Texture _hoverTexture;

public:
	//void(*action)();
	std::function<void()> Callback;
	sf::RectangleShape _rectangle;
	void onDown();
	void onHover();
	void onHoverExit();
	bool HitTest(sf::Vector2i mousePos);
	bool LoadTexture(std::string src);
	bool LoadHoverTexture(std::string src);
	sfButton();
	~sfButton();
};

