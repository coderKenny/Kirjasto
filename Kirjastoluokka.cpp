#include "stdafx.h"
#include "Kirjastoluokka.h"

Kirjastoluokka::Kirjastoluokka()
{
	KirjastonKirjat = new map<int, Kirja*>();
	KirjastonAsiakkaat = new map<int, Asiakas*>();

}

Kirjastoluokka::~Kirjastoluokka()
{
	if(KirjastonAsiakkaat)
	{
		delete KirjastonAsiakkaat;
		KirjastonAsiakkaat=nullptr;
	}
	if(KirjastonKirjat)
	{
		delete KirjastonKirjat;
		KirjastonKirjat=nullptr;
	}

}

void Kirjastoluokka::lueKirjatTiedostosta()
{
	//int counter=0;

	ifstream myReadFile;
	myReadFile.open("Kirjat.txt");
	if (myReadFile.is_open())
	{
		//cout << "Tiedosto on auki !\n";
	}
	else
	{
		//cout << "Tiedosto on kiinni !\n";
	}

	char output[100];
	//string someString(output);
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			
			
			Kirja* muodostettuKirjaOlio = new Kirja();
			myReadFile >> output;
			string someString(output);

			unsigned pos = someString.find(",");
			string osaString = someString.substr(0, pos);
			string Tekija = osaString;

			osaString = someString.substr(pos+1);
			unsigned pos2 = osaString.find(",");
			osaString = osaString.substr(0, pos2);
			string KirjanNimi=osaString;

			string someString1 = someString.substr(pos + pos2+2);
			unsigned pos3 = someString1.find(",");
			osaString = someString1.substr(0,pos3);

			string Sarjanumero = osaString;

			string someString2 = someString.substr(pos + pos2 + pos3+3);
			unsigned pos4 = someString2.find(",");
			osaString = someString2.substr(0, pos4);

			string UDKLuokka = osaString;

			string someString3 = someString.substr(pos + pos2 + pos3 + pos4+4);
			unsigned pos5 = someString3.find(",");
			osaString = someString3.substr(0, pos5);

			string Kustantaja = osaString;

			string someString4 = someString.substr(pos + pos2 + pos3 + pos4 + pos5 +5);
			unsigned pos6 = someString4.find(",");
			osaString = someString4.substr(0, pos6);

			string Vuosi = osaString;

			string someString5 = someString.substr(pos + pos2 + pos3 + pos4 + pos5 + pos6 +6);
			unsigned pos7 = someString5.find(",");
			osaString = someString5.substr(0, pos7);

			string Lainaustilanne = osaString; 



			//cout << Tekija << endl;
			string muunnettu = Tekija;
			replace(muunnettu.begin(), muunnettu.end(), '_', ' '); // replace all '_' to ' '
			muodostettuKirjaOlio->Tekija = muunnettu;

			//cout << KirjanNimi<< endl;
			muunnettu = KirjanNimi;
			replace(muunnettu.begin(), muunnettu.end(), '_', ' ');
			muodostettuKirjaOlio->TeoksenNimi = muunnettu;

			//cout << Sarjanumero<< endl;
			muodostettuKirjaOlio->Sarjanumero = atoi(Sarjanumero.c_str());

			//cout << UDKLuokka << endl;
			muodostettuKirjaOlio->UDKLuokka = UDKLuokka;

			//cout << Kustantaja << endl;
			muunnettu = Kustantaja;
			replace(muunnettu.begin(), muunnettu.end(), '_', ' ');
			muodostettuKirjaOlio->Kustantaja = muunnettu;

			//cout << Vuosi << endl;
			muodostettuKirjaOlio->Vuosi = atoi(Vuosi.c_str());//stoi parempi¥?
			//cout << Lainaustilanne << endl;
			 
			if (Lainaustilanne == "true")
				muodostettuKirjaOlio->Lainaustilanne = true;
			else 
				muodostettuKirjaOlio->Lainaustilanne = false;


			// EOF tulee liian myˆh‰‰n !! Lukee tyhj‰‰ kirjaa
			if(Tekija=="" && KirjanNimi=="")
			{
				// Purkkakorjaus virheeseen :
				// DO NOT INSERT THIS BLANK BOOK TO MAP
			}

			else
				KirjastonKirjat->insert(pair<int, Kirja*>(muodostettuKirjaOlio->Sarjanumero, muodostettuKirjaOlio));

		}

	
		
	}
}
void Kirjastoluokka::lueAsiakkaatTiedostosta()
{
	int counter = 0;
	ifstream myReadFile;
	myReadFile.open("Asiakas.txt");
	if (myReadFile.is_open())
	{
		//cout << "Tiedosto on auki !\n";
	}
	else
	{
		//cout << "Tiedosto on kiinni !\n";
	}

	char output[100];
	//string someString(output);
	if (myReadFile.is_open())
	{
		while (!myReadFile.eof())
		{
			// Ville Virtanen, Katu 1 Salo, 230694 - 0621, 001
			//string Nimi;Osoite;Sotu;Asiakasnumero;
			Asiakas* muodostettuAsiakasOlio = new Asiakas();
			myReadFile >> output;
			string someString(output);

			unsigned pos = someString.find(",");
			string osaString = someString.substr(0, pos);
			string Nimi = osaString;

			osaString = someString.substr(pos + 1);
			unsigned pos2 = osaString.find(",");
			osaString = osaString.substr(0, pos2);
			string Osoite = osaString;

			string someString1 = someString.substr(pos + pos2 + 2);
			unsigned pos3 = someString1.find(",");
			osaString = someString1.substr(0, pos3);

			string Sotu = osaString;

			string someString2 = someString.substr(pos + pos2 + pos3 + 3);
			unsigned pos4 = someString2.find(",");
			osaString = someString2.substr(0, pos4);

			string Asiakasnumero = osaString;


			string someString3 = someString.substr(pos + pos2 + pos3 + pos4 + 4);
			unsigned pos5 = someString3.find(",");
			osaString = someString3.substr(0, pos5);

			string Sakko = someString3;

			
			muodostettuAsiakasOlio->Sakko=stod(Sakko);
			

			double koe = muodostettuAsiakasOlio->Sakko;

			//cout << Nimi << endl;
			string muunnettu = Nimi;
			replace(muunnettu.begin(), muunnettu.end(), '_', ' ');
			/*replace(muunnettu.begin(), muunnettu.end(), 'ı', 'o');*/

			/*	string input =muunnettu;
				string temp;
				char ctemp;
				int ascii = 0;
				
				for (int i = 0; i < input.size(); i++) // Loop through the inputted string
				{


					ctemp = input[i];
					cout << ctemp << endl;
					ascii = (int)ctemp;
		          //if(ctemp >= 97) // Check to see if it's upper or lower
					cout << ascii << endl;

				}*/

			muodostettuAsiakasOlio->Nimi = muunnettu;

			//cout << Osoite<< endl;
			muunnettu = Osoite;
			replace(muunnettu.begin(), muunnettu.end(), '_', ' ');
			muodostettuAsiakasOlio->Osoite = muunnettu;

			//cout << Sarjanumero<< endl;
			muodostettuAsiakasOlio->Sotu = Sotu; 

			//cout << UDKLuokka << endl;
			muodostettuAsiakasOlio->Asiakasnumero = atoi(Asiakasnumero.c_str());
			
			KirjastonAsiakkaat->insert(pair<int, Asiakas*>(muodostettuAsiakasOlio->Asiakasnumero, muodostettuAsiakasOlio));

			//tauko();
		}

	}
	myReadFile.close();
}
void Kirjastoluokka::lisaaKirja() 
{
	Kirja* lisattavaKirja = new Kirja();


	getchar(); // Putsaa rivinvaihtomerkki pois
	cout << "\nAnna uuden lis‰tt‰v‰n kirjan tekij‰ : ";
	string nimi;
	getline(cin, nimi);
	string muunnettuNimi = nimi;
	replace(muunnettuNimi.begin(), muunnettuNimi.end(), ' ', '_');
	lisattavaKirja->Tekija = muunnettuNimi;

	cout << "\n\nAnna uuden lis‰tt‰v‰n teoksen nimi : ";
	string teoksennimi;
	getline(cin, teoksennimi);
	string muunnettuteoksennimi = teoksennimi;
	replace(muunnettuteoksennimi.begin(), muunnettuteoksennimi.end(), ' ', '_');
	lisattavaKirja->TeoksenNimi = muunnettuteoksennimi;

	cout << "\n\nAnna uuden lis‰tt‰v‰n kirjan sarjanumero muotoa 00X : ";
	string sarjanumero;
	getline(cin, sarjanumero);
	lisattavaKirja->Sarjanumero = stoi(sarjanumero);

	cout << "\n\nAnna uuden lis‰tt‰v‰n kirjan UDK Luokka : ";
	string UDK;
	getline(cin,UDK);
	lisattavaKirja->UDKLuokka = UDK;


	cout << "\n\nAnna uuden lis‰tt‰v‰n kirjan kustantaja : ";
	string kustantaja;
	getline(cin, kustantaja);
	string muunnettukustantaja = kustantaja;
	replace(muunnettukustantaja.begin(), muunnettukustantaja.end(), ' ', '_');
	lisattavaKirja->Kustantaja = muunnettukustantaja;

	cout << "\n\nAnna uuden lis‰tt‰v‰n kirjan julkaisuvuosi : ";
	string vuosi;
	cin >> vuosi;
	lisattavaKirja->Vuosi = stoi(vuosi);

	lisattavaKirja->Lainaustilanne = false;


	KirjastonKirjat->insert(pair<int, Kirja*>(lisattavaKirja->Sarjanumero, lisattavaKirja));

	ofstream outfile;

	outfile.open("Kirjat.txt", std::ios_base::app);
	outfile << "\n" << muunnettuNimi << "," << muunnettuteoksennimi << "," << sarjanumero << "," << UDK << "," << muunnettukustantaja << "," << vuosi << "," << "false";
	outfile.close();

	cout << "\nKirja lis‰tty kirjastoon" << endl;
	lisattavaKirja->toString();

	getchar();
	tauko();
}

