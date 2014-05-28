#pragma once
#include "Asiakas.h"
#include "Kirja.h"

class Kirjastoluokka
{
public:

	(map<int, Kirja*>)* KirjastonKirjat; // Map johon tallennnetaan kirjat kirjaolionpoinntterina
	(map<int, Asiakas*>)* KirjastonAsiakkaat; //Map johon tallennetaan asiakkaat asiaksoloion pointterina

	void lisaaKirja(); 
	void poistaKirja();

	void lisaaAsiakas();
	void poistaAsiakas();
	void mywait(int waittime);
	
	void naytaKaikkiKirjastonKirjat(); //Listaa mapist‰ kaikki kirjat
	
	void HaeTiettyTeos(Kirja*); //hakee sarjanumerolla yhden kirjan
	void HaeTiettyTeos(void);   //
	void AsiakkaanLainatutKirjat();
	void ListaaAsiakkaanTiedot();
	void tauko(void);

	//void lainaaKirja(Asiakas*,Kirja*); //lis‰t‰‰n kirja asikkaan lainatut kirjat mappiin
	void lainaaKirja();  
	void palautaKirja();
	void lueKirjatTiedostosta(); // Hakee tiedot kirja.txt tiedostosta
	void lueAsiakkaatTiedostosta(); // HAkee asiakkaat tiedostosta

	void ListaaKaikkiAsiakkaat(void);

	void LisaaAsiaalleSakkoa(void);
	void MaksaSakkoaPois(void);

	void PaivitaSakkoRekisteri(Asiakas*,double);
	

	Kirjastoluokka();
	~Kirjastoluokka();
};

