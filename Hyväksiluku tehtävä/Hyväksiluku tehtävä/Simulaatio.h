#pragma once
#include <iostream>
#include <string>
#include "Asiakas.h"
#include "Tarjoilija.h"
#include "RuokalaJono.h"

class Simulaatio
{
public:
	Simulaatio();
	~Simulaatio();
	void Start(int pKierroksia);

private:

	Asiakas* uusiAsiakas;
	Asiakas* asiakas;
	Tarjoilija tarjoilija;
	int jononPituus;
	int kierroksia;
	int kierros;
};