//void Kirjastoluokka::poistaKirja(Kirja* kirjaolio)
void Kirjastoluokka::poistaKirja()
{
	cout << "\nSyˆt‰ poistettavan kirjan sarjanumero mallilla 000,001,002....\n\n: ";

	string sarjaNumero;

	cin >> sarjaNumero;

	

	std::map<int, Kirja*>::iterator it;

	int numero = stoi(sarjaNumero);

	it = KirjastonKirjat->find(numero);
	
	if ( KirjastonKirjat->find(numero) == KirjastonKirjat->end() ) // Iteraattori rullaa loppuun
	{
		cout << "\nKirjaa ei lˆytynyt kirjastosta\n";
		tauko();
	} 
	
	else 
	{
		cout << "\nKirja poistettu kirjastosta" << endl;
		tauko();
	

	//KirjastonKirjat[stoi(sarjaNumero)].;

	
	KirjastonKirjat->erase(stoi(sarjaNumero)); // Parse to integer

	// Poista kirja tiedostosta -->

	std::ifstream inputStream("Kirjat.txt", std::ifstream::binary);
	if (inputStream)
	{

		// Laske tekstifilun koko
		inputStream.seekg(0, inputStream.end);
		int length = inputStream.tellg();
		inputStream.seekg(0, inputStream.beg);


		// Varaa muistia koon verran
		char * buffer = new char[length];

		// Lue data sis‰‰n ja tee siit‰ stringi
		inputStream.read(buffer, length);
		string tiedostonSisalto(buffer, length);

		cout << endl << endl;
		//cout<<tiedostonSisalto;

		// http://stackoverflow.com/questions/8247102/how-to-remove-a-line-from-a-string-with-large-content-in-c

		// Poista rivi kahden rivinvaihdon v‰list‰
		size_t nFPos = tiedostonSisalto.find(sarjaNumero);
		size_t secondNL = tiedostonSisalto.find('\n', nFPos);
		size_t firstNL = tiedostonSisalto.rfind('\n', nFPos);

		//cout << "Original string: " << '\n' << tiedostonSisalto << '\n' << endl;

		

		tiedostonSisalto.erase(firstNL, secondNL - firstNL);


		//cout << "Modified string: " << '\n' << tiedostonSisalto << endl;

		// Sulje inputStrem
		inputStream.close();

		// Avaa tiedosto ja tyhjenn‰ se 
		std::fstream f;
		f.open("Kirjat.txt", std::fstream::out | std::fstream::trunc);


		// Kirjoita data takaisin tiedostoon / streamiin
		f << tiedostonSisalto;

		// Sulje stream
		f.close();

		// Vapauta tila heap:ist‰
		delete[] buffer;
		
	}
	}
}

