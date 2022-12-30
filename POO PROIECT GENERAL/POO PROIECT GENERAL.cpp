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
 
void loadingScreen();
void meniu();
void functionalitati(Eveniment ev, Bilet bilete[], Locatie loc);
void meniu2();

int main()
{
	meniu(); 
	//de testat functionalitatile aplicatiei! (metodele generale)
	//cin.fail() cases
	return 0;
}

void loadingScreen() {
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

	//system("CLS");
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
void meniu() {
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
	while (Bilet::getNrBilete() > Zona::getNrLocuriDisponobile()) {
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
	loadingScreen();
	Generator gen;
	gen.genereazaBilete(bilete, categoriiBilete, zone, categoriiZone);
	functionalitati(ev, bilete, loc);
	gen.genereazaBilete(bilete, categoriiBilete, zone, categoriiZone);
}
void functionalitati(Eveniment ev, Bilet bilete[], Locatie loc) {
	int switch_on = 1;
	string continua="y";
	do {
		cout << endl << endl;
		cout << "Lista functionalitati: " << endl;
		cout << "1. Vedeti daca evemimentul a fost ratat sau nu. " << endl;
		cout << "2. Epuizati numarul total de bilete disponibile. " << endl;
		cout << "3. Verificati suma de platit pentru un anumit numar de bilete. " << endl;
		cout << "4. Aplicati o reducere generala asupra unui tip de bilete. " << endl;
		cout << "5. Vedeti cate locuri nu vor fi utilizate in timpul evenimentului, in cazul deficitului de bilete. " << endl;
		cout << "6. Acordati un rating locatiei. " << endl;
		
		cout << "Doriti sa testati o anumita functionalitate? y/n   ";
		cin >> continua;
		while (continua != "y" && continua != "n") {
			cout << "'" << continua << "' nu reprezinta o optiune valabila.";
			cout << "Va rugam incercati din nou!" << endl;
			cout << "Doriti sa testati o anumita functionalitate? y/n   ";
			cin >> continua;
		}
		if (continua == "y") {
			cout << endl << "functionalitatea dorita este: ";
			cin >> switch_on;
		}
		else break;

		switch (switch_on)
		{
		case 1: {
			int x, y, z;
			cout << "Introduceti data curenta: " << endl;
			cout << "Ziua: "; cin >> x;
			cout << "Luna: "; cin >> y;
			cout << "An: "; cin >> z;
			ev.evenimentRatat(x, y, z);
			cout << endl;
			break;
		}
		case 2: {
			int x;
			cout << "Introduceti numarul de bilete pe care doriti sa il epuizati: ";
			cin >> x;
			ev.epuizareBilete(x);
			cout << "Acum numarul de bilete ramase este: " << Bilet::getNrBilete();
			break;
		}
		case 3: {
			int x[100] = { 0 };
			float sum = 0.0;
			for (int i = 0; i < ev.getNrCategorii(); i++) {
				cout << "Numar de bilete dorit din categoria  '" << bilete[i].getTip() << "' : ";
				cin >> x[i];
			}
			cout << endl;

			for (int i = 0; i < ev.getNrCategorii(); i++) {
				sum += bilete[i].checkValoare(x[i]);
			}
			cout << "Suma de plata pentru ";
			for (int i = 0; i < ev.getNrCategorii(); i++) {
				cout << x[i] << " bilete de tip  '" << bilete[i].getTip() << "',  ";
			}
			cout << "este " << sum;
			break;
		}
		case 4: {
			float procente;
			int bilet;
			cout << "Carui tip de bilet doriti sa aplicati reducerea? "<<endl;
			for (int i = 0; i < ev.getNrCategorii(); i++) {
				cout << i + 1 << " " << bilete[i].getTip() << endl;
			}
			cin >> bilet;
			if (bilet<1 || bilet>ev.getNrCategorii()) {
				cout << "biletul nu exista!";
				break;
			}
			cout << "Introduceti procentele aferente reducerii generale: ";
			cin >> procente;
			bilete[bilet-1].aplicareReducereGenerala(procente);
			break;
		}
		case 5: {
			if (Bilet::getNrBilete() == Zona::getNrLocuriDisponobile())
				cout << "Toate locurile sunt atribuite!";
			else
				cout << loc.locuriNeutilizate();
			break;
		}
		case 6: {
			float rating;
			cout << "Introduceti valoarea ratingului: ";
			cin >> rating;
			if (rating < 1 || rating>5)
				cout << "Rating-ul trebuie sa aiba o valoare cuprinsa intre 1.0 si 5.0!";
			else
				loc.acordareRating(rating);
			break;
		}
		default:
			cout << switch_on << " nu este o optiune valida!";
			break;
		}
	} while (continua == "y");
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