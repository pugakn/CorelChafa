#pragma once
class Observer
{
public:
	virtual void Update()=0;
	Observer();
	virtual ~Observer();
};

