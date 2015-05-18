#pragma once
#include <string>
#include <iostream>

class Asiakas
{
public:
	Asiakas(std::string pNimi, int pAterianHinta);
	~Asiakas();
	void SyoAteriaa();
	int getHinta() { return aterianHinta; }
	std::string getNimi(){ return nimi; }

private:

	std::string nimi;
	int aterianHinta;
};