// void Kirjastoluokka::lisaaAsiakas(Asiakas* lisattavaAsiakas)
void Kirjastoluokka::lisaaAsiakas()
{
	Asiakas* lisattavaAsiakas = new Asiakas();


	getchar(); // Putsaa rivinvaihtomerkki pois
	cout << "\nAnna uuden lis‰tt‰v‰n asiakkaan nimi : ";
	string nimi;
	getline(cin, nimi);
	string muunnettuNimi = nimi;
	replace(muunnettuNimi.begin(), muunnettuNimi.end(), ' ', '_');
	lisattavaAsiakas->Nimi = muunnettuNimi;

	cout << "\n\nAnna uuden lis‰tt‰v‰n asiakkaan osoite : ";
	string osoite;
	getline(cin, osoite);
	string muunnettuOsoite = osoite;
	replace(muunnettuOsoite.begin(), muunnettuOsoite.end(), ' ', '_');
	lisattavaAsiakas->Osoite = muunnettuOsoite;

	cout << "\n\nAnna uuden lis‰tt‰v‰n asiakkaan SOTU : ";
	string SOTU;
	getline(cin, SOTU);
	lisattavaAsiakas->Sotu = SOTU;


	cout << "\n\nAnna uuden lis‰tt‰v‰n asiakkaan asiakasnumero : ";
	int asiakasNumero;
	cin >> asiakasNumero;
	lisattavaAsiakas->Asiakasnumero = asiakasNumero;


	double sakko=0.00;
	lisattavaAsiakas->Sakko=sakko;


	KirjastonAsiakkaat->insert(pair<int, Asiakas*>(lisattavaAsiakas->Asiakasnumero, lisattavaAsiakas));

	ofstream outfile;

	outfile.open("Asiakas.txt", std::ios_base::app);
	outfile << "\n" << muunnettuNimi << "," << muunnettuOsoite << "," << SOTU << "," << "00" << asiakasNumero<<","<<sakko;
	outfile.close();

}

