#pragma once
#include "C_Dibujable.h"
#include "SFML\System.hpp"
class C_Seleccionable : public C_Dibujable
{
public:
	bool Bloqueado = false;
	bool Visible = true;
	virtual bool HitTest(sf::Vector2i point) = 0;

};