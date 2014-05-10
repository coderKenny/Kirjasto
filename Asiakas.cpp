#include "stdafx.h"
#include "Asiakas.h"

Asiakas::Asiakas()
{
	LainatutKirjat = new map<int, string>();
}

void Asiakas::LainaaKirja(Kirja kirjaolio)
{
	LainatutKirjat->insert(pair<int , string>(kirjaolio.Sarjanumero, kirjaolio.TeoksenNimi));

}

void Asiakas::PalautaKirja(Kirja kirjaolio)
{
	LainatutKirjat->erase(kirjaolio.Sarjanumero);
}

Asiakas::~Asiakas()
{
	delete LainatutKirjat;
}