void Kirjastoluokka::poistaAsiakas()
{
	cout << "\nSyˆt‰ poistettavan asiakkaan asiakasnumero mallilla 000,001,002....\n\n: ";

	string sarjaNumero;

	cin >> sarjaNumero;

	

	std::map<int, Asiakas*>::iterator it;

	int numero = stoi(sarjaNumero);

	it = KirjastonAsiakkaat->find(numero);
	
	if ( KirjastonAsiakkaat->find(numero) == KirjastonAsiakkaat->end() ) // Iteraattori rullaa loppuun
	{
		cout << "\nAsiakasta ei lˆytynyt kirjastosta\n";
		tauko();
	} 
	
	else 
	{
		cout << "\nAsiakas on poistettu kirjaston j‰rjestelm‰st‰" << endl;
		tauko();


		KirjastonAsiakkaat->erase(numero); // Parse to integer

	// Poista asiakas tiedostosta -->

	std::ifstream inputStream("Asiakas.txt", std::ifstream::binary);
	if (inputStream)
	{

		// Laske tekstifilun koko
		inputStream.seekg(0, inputStream.end);
		int length = inputStream.tellg();
		inputStream.seekg(0, inputStream.beg);


		// Varaa muistia koon verran
		char * buffer = new char[length];

		// Lue data sis‰‰n ja tee siit‰ stringi
		inputStream.read(buffer, length);
		string tiedostonSisalto(buffer, length);

		cout << endl << endl;
		//cout<<tiedostonSisalto;

		// http://stackoverflow.com/questions/8247102/how-to-remove-a-line-from-a-string-with-large-content-in-c

		// Poista rivi kahden rivinvaihdon v‰list‰
		size_t nFPos = tiedostonSisalto.find(sarjaNumero);
		size_t secondNL = tiedostonSisalto.find('\n', nFPos);
		size_t firstNL = tiedostonSisalto.rfind('\n', nFPos);

		//cout << "Original string: " << '\n' << tiedostonSisalto << '\n' << endl;

		tiedostonSisalto.erase(firstNL, secondNL - firstNL);


		//cout << "Modified string: " << '\n' << tiedostonSisalto << endl;

		// Sulje inputStrem
		inputStream.close();

		// Avaa tiedosto ja tyhjenn‰ se 
		std::fstream f;
		f.open("Asiakas.txt", std::fstream::out | std::fstream::trunc);


		// Kirjoita data takaisin tiedostoon / streamiin
		f << tiedostonSisalto;

		// Sulje stream
		f.close();

		// Vapauta tila heap:ist‰
		delete[] buffer;
	}

	} // End else
}

