#include "stdafx.h"
#include "Kirja.h"

Kirja::Kirja()
{
}

void Kirja::toString() 
{
	
	cout<<endl;
	cout << Tekija << endl;
	cout << TeoksenNimi << endl;
	cout << Sarjanumero << endl;
	cout << UDKLuokka << endl;
	cout << Kustantaja << endl;
	cout << Vuosi << endl;
	if (Lainaustilanne == true)
		cout << "Lainaustieto : Lainassa " << endl;
	else
		cout << "Lainaustieto : Lainattavissa "<<endl;

}

Kirja::~Kirja()
{
}
