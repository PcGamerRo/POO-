#include "Locatie.h"

Locatie::Locatie() {
	denumireLocatie = "necunoscuta";
	nrZone = 1;
	//nrLocuriDisponibile = 0;
	ratingLocatie = 5;
}
Locatie::Locatie(string denumire, int nrZone, float rating) {
	this->denumireLocatie = denumire;
	this->nrZone = nrZone;
	//this->nrLocuriDisponibile = nrLocuriDisponibile;
	this->ratingLocatie = rating;
}
Locatie::Locatie(const Locatie& x) {
	denumireLocatie = x.denumireLocatie;
	nrZone = x.nrZone;
	//nrLocuriDisponibile = x.nrLocuriDisponibile;
	ratingLocatie = x.ratingLocatie;
}

//metode
int Locatie::locuriNeutilizate() { //in cazul in care sunt mai putine bilete decat locuri disponibile
	//return nrLocuriDisponibile - Bilet::getNrBilete();
	return 0;
}
void Locatie::acordareRating(float rating) { //rating=[1.0 stele; 5.0 stele]
	if (rating >= 1 && rating <= 5) {
		ratingLocatie *= index;
		index++;
		ratingLocatie += rating;
		ratingLocatie /= index;
	}
	else cout << "Introduceti o valoare intre 1.0 si 5.0 stele!";
}

//setteri
void Locatie::setDenumireLocatie(string denumire) {
	if (denumire.length() >= 1)
		this->denumireLocatie = denumire;
	else cout << "Denumirea trebuie sa contina cel putin un caracter!";
}
void Locatie::setNrZone(int nrZone) {
	if (nrZone > 0)
		this->nrZone = nrZone;
	else cout << "Trebuie sa existe cel putin o zona!";
}
//void Locatie::setNrLocuriDisponibile(int nrLocuriDisponibile) {
//	if (nrLocuriDisponibile >= 0)
//		this->nrLocuriDisponibile = nrLocuriDisponibile;
//	else cout << "Numarul de locuri nu poate fi negativ!";
//};
void Locatie::setRating(float rating) {
	if (rating >= 1 && rating <= 5)
		this->ratingLocatie = rating;
	else
		cout << endl << "Introduceti o valoare intre 1.0 si 5.0 stele!" << endl;
}

//getteri
string Locatie::getDenumire() { return denumireLocatie; }
int Locatie::getNrZone() { return nrZone; }
//int Locatie::getNrLocuriDisponobile() { return nrLocuriDisponibile; }
float Locatie::getRating() { return ratingLocatie; }

//supraincarcari
istream& operator>>(istream& in, Locatie& x) {
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

	/*cout << "Numarul total de locuri: ";
	in >> x.nrLocuriDisponibile;
	while (x.nrLocuriDisponibile < 0 || cin.fail() || x.nrLocuriDisponibile<Bilet::getNrBilete()) {
		if (cin.fail())
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		else if (x.nrLocuriDisponibile < 0)
			cout << "Numarul de locuri nu poate fi negativ!";
		else cout << "Numarul de locuri nu poate fi mai mic decat numarul de bilete! ";
		cin.clear();
		cin.ignore(100, '\n');
		in >> x.nrLocuriDisponibile;
	}*/

	cout << "Rating locatie: ";
	in >> x.ratingLocatie;
	while (x.ratingLocatie < 1 || x.ratingLocatie>5 || cin.fail()) {
		if (cin.fail())
			cout << "Valoarea introdusa nu este un numar real! incercati din nou: ";
		else cout << "Ratingul locatiei trebuie sa fie cuprins intre 1 si 5!";
		cin.clear();
		cin.ignore(100, '\n');
		in >> x.ratingLocatie;
	}

	in.get();
	return in;
}
ostream& operator<<(ostream& out, Locatie x) {
	out << endl;
	out << "Denumire locatie: " << x.denumireLocatie << endl;
	out << "Numar zone / categorii: " << x.nrZone << endl;
	//out << "Numar total de locuri: " << x.nrLocuriDisponibile << endl;
	out << "Rating-ul locatiei este: " << x.ratingLocatie << endl;
	out << endl << endl;
	return out;
}

bool Locatie::operator==(const Locatie y) {
	Locatie& x = *this;
	if (x.denumireLocatie == y.denumireLocatie)
		//if (x.Locatie::nrLocuriDisponibile == y.Locatie::nrLocuriDisponibile)
			if (x.nrZone == y.nrZone)
				if (x.ratingLocatie == y.ratingLocatie)
					return true;
	return false;
}
Locatie::operator int()
{
	return ratingLocatie;
}