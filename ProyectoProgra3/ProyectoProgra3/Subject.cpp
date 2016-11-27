#include "stdafx.h"
#include "Subject.h"


void Subject::Notify()
{
	for (auto &item : _list) {
		item->Update();
	}
}

Subject::Subject()
{
}


Subject::~Subject()
{
}
