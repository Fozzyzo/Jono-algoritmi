#pragma once
#include <list>
#include "Asiakas.h"
class RuokalaJono
{
public:
	RuokalaJono();
	~RuokalaJono();
	void Add(Asiakas* asiakas);
	void Remove(Asiakas* asiakas);
	void SeuraavaAsiakas();
	void Sort();
	std::list<Asiakas*>::iterator getIteratorPtr(){ return it; }
	std::list<Asiakas*> getQueue() { return queue; }

private:
	std::list<Asiakas*>queue;
	std::list<Asiakas*>::iterator it;
};

