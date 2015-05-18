#include "Simulaatio.h"


Simulaatio::Simulaatio()
{
	kierroksia = 0;
	kierros = 0;

}


Simulaatio::~Simulaatio()
{
}

void Simulaatio::Start(int pKierroksia)
{
	kierroksia = pKierroksia;

	RuokalaJono jono;
	std::string nimi;
	int hinta;

	//Luodaan asiakkaita kierrosm‰‰r‰n verran

	for (int i = 0; i < kierroksia; i++)
	{
		std::cout << "Asiakkaan " << i + 1 << " nimi: " << std::endl;
		std::cin >> nimi;
		std::cout << "Asiakkaan " << i + 1 << " aterian hinta: " << std::endl;
		std::cin >> hinta;

		uusiAsiakas = new Asiakas(nimi, hinta);
		jono.Add(uusiAsiakas);
	}

	//Kutsutaan jonon lajittelu algoritmia: 
	//Jono j‰rjestell‰‰n hinnan mukaan niin, ett‰ halvimman aterian omaavalle tarjoillaan ensin.
	jono.Sort();

	system("pause");

	//Aloitetaan tarjoilemissilmukka: tarjoilija saa parametriksi jono jota tarjoilla ja palauttaa true arvon niin kauan kun listassa on viel‰ asiakkaita
	while (tarjoilija.Tarjoile(jono))
	{		
		asiakas = *jono.getIteratorPtr(); // Asetetaan simulaatio luokan asiakas osoittamaan jonon ensimm‰iseen asiakkaaseen
		asiakas->SyoAteriaa();
		jono.Remove(asiakas); //Poistetaan asiakas jonosta sek‰ siirret‰‰n iteraattori osoittamaan jonon ensimm‰iseen asiakkaaseen
	}

	std::cout << "*****Kaikki asiakkaat on tarjoiltu!******" << std::endl;
	system("pause");
}


