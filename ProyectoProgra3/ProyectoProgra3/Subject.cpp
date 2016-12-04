#include "stdafx.h"
#include "Subject.h"


void Subject::Notify()
{
	for (auto &item : _observers) {
		item->Update();
	}
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
