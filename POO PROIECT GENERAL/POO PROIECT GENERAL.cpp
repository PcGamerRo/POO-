#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"

using namespace std;

int Eveniment::nrBileteDisponibile = 200;
int Locatie::nrLocuriDisponibile = 600;

int main()
{	
	//		VERIFICARE FUNCTIONALITATE CLASE
	cout << "VERIFICARE FUNCTIONALITATE CLASE" << endl;
	int verifClase = 1;
	cout << "1 -Eveniment" << endl;
	cout << "2 -Bilet" << endl;
	cout << "3 -Locatie" << endl;
	cout << "4 -Zona" << endl;
	cin >> verifClase;
	switch (verifClase)
	{
	case 1: {
		//Clasa Eveniment.h
		Eveniment event2((char*)"Meci Fotbal", 22, 03, 2023, 20, 30, 2);
		Eveniment event3((char*)"Concert rock", 18, 01, 2023, 17, 00, 1);
		cout << event2;
		event2.evenimentRatat(18, 12, 2022); //metoda1
		event2.epuizareBilete(15); //metoda2 - statica
		cout << "Bilete ramase: " << event2.getBileteDisp() << endl;
		cout << event2;

		if ((event3 > event2) == 1)
			cout << "Evenimentul 2 incepe mai tarziu decat evenimentul 1" << endl;
		else
			cout << "Evenimentul 2 NU incepe mai tarziu decat evenimentul 1" << endl;
		cout << endl << "getZi(): " << endl;
		cout << "event3		" << event3.getZi() << endl;
		cout << "event2		" << event2.getZi() << endl;
		event3 = ++event2;
		cout << endl << "Dupa preincrementare: event3 = ++event2 " << endl;
		cout << "event3		" << event3.getZi() << endl;
		cout << "event2		" << event2.getZi() << endl;
		event3 = event2++;
		cout << endl << "Dupa postincrementare: event3 = event2++ " << endl;
		cout << "event3		" << event3.getZi() << endl;
		cout << "event2		" << event2.getZi() << endl;
		break;
	}
	case 2: {
		//Clasa Bilet.h
		Bilet bilet2("0b1cadf5", "Normal", 20);
		cout << bilet2;
		bilet2.checkValoare(50); //suma totala pentru 50 de bilete
		bilet2.aplicareReducereGenerala(10); //10% reducere
		cout << bilet2;
		bilet2 = bilet2 + 5;
		cout << "bilet2 = bilet2 + 5  = " << bilet2.getPret() << endl;
		bilet2 = bilet2 - 4;
		cout << "bilet2 = bilet2 - 4 = " << bilet2.getPret();
		break;
	}
	case 3: {
		//Clasa Locatie.h
		Locatie locatie2("stadion Suceava", 2, 650, 4.5);
		Locatie locatie3("gara de nord", 1, 1000, 3.5);
		cout << locatie2;
		cout << locatie3;
		cout << "locatie2.locuriNeutilizate() (adica locuri - bilete disponibile,200)  = " << locatie2.locuriNeutilizate() << endl;
		cout << "(locatie2 == locatie3) = " <<  (locatie2 == locatie3) << endl;
		cout << "int(locatie2)  " << int(locatie2) << endl;
		break;
	}
	case 4: {
		//Clasa Zona.h
		int* locuri = new int[20];
		for (int i = 0; i < 20; i++)
			locuri[i] = 1;
		Zona zona2("tribuna", 20, 2, locuri);
		cout << zona2;
		cout << endl << "zona2[0] este " << zona2[0] << endl;
		cout << "zona2.locuriPerRand()  => " << zona2.locuriPerRand() << endl;
		zona2 = zona2 + 5;
		cout << zona2;
		cout << "(au fost adaugate 5 locuri libere, adica locOcupat[i] = 0 )";
		break;
	}
	default:
		break;
	}
	
	// VERIFICARE CITIRE + AFISARE
	cout << endl;
	cout << endl <<  "VERIFICARE CITIRE + AFISARE";
	bool switch_on;
	cout << endl << endl << "Doriti sa verificati citirea obiectelor din clase? " << endl;
	cout << "1-da / 0-nu:	";
	cin >> switch_on;
	switch (switch_on)
	{
	case 1:
	{
		Eveniment event1;
		cin.get();
		cin >> event1;
		Bilet* bilet1 = new Bilet[event1.getNrCategorii() * sizeof(bilet1)];
		for (int i = 0; i < event1.getNrCategorii(); i++) {
			cout << endl << "Info bilet " << i + 1 << endl;
			cin >> bilet1[i];
		}
		cout << endl;
		Locatie locatie1;
		cin >> locatie1;
		Zona* zona1 = new Zona[locatie1.getNrZone() * sizeof(zona1)];
		for (int i = 0; i < locatie1.getNrZone(); i++) {
			cout << endl << "Info zona " << i + 1 << endl;
			cin >> zona1[i];
		}

		cout << endl << " ####################### Iata ce informatii au fost furnizate: ############################  " << endl;
		cout << event1;
		for (int i = 0; i < event1.getNrCategorii(); i++) {
			cout << endl << "Info bilet " << i + 1 << endl;
			cout << bilet1[i];
		}
		cout << locatie1;
		for (int i = 0; i < locatie1.getNrZone(); i++) {
			cout << endl << "Info Zona " << i + 1 << endl;
			cout << zona1[i];
		}
	}
	case 0:
	default:
		break;
	}

	/*bool switch_on = 1;
	int switch_on2 = 1;
	cout << "doriti sa realizati modificari asupra datelor citite? 1-da/0-nu   : ";
	cin >> switch_on;
	switch (switch_on)
	{
	case 1: {
		cout << "Alegeti clasa asupra carei sa realizati modificari: " << endl;
		cout << "0 - M-am razgandit, nu vreau sa realizez modificari!" << endl;
		cout << "1 -Eveniment" << endl;
		cout << "2 -Bilet" << endl;
		cout << "3 -Locatie" << endl;
		cout << "4 -Zona" << endl;
		cin >> switch_on2;
		switch (switch_on2)
		{
		case 0: 
			cout << "nu ati ales nicio modificare" << endl;
		case 1:
			cout << "ati modificat clasa 1" << endl;
		case 2:
			cout << "ati modificat clasa 2" << endl;
		case 3:
			cout << "ati modificat clasa 3" << endl;
		case 4:
			cout << "ati modificat clasa 4" << endl;
		default:
			break;
		}
	}
	case 0:
	default:
		break;
	}*/

	return 0;
}