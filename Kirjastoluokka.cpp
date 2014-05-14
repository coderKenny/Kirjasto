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
	int counter=0;
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

			KirjastonKirjat->insert(pair<int, Kirja*>(muodostettuKirjaOlio->Sarjanumero, muodostettuKirjaOlio));

			//tauko();
		}
		
	}
	myReadFile.close();
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


void Kirjastoluokka::lisaaKirja(Kirja* kirjaolio) // kommetti ett‰ kirja lis‰ttu ?
{
	KirjastonKirjat->insert(pair<int, Kirja*>(kirjaolio->Sarjanumero, kirjaolio));
}

//void Kirjastoluokka::poistaKirja(Kirja* kirjaolio)
void Kirjastoluokka::poistaKirja()
{
	

	cout<<"\nSyˆt‰ poistettavan kirjan sarjanumero mallilla 000,001,002....\n\n: ";

	string sarjaNumero;

	cin>>sarjaNumero;

	KirjastonKirjat->erase(stoi(sarjaNumero)); // Parse to integer

	// Poista kirja tiedostosta -->

	std::ifstream inputStream ("Kirjat.txt", std::ifstream::binary);
	if (inputStream) 
	{

	// Laske tekstifilun koko
    inputStream.seekg (0, inputStream.end);
    int length = inputStream.tellg();
    inputStream.seekg (0, inputStream.beg);

	
    // Varaa muistia koon verran
    char * buffer = new char [length];

    // Lue data sis‰‰n ja tee siit‰ stringi
    inputStream.read (buffer,length);
	string tiedostonSisalto(buffer,length);

	cout<<endl<<endl;
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
	f<<tiedostonSisalto;

	// Sulje stream
	f.close();

	// Vapauta tila heap:ist‰
    delete[] buffer;
  }
}

// void Kirjastoluokka::lisaaAsiakas(Asiakas* lisattavaAsiakas)
void Kirjastoluokka::lisaaAsiakas()
{
	Asiakas* lisattavaAsiakas = new Asiakas();

	
	getchar(); // Putsaa rivinvaihtomerkki pois
	cout<<"\nAnna uuden lis‰tt‰v‰n asiakkaan nimi : ";
	string nimi;
	getline(cin,nimi);
	string muunnettuNimi = nimi;
	replace(muunnettuNimi.begin(), muunnettuNimi.end(), ' ', '_');
	lisattavaAsiakas->Nimi=muunnettuNimi;
	
	cout<<"\n\nAnna uuden lis‰tt‰v‰n asiakkaan osoite : ";
	string osoite;
	getline(cin,osoite);
	string muunnettuOsoite = osoite;
	replace(muunnettuOsoite.begin(), muunnettuOsoite.end(), ' ', '_');
	lisattavaAsiakas->Osoite=muunnettuOsoite;
	
	cout<<"\n\nAnna uuden lis‰tt‰v‰n asiakkaan SOTU : ";
	string SOTU;
	getline(cin,SOTU);
	lisattavaAsiakas->Sotu=SOTU;


	cout<<"\n\nAnna uuden lis‰tt‰v‰n asiakkaan asiakasnumero : ";
	int asiakasNumero;
	cin>> asiakasNumero;
	lisattavaAsiakas->Asiakasnumero=asiakasNumero;


	KirjastonAsiakkaat->insert(pair<int, Asiakas*>(lisattavaAsiakas->Asiakasnumero, lisattavaAsiakas));

	ofstream outfile;

	outfile.open("Asiakas.txt", std::ios_base::app);
	outfile << "\n"<<muunnettuNimi<<","<<muunnettuOsoite<<","<<SOTU<<","<<"00"<<asiakasNumero;
	outfile.close();

}

void Kirjastoluokka::poistaAsiakas()
{
	cout<<"\nSyˆt‰ poistettavan asiakkaan asiakasnumero mallilla 000,001,002....\n\n: ";

	string sarjaNumero;

	cin>>sarjaNumero;

	KirjastonAsiakkaat->erase(stoi(sarjaNumero)); // Parse to integer



	// Poista asiakas tiedostosta -->

	std::ifstream inputStream ("Asiakas.txt", std::ifstream::binary);
	if (inputStream) 
	{

	// Laske tekstifilun koko
    inputStream.seekg (0, inputStream.end);
    int length = inputStream.tellg();
    inputStream.seekg (0, inputStream.beg);

	
    // Varaa muistia koon verran
    char * buffer = new char [length];

    // Lue data sis‰‰n ja tee siit‰ stringi
    inputStream.read (buffer,length);
	string tiedostonSisalto(buffer,length);

	cout<<endl<<endl;
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
	f<<tiedostonSisalto;

	// Sulje stream
	f.close();

	// Vapauta tila heap:ist‰
    delete[] buffer;
  }
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


void Kirjastoluokka::tauko() // System pause funktio
{
  cout << endl << "Paina Paina rivinvaihtoa";
  getchar();
}


void Kirjastoluokka::lainaaKirja(Asiakas* asiakas1,Kirja* kirja1)
{
	asiakas1->LainatutKirjat->insert(pair<int, Kirja*>(kirja1->Sarjanumero,kirja1));
	kirja1->Lainaustilanne=true;
}


void Kirjastoluokka::lainaaKirja(Kirja* kirja1)
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
			for (map<int, Asiakas*>::iterator itr2 = KirjastonAsiakkaat->begin(), itr_end = KirjastonAsiakkaat->end(); itr2 != itr_end; ++itr2)
			{
				itr->second->Lainaustilanne=true;
				itr2->second->LainatutKirjat-> insert(pair<int, Kirja*>(kirja1->Sarjanumero,kirja1));
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