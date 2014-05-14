#include "stdafx.h"
#include "Apuluokka.h"
#include <Windows.h> // gotoxy


//Apuluokka

Apuluokka::Apuluokka(void) // Apuluokan konstruktori
{
	kirja1= new Kirja();
	asiakas1 = new Asiakas(true); // Overload to construct test
}


Apuluokka::~Apuluokka(void) // Apuluokan destruktori
{
	if(kirja1)
		delete kirja1;
}


void Apuluokka::tauko() // System pause funktio //nimeä ja suomeksi
{
  cout << endl << "Paina rivinvaihtoa";
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

void Apuluokka::ApuluokanLisaaKirjaFunktio(Kirjastoluokka* instantioituOlio) // Lisää kirja
{
	// Lue tiedostosta !
	// 
	// dummy :

	kirja1->TeoksenNimi="Bible";
	kirja1->Lainaustilanne=false;
	kirja1->Vuosi=1888;
	kirja1->Tekija=("God");
	kirja1->Sarjanumero=6;
	kirja1->UDKLuokka="UDKluokka";
	kirja1->Kustantaja="World";
	
	instantioituOlio->lisaaKirja(kirja1);

	LuoAlkuIF();
}


void Apuluokka::ListaaKaikkiKirjat(Kirjastoluokka*  instantioituLuokka)
{
	instantioituLuokka->naytaKaikkiKirjastonKirjat();
	tauko();
}



void Apuluokka::KaynnistaKirjastoApplikaatio(Kirjastoluokka* instantioituOlio) // Käynnistä karuselli
{
	LuoAlkuIF();
	while(1)
	{
		int syote;
		syote=cin.get();
		if(syote==48)
			break;
		else
		{
			switch(syote)
			{
				case 49 :
					ApuluokanLisaaKirjaFunktio(instantioituOlio);
				break;

				case 50 :
					instantioituOlio->poistaKirja(kirja1);
				break;
				
				case 51 :
					ListaaKaikkiKirjat(instantioituOlio);
				break;

				case 52 : 
					instantioituOlio->HaeTiettyTeos();
				break;

				case 53 :
					//instantioituOlio->lainaaKirja(asiakas1,kirja1);
					instantioituOlio->lainaaKirja(kirja1);
				break;

				case 54 :
					instantioituOlio->palautaKirja();
				break;

				case 55 :
					instantioituOlio->lisaaAsiakas(asiakas1);
				break;
		
				case 56:
					instantioituOlio->poistaAsiakas(asiakas1);
				break;

				case 57:
				instantioituOlio->ListaaKaikkiAsiakkaat();
				tauko();
				break;

				//case 97: // a Listaa asiakkaan lainat
				// XXX a case
				// break;

				//case 98: //b Listaa asiakkaan tiedot
				// XXX a case
				// break;

				default:
				LuoAlkuIF();
				gotoxy(16,17);
				break;

			}
		
		}

	}
}

void Apuluokka::LuoAlkuIF() // Luo puhdas screna
{
	
	system("CLS");	// Tyhjennä ruutu, non-portable
	gotoxy(0,17);		// Tyhjennä mahdollinen vanha syöte
	cout<<"                                                                            "; // Tyhjennä rivi
	gotoxy(16,17);		// Palauta kursori syöttömoodiin
	
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
	cout <<"9. Listaa kaikki asiakkaat\n";
	cout <<"a. Listaa asiakkaan lainat\n";
	cout <<"b. Listaa asiakkaan tiedot\n";
	cout <<"0. Poistu\n";
	cout<<endl<<endl;

	cout<<"Syota tehtava : ";

	gotoxy(16,17);

}