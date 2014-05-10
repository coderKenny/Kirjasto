#include "stdafx.h"
#include "Kirjastoluokka.h"

Kirjastoluokka::Kirjastoluokka()
{
	KirjastonKirjat = new map<int, Kirja*>();
	KirjastonAsiakkaat = new map<int, Asiakas*>();
}


Kirjastoluokka::~Kirjastoluokka()
{
	if(KirjastonAsiakkaat)
	{
		delete KirjastonAsiakkaat;
		KirjastonAsiakkaat=nullptr;
	}
	if(KirjastonKirjat)
	{
		delete KirjastonKirjat;
		KirjastonKirjat=nullptr;
	}
}


void Kirjastoluokka::lisaaKirja(Kirja kirjaolio)
{
	KirjastonKirjat->insert(pair<int, Kirja*>(kirjaolio.Sarjanumero, &kirjaolio));
}

void Kirjastoluokka::poistaKirja(Kirja kirjaolio)
{
	KirjastonKirjat->erase(kirjaolio.Sarjanumero);
}

void Kirjastoluokka::lisaaAsiakas(Asiakas lisattavaAsiakas)
{
	KirjastonAsiakkaat->insert(pair<int, Asiakas*>(lisattavaAsiakas.Asiakasnumero, &lisattavaAsiakas));

}
void Kirjastoluokka::poistaAsiakas(Asiakas poistettavaAsiakas)
{
	KirjastonKirjat->erase(poistettavaAsiakas.Asiakasnumero);
}

void Kirjastoluokka::naytaKaikkiKirjastonKirjat() // EI TOIMI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{


	for (map<int, Kirja*>::iterator itr = KirjastonKirjat->begin(), itr_end = KirjastonKirjat->end(); itr != itr_end; ++itr)
	{
		//cout<<"Kukkuu";
		cout << itr->second->TeoksenNimi; // Crash
	}
}
