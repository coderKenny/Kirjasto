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
	double Sakko;

	(map<int, Kirja*>)* LainatutKirjat; //Asiakkaan lainatut kirjat

	void LainaaKirja(Kirja* kirjaolio); 
	void PalautaKirja(Kirja* kirjaolio);
	
	Asiakas();
	//Asiakas(bool);
	~Asiakas();

	void toString();

	
};

