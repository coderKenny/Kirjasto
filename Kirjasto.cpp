// Kirjasto.cpp : Defines the entry point for the console application.
//Kirjaston main ohjelma

#include "stdafx.h"
#include "Apuluokka.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Kirjastoluokka* kirjastoLuokka = new Kirjastoluokka();
	Apuluokka* apuluokka = new Apuluokka();
	

	apuluokka->KaynnistaKirjastoApplikaatio(kirjastoLuokka);

	apuluokka->LisaaGetCharreja(1);

	delete kirjastoLuokka;	// Kutsu kirjastoluokan destruktoria
	delete apuluokka;		// Kutsu apuluokan destruktoria

	return 0;
}

