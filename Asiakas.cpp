#include "stdafx.h"
#include "Asiakas.h"

Asiakas::Asiakas()
{
	LainatutKirjat = new map<int, Kirja*>();
}

Asiakas::Asiakas(bool valitsin)
{
	Nimi="Kenneth Ekbom";
	string Osoite="Ketolankatu 5 as 18";
	string Sotu="290479-1472";
	int Asiakasnumero=123;

	LainatutKirjat = new map<int, Kirja*>();
}


void Asiakas::toString()
{
	cout << endl;
	cout << Nimi << endl;
	cout << Osoite << endl;
	cout << Sotu << endl;
	cout << Asiakasnumero << endl;
}






void Asiakas::LainaaKirja(Kirja* kirjaolio)
{
	LainatutKirjat->insert(pair<int , Kirja*>(kirjaolio->Sarjanumero, kirjaolio));
}

void Asiakas::PalautaKirja(Kirja* kirjaolio)
{
	LainatutKirjat->erase(kirjaolio->Sarjanumero);
}

Asiakas::~Asiakas()
{
	delete LainatutKirjat;
}
