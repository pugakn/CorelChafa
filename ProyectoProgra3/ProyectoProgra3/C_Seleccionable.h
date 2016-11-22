#pragma once
#include "C_Dibujable.h"
#include "SFML\System.hpp"
class C_Seleccionable : public C_Dibujable
{
public:
	bool Bloqueado;
	bool Visible;
	virtual bool HitTest(sf::Vector2i point) = 0;

};