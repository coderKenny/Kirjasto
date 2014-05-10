#pragma once
class Apuluokka
{
public:
	Apuluokka(void);
	~Apuluokka(void);

	void pause();
	void gotoxy (int, int);
	void LisaaGetCharreja(int);
	void KaynnistaKirjastoApplikaatio(Kirjastoluokka*);
	void LuoAlkuIF();
	void ApuluokanLisaaKirjaFunktio(Kirjastoluokka*);
	void ListaaKaikkiKirjat(Kirjastoluokka*);

	Kirja* kirja1;

};

