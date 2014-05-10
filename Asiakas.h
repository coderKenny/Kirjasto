#pragma once
#include "Asiakas.h"
#include "Kirja.h"

class Asiakas
{
public:
	string Nimi;
	string Osoite;
	string Sotu;
	int Asiakasnumero;
	(map<int, string>)* LainatutKirjat;
	//sakko

	void Kysy();

	void LainaaKirja(Kirja kirjaolio);
	void PalautaKirja(Kirja kirjaolio);
	

	Asiakas();
	~Asiakas();
};

