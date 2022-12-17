#pragma once
#include <iostream>
#include <string>
#include "Zona.h"
#include "Eveniment.h"
using namespace std;

class Locatie
{
	int nrLocuriDisponibile=0;
	string denumireLocatie="necunoscuta";
	int nrZone=1;
	float ratingLocatie=5;
	int index = 1; //folosit pentru a contoriza rating-urile primite
	//Zona* zone;
public:
	//metoda #1
	int locuriNeutilizate() { //in cazul in care sunt mai putine bilete decat locuri disponibile
		return nrLocuriDisponibile - Eveniment::getBileteDisp();
	}
	//metoda #2
	void acordareRating(float rating) { //rating=[1.0 stele; 5.0 stele]
		if (rating >= 1 && rating <= 5) {
			ratingLocatie *= index;
			index++;
			ratingLocatie += rating;
			ratingLocatie /= index;
		}
		else cout << "Introduceti o valoare intre 1.0 si 5.0 stele!";
	}

	Locatie() {
		denumireLocatie = "necunoscuta";
		nrZone = 1;
		nrLocuriDisponibile = 0;
		ratingLocatie = 5;
	}
	Locatie(string denumire, int nrZone, int nrLocuriDisponibile, float rating) {
		if (denumire.length() >= 1)
			this->denumireLocatie = denumire;
		else cout << "Denumirea trebuie sa contina cel putin un caracter!" << endl;
		
		if (nrZone > 0)
			this->nrZone = nrZone;
		else cout << "Trebuie sa existe cel putin o zona!" << endl;
		
		if (nrLocuriDisponibile >= 0)
			this->nrLocuriDisponibile = nrLocuriDisponibile;
		else cout << "Numarul de locuri nu poate fi negativ!" << endl;

		if (rating >= 1 && rating <= 5)
			this->ratingLocatie = rating;
		else
			cout << endl << "Introduceti o valoare intre 1.0 si 5.0 stele!" << endl;
	}

	//setteri validati
	void setDenumireLocatie(string denumire) { 
		if (denumire.length() >= 1)
			this->denumireLocatie = denumire;
		else cout << "Denumirea trebuie sa contina cel putin un caracter!";
	}
	void setNrZone(int nrZone) {
		if (nrZone > 0)
			this->nrZone = nrZone;
		else cout << "Trebuie sa existe cel putin o zona!";
	}
	void setNrLocuriDisponibile(int nrLocuriDisponibile) {
		if (nrLocuriDisponibile >= 0)
			this->nrLocuriDisponibile = nrLocuriDisponibile;
		else cout << "Numarul de locuri nu poate fi negativ!";
	};
	void setRating(float rating) {
		if (rating >= 1 && rating <= 5)
			this->ratingLocatie = rating;
		else
			cout << endl << "Introduceti o valoare intre 1.0 si 5.0 stele!" << endl;
	}

	string getDenumire() { return denumireLocatie; }
	int getNrZone() { return nrZone; }
	int getNrLocuriDisponobile() { return nrLocuriDisponibile; }
	float getRating() { return ratingLocatie; }

	//validated
	friend istream& operator>>(istream& in, Locatie& x) {
		cout << "Denumire locatie: ";

		getline(in, x.denumireLocatie);
		while (x.denumireLocatie.length() < 1)
		{
			cout << "Denumirea trebuie sa contina cel putin un caracter! incercati din nou!";
			getline(in, x.denumireLocatie);
		}

		cout << "Numar zone / categorii: ";
		in >> x.nrZone;
		while (x.nrZone <= 0 || cin.fail()) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else
				cout << "Trebuie sa existe cel putin o zona!";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.nrZone;
		}

		cout << "Numarul total de locuri: ";
		in >> x.nrLocuriDisponibile;
		while (x.nrLocuriDisponibile < 0 || cin.fail()) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else cout << "Numarul de locuri nu poate fi negativ!";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.nrLocuriDisponibile;
		}

		cout << "Rating locatie: ";
		in >> x.ratingLocatie;
		while (x.ratingLocatie < 1 || x.ratingLocatie>5 || cin.fail()) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar real! incercati din nou: ";
			else cout << "Numarul de locuri nu poate fi negativ!";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.ratingLocatie;
		}

		in.get();
		return in;
	}
	friend ostream& operator<<(ostream& out, Locatie x) {
		out << "Denumire locatie: " << x.denumireLocatie << endl;
		out << "Numar zone / categorii: " << x.nrZone << endl;
		out << "Numar total de locuri: " << x.nrLocuriDisponibile << endl;
		out << "Rating-ul locatiei este: " << x.ratingLocatie << endl;
		return out;
	}

	Locatie(const Locatie& x) {
		denumireLocatie = x.denumireLocatie;
		nrZone = x.nrZone;
		nrLocuriDisponibile = x.nrLocuriDisponibile;
		ratingLocatie = x.ratingLocatie;
	}

	//supraincarcare operator ==
	bool operator==(const Locatie y) {
		Locatie& x = *this;
		if (x.nrLocuriDisponibile == y.nrLocuriDisponibile)
			if (x.denumireLocatie == y.denumireLocatie)
				if (x.nrLocuriDisponibile == y.nrLocuriDisponibile)
					if (x.nrZone == y.nrZone)
						if(x.ratingLocatie==y.ratingLocatie)
							return true;
		return false;
	}

	//supraincarcare cast explicit
	explicit operator int()
	{
		return ratingLocatie;
	}
};