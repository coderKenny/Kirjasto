#pragma once
#include "Asiakas.h"
#include "Kirja.h"

class Kirjastoluokka
{
public:

	(map<int, Kirja*>)* KirjastonKirjat;
	(map<int, Asiakas*>)* KirjastonAsiakkaat;

	void lisaaKirja(Kirja);
	void poistaKirja(Kirja);

	void lisaaAsiakas(Asiakas);
	void poistaAsiakas(Asiakas);

	void naytaKaikkiKirjastonKirjat();

	Kirjastoluokka();
	~Kirjastoluokka();
};