void Kirjastoluokka::naytaKaikkiKirjastonKirjat() //
{
	for (map<int, Kirja*>::iterator itr = KirjastonKirjat->begin(), itr_end = KirjastonKirjat->end(); itr != itr_end; ++itr)
	{
		
		//cout << itr->second->TeoksenNimi; 
		itr->second->toString();
	}
}

void Kirjastoluokka::HaeTiettyTeos()
{
	cout<<"Anna Sarjanumero : ";
	int sarjaNumero;
	cin>>sarjaNumero;

	for (map<int, Kirja*>::iterator itr = KirjastonKirjat->begin(), itr_end = KirjastonKirjat->end(); itr != itr_end; ++itr)
	{
		if(itr->second->Sarjanumero==sarjaNumero)
		{
			itr->second->toString();
		}
	}
	tauko();
}

void Kirjastoluokka :: AsiakkaanLainatutKirjat()
{
	cout << "\nAnna asiakasnumero : ";
	int asiakasNumero;
	cin >> asiakasNumero;

	for (map<int, Asiakas*>::iterator itr2 = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr2 != itr_end; ++itr2)
	{
		if (itr2->second->Asiakasnumero == asiakasNumero)
		{
			if (itr2->second->LainatutKirjat->empty())
				cout << "\nAsiakkaalla "<< itr2->second->Nimi  <<" ei ole lainoja\n";
			for (map<int, Kirja*>::iterator itr3 = (itr2->second->LainatutKirjat)->begin(), itr_end = (itr2->second->LainatutKirjat)->end(); itr3 != itr_end; ++itr3)
			{
				itr3->second->toString();
			}		
		}
	}
	tauko();
}

void Kirjastoluokka::tauko() // System pause funktio
{
  cout << endl << "Paina rivinvaihtoa";
  getchar();
}



void Kirjastoluokka::lainaaKirja() 
{
	cout<<"Anna asiakasnumero : ";
	int asiakasNumero;
	cin>>asiakasNumero;

	cout<<"Anna kirjan sarjanumero : ";
	int sarjaNumero;
	cin>>sarjaNumero;

	for (map<int, Kirja*>::iterator itr = KirjastonKirjat->begin(), itr_end = KirjastonKirjat->end(); itr != itr_end; ++itr)
	{

		if(itr->second->Sarjanumero==sarjaNumero)
		{
			itr->second->Lainaustilanne = true;

			for (map<int, Asiakas*>::iterator itr2 = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr2 != itr_end; ++itr2)
			{
				if (itr2->second->Asiakasnumero == asiakasNumero)
				{
					itr2->second->LainatutKirjat->insert(pair<int, Kirja*>(itr->second->Sarjanumero, itr->second));
				}
				//itr2->second->LainatutKirjat-> insert(pair<int, Kirja*>(kirja1->Sarjanumero,kirja1));
			}
		}
	}
}

void Kirjastoluokka::palautaKirja()
{
	cout<<"Anna asiakasnumero : ";
	int asiakasNumero;
	cin>>asiakasNumero;

	cout<<"Anna kirjan sarjanumero : ";
	int sarjaNumero;
	cin>>sarjaNumero;

	for (map<int, Kirja*>::iterator itr = KirjastonKirjat->begin(), itr_end = KirjastonKirjat->end(); itr != itr_end; ++itr)
	{
		//cout<<"Kukkuu";
		if(itr->second->Sarjanumero==sarjaNumero)
		{
			for (map<int, Asiakas*>::iterator itr2 = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr2 != itr_end; ++itr2)
			{
				itr->second->Lainaustilanne=false;
				itr2->second->LainatutKirjat->erase(sarjaNumero);
			}
		}
	}
}

void Kirjastoluokka::ListaaKaikkiAsiakkaat(void)
{
	for (map<int, Asiakas*>::iterator itr = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr != itr_end; ++itr)
	{

		//cout << itr->second->TeoksenNimi; 
		itr->second->toString();
	}

}
void Kirjastoluokka::ListaaAsiakkaanTiedot()
{
	cout << "\nAnna asiakasnumero : ";
	int asiakasNumero;
	cin >> asiakasNumero;

	
	for (map<int, Asiakas*>::iterator itr = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr != itr_end; ++itr)
	{
		if (itr->second->Asiakasnumero == asiakasNumero)
		{

			itr->second->toString();
			tauko();
		}
	}
}

