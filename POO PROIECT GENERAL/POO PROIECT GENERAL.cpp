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
	Eveniment event1; 
	if (1 != 0) {
		////cin >> event1;
		//cout << endl;
		////cout << event1 << endl;
		//event1.setDenumire((char*)"");
		//event1.setDenumire(nullptr);
		//event1.setDenumire((char*)"concert killa fonic");
		//event1.setNrBileteDisponibile(2000);
		//event1.setZi(16);
		//event1.setLuna(12);
		//event1.setAn(2022);
		//event1.setTime(20, 00);
		//event1.setCategoriiBilete(2);
		////cout << event1 << endl;

		//Eveniment event2 = event1;
		//cout << event2 << endl;

		//Eveniment event3((char*)"Concert Nane x Rava x Ian", 7, 1, 2023, 23, 00, 2);
		//cout << event3 << endl;

		//cout << (event2 > event3) << endl;
		//cout << (event3 > event2);

		//cout << event2 << endl;

		////Eveniment event4 = ++event2;
		//////event4 = event2++;

		////cout << event4;
		////cout << endl << event2 << endl;

		//Eveniment event4;
		//event4 = --event2;
		//cout << event4;
		//cout << endl << event2 << endl;

		//event4.epuizareBilete(2003);
		//event1.evenimentRatat(16, 12, 2022);
	}

	Bilet bilet1, bilet2("121dawd", "Regular", 2);
	if (2 != 0) {
		//Bilet bilet1, bilet2("121dawd", "Regular", 2);
		////cin >> bilet1;
		////cin >> bilet2;
		////int x;
		////cin >> x;
		//Bilet bilet3;// = bilet2;
		//cout << bilet2 << endl;
		//cout << bilet3 << endl;

		//bilet3 = bilet2;
		//cout << bilet2 << endl;
		//cout << bilet3 << endl;

		//bilet3 = bilet3 - 2;
		//cout << bilet3 << endl;
	}

	Locatie locatie1;
	if (3 != 0) {
		////cin >> locatie1;	
		////cin >> locatie2;

		//locatie1.setDenumireLocatie("Arenele Romane");
		//locatie1.setNrLocuriDisponibile(2000);
		//locatie1.setNrZone(3);
		//locatie1.setRating(3.5);

		//Locatie locatie2 = locatie1;
		//locatie2.setNrZone(10);

		//cout << locatie2.getDenumire() << endl;
		//cout << locatie2.getNrLocuriDisponobile() << endl;
		//cout << locatie2.getNrZone() << endl;
		//cout << locatie2.getRating() << endl;

		//cout << endl;

		////cout << endl;
		////cout << locatie1 << endl;
		////cout << locatie2;

		////cout << (locatie1 == locatie2);
		////cout << int(locatie1);

		//Locatie locatie3("", 0, -1, 6);
		//cout << endl << locatie3;
	}

	Zona zona5;
	if (4 != 0) {
		//int* p = new int[5]{ 0,0,1,0,1 };
		//Zona zona1("tribuna 1", 5, 1, p);
		//cout << zona1;
		//Zona zona2 = zona1;
		////cout << endl << zona2;
		//Zona zona3;
		//zona3 = zona1;
		//cout << endl << zona3;

		//zona3 = zona3 + 10;

		//cout << endl << zona3;
		//cout << endl << zona3[4] << endl;
		////zona 5:
		//cin >> zona5;
		//cout << endl << zona5;
	}

	return 0;
}