#pragma once
#include "Observer.h"
#include <list>
class Subject
{
private:
	std::list<Observer*> _list;
public:
	virtual void Attach(Observer& observer) = 0;
	virtual void Detach(Observer& observer) = 0;
	virtual void Notify();
	Subject();
	virtual ~Subject();
};

