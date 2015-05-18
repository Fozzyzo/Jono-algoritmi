#include "Asiakas.h"


Asiakas::Asiakas(std::string pNimi, int pAterianHinta)
{
	nimi = pNimi;
	aterianHinta = pAterianHinta;
}


Asiakas::~Asiakas()
{
}

void Asiakas::SyoAteriaa()
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << nimi << ": Omm..nom...nom...." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::system("Pause");
}

