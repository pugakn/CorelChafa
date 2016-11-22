#include "stdafx.h"
#include "VECTOR.h"

sf::Vector2f operator*(sf::Vector2f A, sf::Vector2f B) {
	return sf::Vector2f(A.x*B.x, A.y*B.y);
}
sf::Vector2f operator/(sf::Vector2f A, sf::Vector2f B) {
	return sf::Vector2f(A.x / B.x, A.y / B.y);
}

sf::Vector3f Cross(sf::Vector2f A, sf::Vector2f B) {
	return sf::Vector3f(0, 0, A.x*B.y - A.y*B.x);
}

sf::Vector3f Cross(sf::Vector3f A, sf::Vector3f B) {
	return sf::Vector3f(A.y*B.z - A.z*B.y,
		A.z*B.x - A.x*B.z,
		A.x*B.y - A.y*B.x);
}
