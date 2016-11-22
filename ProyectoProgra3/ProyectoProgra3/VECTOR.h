#pragma once
#include <SFML\System.hpp>

sf::Vector2f operator*(sf::Vector2f A, sf::Vector2f B);

sf::Vector2f operator/(sf::Vector2f A, sf::Vector2f B);

sf::Vector3f Cross(sf::Vector2f A, sf::Vector2f B);

sf::Vector3f Cross(sf::Vector3f A, sf::Vector3f B);

