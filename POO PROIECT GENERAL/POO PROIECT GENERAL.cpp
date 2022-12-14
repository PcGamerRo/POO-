#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"
#include "AchizitieBilet.h"

using namespace std;

int Eveniment::nrBileteDisponibile = 200;

int main()
{
	//Zona zona1("peluza", 50, 5);
	//Zona zona2("tribuna1", 120, 4);
	//Zona zona3("tribuna2", 160, 4);
	//Zona zone[3]={zona1, zona2, zona3};
	//Locatie locatie1("Stadion Bucuresti", 3, zone);
	//cout << locatie1.zone[0].getNrL() << endl;
	//cout << locatie1.zone[1].getNrL() << endl;
	//cout << locatie1.zone[2].getNrL() << endl;

	//Bilet tip1("796999fc-e88c-4cb4-adba-980ac8b764a8", "Peluza", 20);
	//Bilet tip2("e9259402-385d-4e4d-8b16-d7f98fb1fd63", "Tribuna", 10);
	//
	//Bilet* bilete = new Bilet[2]{tip1, tip2};
	//Eveniment eveniment1((char*)"meci fotbal", "10-DEC-2022", "20:00", 2, bilete);
	////cout << eveniment1.bilete[0].getTip() << endl;
	////cout << tip1.getTip();
	////cout << eveniment1.bilete[0].getPret() << endl;
	////cout << eveniment1.bilete[1].getPret() << endl;
	//cout << eveniment1;
	//cout << endl << tip1;
	//cout << endl << locatie1;
	//cout << endl << zona1;

	//Emitere de bilete la film din categoriile Normal sau VIP.
	//Fiecare zonă are rând și loc.Biletele se vor genera în limita locurilor disponibile.
	//Atunci când un utilizator prezintă biletul se va verifica id - ul 
	//unic al acestuia pentru a vedea dacă este valid

	/*cout << "===========   EVENIMENT #1 ===========" << endl;
	Bilet bilet1("1", "Normal", 20);
	Bilet bilet2("2", "VIP", 35);
	Bilet* bilete = new Bilet[2]{bilet1, bilet2};
	Eveniment film((char*)"film", "10-Dec-2022", "19:00", 2, bilete);
	cout << film << endl;
	cout << bilet1 << endl;
	cout << bilet2 << endl;

	int* purchase1 = new int[2]{ 2,3 };
	AchizitieBilet achizitie1(purchase1);
	cout << achizitie1.valoareAchizitie(bilete);

	cout << endl;
	cout << endl;*/
	//Emitere de bilete la teatru din categoriile Categoria 1, Categoria 2 și Lojă.
	//Fiecare zonă are rând și loc.
	//Biletele se vor genera în limita locurilor disponibile.
	//Atunci când un utilizator prezintă biletul se va verifica id - ul
	//unic al acestuia pentru a vedea dacă este valid

	/*cout << "===========   EVENIMENT #2 ===========" << endl;
	Bilet biletTeatru("1t", "Normal", 30);
	Bilet* bileteTeatru = new Bilet[1]{ biletTeatru };
	Eveniment teatru((char*)"teatru", "12-Dec-2022", "16:00", 1, bileteTeatru);
	Zona zona1("Categoria 1", 100, 5);
	Zona zona2("Categoria 2", 100, 5);
	Zona zona3("Loja", 200, 8);
	Zona* zone = new Zona[3]{ zona1, zona2, zona3 };
	Locatie locatie1("necunoscuta", 3, zone);
	cout << teatru << endl;
	cout << biletTeatru << endl;
	cout << locatie1 << endl;
	cout << zona1 << endl;
	cout << zona2 << endl;
	cout << zona3 << endl;*/

	Eveniment ev((char*)"meci", 10, 2, 2023, "20:00", 1);
	ev.zileRamase(14,12,2022);
	ev.epuizareBilete(2);

	Bilet b("123", "Normal", 23);
	b.checkValoare(10);
	b.aplicareReducereGenerala(23);

	Locatie l("Stadion Craiova", 1, 500);
	cout << endl << l.locuriNeutilizate();
	l.acordareRating(5);
	l.acordareRating(1.5);
	cout << endl << l.getRating();
	
	cout << endl;
	int* p = new int[200];
	int* locuri = new int[3]{ 5,2,3 };
	for (int i = 0; i < 200; i++) p[i] = 1;
	Zona z("zona 1", 200, 10, p);
	cout << endl << z.locuriPerRand();
	z.eliberareLocuri(locuri, 3);

	//MENIU
	bool switch_on = true;

	//do {
	//	switch (switch_on)
	//	{
	//	case 1: {
	//		cout << "-- DETALII EVENIMENT -- " << endl;
	//		Eveniment ev1; //pentru switch am nevoie de vector de obiecte, nu e bine daca il las asa
	//		cin >> ev1;
	//		cout << endl;

	//		cout << "-- DETALII BILETE -- " << endl;
	//		Bilet* b1 = new Bilet[ev1.getNrCategorii()];
	//		for (int i = 0; i < ev1.getNrCategorii(); i++) {
	//			cout << endl << "bilet " << i + 1 << ": " << endl;
	//			cin >> b1[i];
	//		}
	//		cout << endl;

	//		cout << "-- DETALII LOCATIE -- " << endl;
	//		Locatie loc1;
	//		cin >> loc1;
	//		cout << endl;

	//		cout << "--DETALII ZONE -- " << endl;
	//		Zona* z1 = new Zona[loc1.getNrZone()];
	//		for (int i = 0; i < loc1.getNrZone(); i++) {
	//			cout << endl << "zona " << i + 1 << ": " << endl;
	//			cin >> z1[i];
	//		}


	//		cout << endl << endl << endl << "Iata informatiile furnizate de dvs: " << endl << endl;

	//		cout << ev1 << endl;
	//		for (int i = 0; i < ev1.getNrCategorii(); i++) {
	//			cout << b1[i] << endl;
	//		}
	//		cout << loc1 << endl;
	//		for (int i = 0; i < loc1.getNrZone(); i++) {
	//			cout << z1[i];
	//		}
	//	}
	//	case 0:
	//		cout << "Multumim pentru timpul acordat, o zi frumoasa!";
	//	default:
	//		cout << "nu a fost recunoscuta comanda!" << endl;
	//		cout << "doriti sa reincercati? true(1)/false(0):   ";
	//		cin >> switch_on;
	//		break;
	//	}
	//	cout << endl << endl << endl << "Doriti sa inregistrati un nou eveniment? true(1)/false(0):   ";
	//	cin >> switch_on;
	//} while (switch_on == true);
	return 0;
}