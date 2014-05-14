// Kirjasto.cpp : Defines the entry point for the console application.
//Kirjaston main ohjelma

#include "stdafx.h"
#include "Apuluokka.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, ""); //Locale h kirjaston mukaan pakotetaan ohjelma käyttämään koneen omaa enkoodausta/lokalisoitua näppäimistöä,
	// tarvittiin että saadaan ä ja ö toimimaan.

	Kirjastoluokka* kirjastoLuokka = new Kirjastoluokka();
	Apuluokka* apuluokka = new Apuluokka();
	
	kirjastoLuokka->lueKirjatTiedostosta();
	kirjastoLuokka->lueAsiakkaatTiedostosta();

	apuluokka->KaynnistaKirjastoApplikaatio(kirjastoLuokka);

	apuluokka->LisaaGetCharreja(1);

	delete kirjastoLuokka;	// Kutsu kirjastoluokan destruktoria
	delete apuluokka;		// Kutsu apuluokan destruktoria

	return 0;
}

