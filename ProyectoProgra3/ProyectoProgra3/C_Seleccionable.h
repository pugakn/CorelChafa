#pragma once
#include "C_Dibujable.h"
class C_Seleccionable : public C_Dibujable
{
public:
	bool Bloqueado;
	bool Visible;
	virtual bool HitTest() = 0;
};