void Kirjastoluokka::LisaaAsiaalleSakkoa(void)
{
	cout<<"\nAnna sakotettavan asiakkaan asiakasnumero : ";
	int numba;
	cin>>numba;

	bool sakotettavaLoytyi=false;

	for (map<int, Asiakas*>::iterator itr = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr != itr_end; ++itr)
	{
		if (itr->second->Asiakasnumero == numba)
		{
			cout<<"\n\nAnna sakon suuruus : ";
			int sakko;
			cin>>sakko;

			sakotettavaLoytyi=true;
			itr->second->Sakko+=sakko;
			PaivitaSakkoRekisteri(itr->second,sakko);
		}
	}

	if(!sakotettavaLoytyi)
	{
		cout<<"\nAsiakasta ei lˆytynyt kyseisell‰ asiakasnumerolla !\n";
	}
	tauko();

	// booleanin elinik‰ p‰‰ttyy ja resetoituu
}


void Kirjastoluokka::MaksaSakkoaPois(void)
{
	cout<<"\nAnna sakotettavan asiakkaan asiakasnumero : ";
	int numba;
	cin>>numba;

	bool maksajaLoytyi=false;

	for (map<int, Asiakas*>::iterator itr = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr != itr_end; ++itr)
	{
		if (itr->second->Asiakasnumero == numba)
		{
			maksajaLoytyi=true;
			cout<<"\n\nAnna takaisin maksettavan sakon suuruus\n";
			cout<<"MAX "<<itr->second->Sakko <<" : ";

			int sakko;
			cin>>sakko;

			if(sakko>=itr->second->Sakko)
				itr->second->Sakko=0;
		
			else
			{
				itr->second->Sakko-=sakko;
			}
			PaivitaSakkoRekisteri(itr->second,sakko);
		}
	}

	if(!maksajaLoytyi)
	{
		cout<<"\nAsiakasta ei lˆytynyt kyseisell‰ asiakasnumerolla !\n";
	}
	tauko();

	// booleanin elinik‰ p‰‰ttyy ja resetoituu
}



void Kirjastoluokka::PaivitaSakkoRekisteri(Asiakas* asiakas,double palautus)
{
	// Poista asiakas tiedostosta -->

	ifstream inputStream("Asiakas.txt", std::ifstream::binary);
	if (inputStream)
	{
		// Laske tekstifilun koko
		inputStream.seekg(0, inputStream.end);
		int length = inputStream.tellg();
		inputStream.seekg(0, inputStream.beg);


		// Varaa muistia koon verran
		char * buffer = new char[length];

		// Lue data sis‰‰n ja tee siit‰ stringi
		inputStream.read(buffer, length);
		string tiedostonSisalto(buffer, length);

		cout << endl << endl;

		size_t aloitusRivi = tiedostonSisalto.find(asiakas->Sotu);


		// Haetaan sakon paikkaa pilkkujen avulla
		size_t ekaPilkku = tiedostonSisalto.find(',',aloitusRivi+1);
		ekaPilkku = tiedostonSisalto.find(',',ekaPilkku+1);
		size_t vikaPilkku = tiedostonSisalto.find(',',ekaPilkku+1);
		

		// Haetaan vika nolla
		size_t rivinLoppu = tiedostonSisalto.find_last_of('0');
		
		// Poista vanha sakko
		tiedostonSisalto.erase(ekaPilkku,rivinLoppu);

		


		if(asiakas->Sakko!=0) // Saldoa j‰ljell‰
		{
			tiedostonSisalto.append(",");
			tiedostonSisalto.append(to_string(asiakas->Sakko));

			rivinLoppu = tiedostonSisalto.find_last_of('0');
			tiedostonSisalto.erase(rivinLoppu-2,rivinLoppu);  // "Luotetaan" ett‰ double lyˆ liikanollia aina saman verran !

		}

		else // Saldo 0
		{
			tiedostonSisalto.append(",");
			tiedostonSisalto.append("0");
		}

		// Sulje inputStrem
		inputStream.close();

		// Avaa tiedosto ja tyhjenn‰ se 
		std::fstream f;
		f.open("Asiakas.txt", std::fstream::out | std::fstream::trunc);


		// Kirjoita data takaisin tiedostoon / streamiin
		f << tiedostonSisalto;

		// Sulje stream
		f.close();

		// Vapauta tila heap:ist‰
		delete[] buffer;
	}
}