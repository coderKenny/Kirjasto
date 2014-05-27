// Kirjasto.cpp : Defines the entry point for the console application.
//Kirjaston main ohjelma

#include "stdafx.h"
#include "Apuluokka.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ""); //Locale h kirjaston mukaan pakotetaan ohjelma käyttämään koneen omaa enkoodausta/lokalisoitua näppäimistöä,
	// tarvittiin että saadaan ä ja ö toimimaan.

	Kirjastoluokka* instantioituKirjastoOlio = new Kirjastoluokka();
	Apuluokka* apuluokkaOlio = new Apuluokka();
	
	instantioituKirjastoOlio->lueKirjatTiedostosta();
	instantioituKirjastoOlio->lueAsiakkaatTiedostosta();

	apuluokkaOlio->KaynnistaKirjastoApplikaatio(instantioituKirjastoOlio);

	apuluokkaOlio->LisaaGetCharreja(1);

	delete instantioituKirjastoOlio;	// Kutsu kirjastoluokan destruktoria
	delete apuluokkaOlio;		// Kutsu apuluokan destruktoria

	return 0;
}

