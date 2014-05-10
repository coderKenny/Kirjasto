#include "stdafx.h"
#include "Apuluokka.h"
#include <Windows.h> // gotoxy


//Apuluokka

Apuluokka::Apuluokka(void) // Apuluokan konstruktori
{
	kirja1= new Kirja();
}


Apuluokka::~Apuluokka(void) // Apuluokan destruktori
{
	if(kirja1)
		delete kirja1;
}


void Apuluokka::pause() // System pause funktio
{
  cout << endl << "Press enter to continue...";
  getchar();
}


void Apuluokka::gotoxy ( int column, int line )  // Liikutetaan kursoria konsolissa
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

void Apuluokka::LisaaGetCharreja(int maara) // Lisää getChar funktioita loppuun
{
	for (int i = 0; i < maara; i++)
		getchar(); // stdio.h		
}

void Apuluokka::ApuluokanLisaaKirjaFunktio(Kirjastoluokka* instantioituLuokka) // Lisää kirja
{
	// Lue tiedostosta !
	// 
	// dummy :

	kirja1->TeoksenNimi="Bible";
	kirja1->Lainaustilanne=false;
	kirja1->Vuosi=0;
	kirja1->Tekija=("God");
	kirja1->Sarjanumero=1;
	kirja1->UDKLuokka=123;
	kirja1->Kustantaja="World";

	instantioituLuokka->lisaaKirja(*kirja1);

	LuoAlkuIF();
}


void Apuluokka::ListaaKaikkiKirjat(Kirjastoluokka*  instantioituLuokka)
{
	instantioituLuokka->naytaKaikkiKirjastonKirjat();
}

void Apuluokka::KaynnistaKirjastoApplikaatio(Kirjastoluokka* instantioituLuokka) // Käynnistä karuselli
{
	LuoAlkuIF();
	while(1)
	{
		int syote;
		cin>> syote;
		if(syote==9)
			break;
		else
		{
			switch(syote)
			{
				case 1 :
				ApuluokanLisaaKirjaFunktio(instantioituLuokka);
				break;

				case 2 :
				break;
				
				case 3 :
					ListaaKaikkiKirjat(instantioituLuokka);
				break;

				case 4 : 
				break;

				case 5 :
				break;

				case 6 :
				break;

				case 7 :
				break;

				case 8:
				break;
			}
		
		}
	}
}

void Apuluokka::LuoAlkuIF() // Luo puhdas screna
{
	
	system("CLS");		// Tyhjennä ruutu, non-portable
	gotoxy(0,14);		// Tyhjennä mahdollinen vanha syöte
	cout<<"                                                                            "; // Tyhjennä rivi
	gotoxy(16,14);		// Palauta kursori syöttömoodiin
	
	gotoxy(0,0);
	cout<<endl;
	cout << "Olet kirjautunut kirjaston ohjelmistoon, mita haluat tehda ?\n\n";

	cout <<"1. Lisaa kirja kirjastoon \n";
	cout <<"2. Poista kirja kirjastosta\n";
	cout <<"3. Listaa kaikki kirjaston kirjat\n";
	cout <<"4. Hae haluttu kirja\n";
	cout <<"5. Kirjan lainaaminen asiakkaalle\n";
	cout <<"6. Palauta kirja kirjastoon\n";
	cout <<"7. Lisaa asiakas\n";
	cout <<"8. Poista asiakas\n";
	cout <<"9. Poistu\n";
	cout<<endl<<endl;

	cout<<"Syota tehtava : ";

	gotoxy(16,14);

}