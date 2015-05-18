#include "Tarjoilija.h"


Tarjoilija::Tarjoilija()
{
	i = 0;
}


Tarjoilija::~Tarjoilija()
{
}

bool Tarjoilija::Tarjoile(RuokalaJono pJono)
{
	if (!pJono.getQueue().empty())
	{
		return true;
	}
	
	else
		return false;
}
