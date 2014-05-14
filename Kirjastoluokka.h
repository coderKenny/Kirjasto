#pragma once
#include "Asiakas.h"
#include "Kirja.h"

class Kirjastoluokka
{
public:

	(map<int, Kirja*>)* KirjastonKirjat; // Map johon tallennnetaan kirjat kirjaolionpoinntterina
	(map<int, Asiakas*>)* KirjastonAsiakkaat; //Map johon tallennetaan asiakkaat asiaksoloion pointterina

	void lisaaKirja(Kirja*); 
	void poistaKirja(Kirja*);

	void lisaaAsiakas(Asiakas*);
	void poistaAsiakas(Asiakas*);

	void naytaKaikkiKirjastonKirjat(); //Listaa mapist‰ kaikki kirjat
	
	void HaeTiettyTeos(Kirja*); //hakee sarjanumerolla yhden kirjan
	void HaeTiettyTeos(void);   //


	void tauko(void);

	void lainaaKirja(Asiakas*,Kirja*); //lis‰t‰‰n kirja asikkaan lainatut kirjat mappiin
	void lainaaKirja(Kirja*);  
	void palautaKirja();
	void lueKirjatTiedostosta(); // Hakee tiedot kirja.txt tiedostosta
	void lueAsiakkaatTiedostosta(); // HAkee asiakkaat tiedostosta

	void ListaaKaikkiAsiakkaat(void);

	
	

	Kirjastoluokka();
	~Kirjastoluokka();
};

