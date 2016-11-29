#pragma once
#include "Observer.h"
#include "C_Dibujable.h"
#include <list>
class Subject : public C_Dibujable
{
protected:
	std::list<Observer*> _observers;
public:
	virtual void Attach(Observer& observer) = 0;
	virtual void Detach(Observer& observer) = 0;
	virtual void Notify();
	Subject();
	virtual ~Subject();
};

