#include "RuokalaJono.h"


RuokalaJono::RuokalaJono()
{
}


RuokalaJono::~RuokalaJono()
{
	queue.clear();
}

void RuokalaJono::Add(Asiakas* asiakas)
{
		queue.push_back(asiakas);
}

void RuokalaJono::Remove(Asiakas* asiakas)
{
	queue.remove(asiakas);
	it = queue.begin();
}

void RuokalaJono::Sort()
{	
	std::list<Asiakas*> newList;
	std::list<Asiakas*>::iterator newIt;

	Asiakas* pieninHinta = NULL;
	Asiakas* tempPtr = NULL;

	//Lajittelu algoritmi: 
		/*
			Algoritmi toimii siten, ett‰ k‰yd‰‰n jonoa l‰pi, ja vertaillaan aina 
			lˆydetty‰ hintaa iteraattorin osoittamaan asiakkaaseen. L‰pik‰ynniss‰ 
			t‰ytyy aina tarkistaa ensin, ett‰ sen hetken pieninHinta ei ole null-pointteri.
		*/
	for (int i = 0; i < queue.size(); i++)
	{
		for (it = queue.begin(); it != queue.end(); it++)
		{
			tempPtr = *it;
			//Jos pienin hinta ei ole NULL, ja iteraattorin osoittaman asiakkaan ateria on halvempi mit‰
			//aiempi pieninHinta, siirryt‰‰n eteen p‰in.
			if (pieninHinta == NULL || tempPtr->getHinta() <= pieninHinta->getHinta())
			{
				//Jos tyhj‰, niin laitetaan pieninHinta osoitin automaattisesti osoittamaan siihen

				if (newList.empty())
				{
					pieninHinta = tempPtr;
				}
				/*
					Tarkistetaan ett‰ hinta on kuitenkin suurempi mit‰ aiempi uuteen listaan asetetun 
					asiakkaan hinta, tarkistuksen tarkoituksena on varmistua ett‰ lˆydetty pieni hinta ei 
					ole jo valmiiksi lis‰tty listaan. T‰m‰ suorituskyvyn kannalta viel‰ yksinkertainen
					tarkistus on viel‰ yksinkertainen tarkistus siihen verrattuna ett‰ k‰yt‰isiin koko
					uusi lista l‰pi
				*/
				else if (tempPtr->getHinta() > newList.back()->getHinta())
					pieninHinta = tempPtr;

				/*
					Jos osoittimen asiakkaan hinta on sama kuin viimeisimm‰n lis‰yksen hinta, sek‰ osoitin 
					on eri kuin aiemmin lis‰tyn asiakkaan osoitin, t‰ytyy uusilista k‰yd‰ l‰pi ja varmistua
					ett‰ asiakas ei ole jo lis‰tty listaan
				*/
				else if (tempPtr->getHinta() == newList.back()->getHinta() && tempPtr != newList.back())
				{

					for (newIt = newList.begin(); newIt != newList.end(); newIt++)
					{
						if (*newIt == tempPtr)
						{
							break;
						}
					}

					/*
						Iteraattori osoittaa listan loppuun, eli asiakasta ei lˆytynyt listalta. Tehd‰‰n 
						asiakkaan hinnasta uusi "pieninHinta"
					*/
					if (newIt == newList.end())
					{
						pieninHinta = tempPtr;
					}
				}
					
				else
					continue;
			}
		}

		/*
			Lis‰t‰‰n uusi asiakas uuteen listaan tarkitusten j‰lkeen
		*/
		newList.push_back(pieninHinta);
		pieninHinta = NULL;
	}

	/*
		Yhteenveto:

		Algoritmi toimii niin kuin pit‰‰, eli j‰rjest‰‰ tietyn m‰‰r‰n asiakkaita hinnan mukaiseen 
		j‰rjestykseen. Mutta ent‰ suorituskyky? Listojen l‰pik‰ynti on raskasta, ja varsinkin jos 
		joutuu k‰ym‰‰n l‰pi useampia listoja l‰pi yhden silmukan aikana. Koodissa on kuitenkin pyritt‰
		if ja else if toiminnoilla varmistamaan ett‰ useamman ett‰ listoja k‰yt‰isiin l‰pi mahdollisimman
		v‰h‰n.
		Muutamalla kymmenell‰ asiakkaalla t‰llaisen listan l‰pi k‰yminen on viel‰ suhteellisen helppoa, 
		mutta ent‰ jos asiakkaita olisi satatuhatta? T‰llaisen listan k‰ymiseen pit‰isi olla jo algoritmi
		joka ei ottaisi listassa huomioon en‰‰, joka ei k‰visi l‰pi en‰‰ jo uuteen listaan lis‰ttyj‰ 
		asiakkaita, eli lista pienenisi joka l‰pik‰ynnin j‰lkeen. 
		Yksinkertaisin suoritus tapa j‰rjest‰miseen olis luultavasti std::sort funktion tai jonkin
		muun optimoidun algoritmin k‰ytt‰minen, mutta kurssin opetuksen kannalta halusin itse tehd‰ 
		lajittelu algoritmin...

	*/
	queue = newList;

	for (it = queue.begin(); it != queue.end(); it++)
	{
		tempPtr = *it;
		std::cout << tempPtr->getNimi() << ": " << tempPtr->getHinta() << std::endl;
	}

	it = queue.begin();
	newList.clear();
}
