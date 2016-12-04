#include "stdafx.h"
#include "Factory.h"

C_Figura* FigurasFactoy(int ClassID)
{
	switch (ClassID)
	{
	case ClassID_Curva:
		return new C_Curva;
	case ClassID_Elipse:
		return new C_Elipse;
	case ClassID_Linea:
		return new C_Linea;
	case ClassID_Poligono:
		return new C_Poligono;
	/*case ClassID_Rectangulo:
		return new C_Rectangulo;
	case ClassID_RRedondeado:
		return new C_RRedondeado;
	case ClassID_Texto:
		return new C_Texto;*/
	case ClassID_TiraLineas:
		return new C_TiraLineas;
	case ClassID_Triangulo:
		return new C_Triangulo;
	default:
		return NULL;
	}
	return NULL; //La Factory esta desactivada hasta que las figuras dejen de ser abstractas
}
