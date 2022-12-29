#include "Zona.h"

Zona::Zona() {
	denumire = "necunoscuta";
	nrLocuri = 1;
	nrRanduri = 1;
	locOcupat = new int[1]{ 0 };
}
Zona::Zona(string denumire, int nrL, int nrR) :Zona() {
	this->denumire = denumire;
	this->nrLocuri = nrL;
	this->nrRanduri = nrR;
	locOcupat = new int[this->nrLocuri];
	//for (int i = 0; i < this->nrLocuri; i++) {
	//	locOcupat[i] = nrLoc[i];
	//}
}
Zona::Zona(const Zona& x) {
	denumire = x.denumire;
	nrLocuri = x.nrLocuri;
	nrRanduri = x.nrRanduri;
	locOcupat = new int[x.nrLocuri];
	for (int i = 0; i < x.nrLocuri; i++)
		locOcupat[i] = x.locOcupat[i];
}
Zona::~Zona() { delete[] locOcupat; }

//metode
int Zona::locuriPerRand() {
	return nrLocuri / nrRanduri;
}
void Zona::eliberareLocuri(int* locuri, int n) {
	for (int i = 0; i < n; i++) {
		locOcupat[locuri[i]] = 0;
	}
}

//setteri
void Zona::setDenumire(string denumire) {
	if (denumire.length() >= 1)
		this->denumire = denumire;
	else cout << "Denumirea trebuie sa contina cel putin un caracter!";
}
void Zona::setNrLocuri(int nrL) {
	if (nrL >= 1)
		this->nrLocuri = nrL;
	else cout << "Trebuie sa existe cel putin un loc!";
}
void Zona::setNrRanduri(int nrR) {
	if (nrR >= 1)
		this->nrRanduri = nrR;
	else cout << "Trebuie sa existe cel putin un rand!";
}
void Zona::setLocOcupat(int* nrLoc) {
	if (locOcupat != nullptr)
		delete[] locOcupat;
	if (nrLoc != nullptr) {
		locOcupat = new int[this->nrLocuri];
		for (int i = 0; i < this->nrLocuri; i++) {
			locOcupat[i] = nrLoc[i];
		}
	}
	else cout << "Sirul de numere nu poate fi unul nul!";
}

//getteri
string Zona::getDenumire() { return denumire; }
int Zona::getNrL() { return nrLocuri; }
int Zona::getNrR() { return nrRanduri; }
int* Zona::getLocOcupat() { return locOcupat; }

//supraincarcari
istream& operator>>(istream& in, Zona& x) {
	cout << "Denumire zona: ";
	getline(in, x.denumire);
	while (x.denumire.length() < 1) {
		cout << "Denumirea trebuie sa contina cel putin un caracter! incercati din nou!";
		getline(in, x.denumire);
	}

	//cout << "Numar locuri: ";
	//in >> x.nrLocuri;
	//while (cin.fail() || x.nrLocuri < 1) {
	//	if (cin.fail())
	//		cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
	//	else
	//		cout << "Trebuie sa existe cel putin un loc!";
	//	cin.clear();
	//	cin.ignore(100, '\n');
	//	in >> x.nrLocuri;
	//}

	cout << "Numar randuri: ";
	in >> x.nrRanduri;
	while (cin.fail() || x.nrRanduri < 1) {
		if (cin.fail())
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		else
			cout << "Trebuie sa existe cel putin un rand!";
		cin.clear();
		cin.ignore(100, '\n');
		in >> x.nrRanduri;
	}

	//cout << "Locuri ocupate: 1-ocupat 0-liber: " << endl;
	//x.locOcupat = new int[x.nrLocuri];
	//for (int i = 0; i < x.nrLocuri; i++) {
	//	cout << "Locul " << i << ": ";
	//	in >> x.locOcupat[i];
	//	while (cin.fail() || (x.locOcupat[i] != 0 && x.locOcupat[i] != 1)) {
	//		if (cin.fail())
	//			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
	//		else cout << "Valorile introduse trebuie sa fie in multimea {0, 1}! incercati din nou: ";
	//		cin.clear();
	//		cin.ignore(100, '\n');
	//		in >> x.locOcupat[i];
	//	}
	//}

	in.get();
	return in;
}
ostream& operator<<(ostream& out, Zona x) {
	out << endl;
	out << "Denumire zona: " << x.denumire << endl;
	out << "Numar locuri: " << x.nrLocuri << endl;
	out << "Numar randuri: " << x.nrRanduri << endl;
	out << "Locuri ocupate: 1-ocupat 0-liber" << endl;
	for (int i = 0; i < x.nrLocuri; i++) {
		out << "locul " << i << ": " << x.locOcupat[i] << endl;
	}
	out << endl << endl;
	return out;
}

int Zona::operator[](int index)
{
	if (index >= 0 && index < nrLocuri)
	{
		return locOcupat[index];
	}
	else return -1;
}
Zona Zona::operator+(int k) {
	// incrementare cu valoarea k a numarului de locuri ale zonei
	//acele locuri nou adaugate vor primi valoarea 0 - locuri libere;
	Zona& x = *this;
	int* copie = new int[x.nrLocuri];
	for (int i = 0; i < x.nrLocuri; i++)
		copie[i] = x.locOcupat[i];
	delete[] x.locOcupat;
	x.locOcupat = new int[x.nrLocuri + k];
	for (int i = 0; i < x.nrLocuri; i++) {
		x.locOcupat[i] = copie[i];
	}
	for (int i = x.nrLocuri; i < x.nrLocuri + k; i++)
		x.locOcupat[i] = 0;
	x.nrLocuri += k;
	delete[] copie;
	return x;
}
Zona Zona::operator=(const Zona& i) {
	Zona& x = *this;
	x.denumire = i.denumire;
	x.numarLocuriPeRand = i.numarLocuriPeRand;
	x.nrLocuri = i.nrLocuri;
	x.nrRanduri = i.nrRanduri;
	x.locOcupat = new int[i.nrLocuri];
	for (int j = 0; j < x.nrLocuri; j++) {
		x.locOcupat[j] = i.locOcupat[j];
	}
	return x;
}