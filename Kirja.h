#pragma once

class Kirja
{
public:
	string Tekija;
	string TeoksenNimi;
	int Sarjanumero;
	string UDKLuokka;
	string Kustantaja;
	int Vuosi;
	bool Lainaustilanne;

	void toString();
	

	Kirja();
	~Kirja();
};

