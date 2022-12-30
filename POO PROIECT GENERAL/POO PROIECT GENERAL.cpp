#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"
#include "Generator.h"
#include <fstream>
#include <Windows.h>

using namespace std;

int Bilet::nrBileteDisponibile = 0;
int Zona::nrLocuriDisponibile = 0;
 
void meniu();
void meniu2();

int main()
{
	int k;
	Eveniment ev;
	cin >> ev;
	int categoriiBilete = ev.getNrCategorii();
	Bilet bilete[100];
	for (int i = 0; i < categoriiBilete; i++) {
		cin >> bilete[i];
	}
	Locatie loc;
	cin >> loc;
	Zona zone[100];
	int categoriiZone = loc.getNrZone();
	for (int i = 0; i < categoriiZone; i++) {
		cin >> zone[i];
	}
	cout << endl << "bilete disp = " << Bilet::getNrBilete();
	cout << endl << "locuri disp = " << Zona::getNrLocuriDisponobile() << endl;
	while(Bilet::getNrBilete() > Zona::getNrLocuriDisponobile()) {
		cout << "Nu pot fi mai multe bilete decat locuri! Va rugam, reintroduceti numarul de bilete, respectiv locuri: " << endl;
		Bilet::setNrBilete(0);
		Zona::setNrLocuriDisponibile(0);
		for (int i = 0; i < categoriiBilete; i++) {
			cout << "numar exemplare bilet " << i + 1 << ":";
			cin >> k;
			bilete[i].setNumar(k);
			cout << endl;
		}
		for (int i = 0; i < categoriiZone; i++) {
			cout << "numar locuri zona " << i + 1 << ":";
			cin >> k;
			zone[i].setNrLocuri(k);
			cout << endl;
		}
		cout << endl << "bilete disp = " << Bilet::getNrBilete();
		cout << endl << "locuri disp = " << Zona::getNrLocuriDisponobile() << endl;
	}
	meniu();
	Generator gen;
	gen.genereazaBilete(bilete, categoriiBilete, zone, categoriiZone);
	return 0;
}

void meniu() {
	Sleep(200);
	cout << "M";
	Sleep(200);
	cout << "E";
	Sleep(200);
	cout << "N";
	Sleep(200);
	cout << "I";
	Sleep(200);
	cout << "U";
	Sleep(1000);

	cout << endl;

	system("CLS");
	int k = 0;
	while (k < 5)
	{
		cout << "LOADING";
		Sleep(30);
		cout << " _ ";
		Sleep(30);
		cout << "_ ";
		Sleep(30);
		cout << "_ ";
		Sleep(30);
		cout << "_ ";
		Sleep(30);
		cout << "_ ";
		Sleep(30);
		cout << "_ ";
		Sleep(30);
		cout << "_ ";
		system("CLS");
		k++;
	}
	Sleep(500);

}
void meniu2() {
	Eveniment e1((char*)"meci fotbal", 27, 12, 2022, 20, 00, 2);
	Locatie loc("stadion vaslui", 2,4.5);
	Zona z1("tribuna 1", 100, 10);
	Zona z2("tribuna 2", 100, 10);
	Zona zone[2] = { z1,z2 };
	Bilet b1("vip", 35, 150);
	Bilet b2("normal", 25, 50);
	Bilet bilete[] = { b1,b2 };

	cout << e1;
	cout << loc;

	Generator gen;
	gen.genereazaBilete(bilete, 2, zone, 2);
}