#pragma once
// UI varten funktioita
class Apuluokka
{
public:
	Apuluokka(void);
	~Apuluokka(void);

	void tauko();
	void gotoxy (int, int);
	void LisaaGetCharreja(int);
	void KaynnistaKirjastoApplikaatio(Kirjastoluokka*);
	void LuoAlkuIF();
	void ApuluokanLisaaKirjaFunktio(Kirjastoluokka*);
	void ListaaKaikkiKirjat(Kirjastoluokka*);

	Kirja* kirja1; //Kova koodattu kirja ennenkuin tiedosto saatiin toimimaan
	Asiakas* asiakas1; //Kovakoodattuasiakas

};

