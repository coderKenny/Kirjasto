// Kirjasto.cpp : Defines the entry point for the console application.
//Kirjaston main ohjelma

#include "stdafx.h"
#include "Apuluokka.h"


//mutex MyMutex;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ""); //Locale h kirjaston mukaan pakotetaan ohjelma k�ytt�m��n koneen omaa enkoodausta/lokalisoitua n�pp�imist��,
	// tarvittiin ett� saadaan � ja � toimimaan.

	Kirjastoluokka* instantioituKirjastoOlio = new Kirjastoluokka();
	Apuluokka* apuluokkaOlio = new Apuluokka();
	
	//instantioituKirjastoOlio->lueKirjatTiedostosta(); 
	//instantioituKirjastoOlio->lueAsiakkaatTiedostosta();

	cout << "Kirjasto-ohjelma k�ynnistyy \n" << endl;
	cout << "Luetaan kirjat ja asiakkaat tiedostoista \n" << endl;

	thread mytreadKirjat(&Kirjastoluokka::lueKirjatTiedostosta,instantioituKirjastoOlio);
	thread mytreadAsiakkaat(&Kirjastoluokka::lueAsiakkaatTiedostosta,instantioituKirjastoOlio);

	mytreadKirjat.join(); mytreadAsiakkaat.join();

	apuluokkaOlio->KaynnistaKirjastoApplikaatio(instantioituKirjastoOlio);

	apuluokkaOlio->LisaaGetCharreja(1);

	delete instantioituKirjastoOlio;	// Kutsu kirjastoluokan destruktoria
	delete apuluokkaOlio;		// Kutsu apuluokan destruktoria

	return 0;
}

