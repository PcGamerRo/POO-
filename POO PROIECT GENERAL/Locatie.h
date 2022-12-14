#pragma once
#include <iostream>
#include <string>
#include "Zona.h"
using namespace std;

class Locatie
{
	int nrLocuriDisponibile;
	string denumireLocatie;
	int nrZone=1;
public:
	//metoda #1
	int locuriNeutilizate() { //in cazul in care sunt mai putine bilete decat locuri disponibile
		return nrLocuriDisponibile - Eveniment::getBileteDisp();
	}
	//metoda #2


	//Zona* zone;
	Locatie() {
		denumireLocatie = "necunoscuta";
		nrZone = 1;
	}
	Locatie(string denumire, int nr/*, const Zona* zone*/) {
		denumireLocatie = denumire;
		nrZone = nr;
		//if (zone != NULL && nrZone > 0) {
		//	delete[] this->zone;
		//	this->zone = new Zona[nrZone];
		//}
		//for (int i = 0; i < nrZone; i++) {
		//	this->zone[i] = zone[i];
		//}
	}
	void setDenumireLocatie(string denumire) { this->denumireLocatie = denumire; }
	void setNrZone(int x) { this->nrZone = x; }

	string getDenumire() { return denumireLocatie; }
	int getNrZone() { return nrZone; }

	int getNrLocuriDisponobile() {
		int sum = 0, n=nrZone;
		for (int i = 0; i < nrZone; i++) {
			sum += zone[i].getNrL();
		}
		//cout << zone[0].getNrL();
		nrLocuriDisponibile = sum;
		return sum;
	}

	friend istream& operator>>(istream& in, Locatie& x) {
		cout << "Denumire locatie: ";
		in.get();
		getline(in, x.denumireLocatie);
		cout << "Numar zone / categorii: ";
		in >> x.nrZone;
		return in;
	}
	friend ostream& operator<<(ostream& out, Locatie x) {
		out << "Denumire locatie: " << x.denumireLocatie << endl;
		out << "Numar zone / categorii: " << x.nrZone << endl;
		//out << "Numar total de locuri: " << x.getNrLocuriDisponobile() << endl;
		return out;
	}
	Locatie(const Locatie& x) {
		denumireLocatie = x.denumireLocatie;
		nrZone = x.nrZone;
		nrLocuriDisponibile = x.nrLocuriDisponibile;
	}
};