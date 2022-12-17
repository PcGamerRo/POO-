#pragma once
#include <iostream>
#include <string>
using namespace std;

class Zona
{
	string denumire;
	int numarLocuriPeRand;
	int nrLocuri;
	int nrRanduri;
	int* locOcupat; //se marcheaza cu 1-ocupat si 0-liber
public:
	//metoda #1
	int locuriPerRand() {
		return nrLocuri / nrRanduri;
	}
	//metoda #2
	void eliberareLocuri(int* locuri, int n) {
		for (int i = 0; i < n; i++) {
			locOcupat[locuri[i]] = 0;
		}
	}

	Zona() {
		denumire = "necunoscuta";
		nrLocuri = 1;
		nrRanduri = 1;
		locOcupat = new int[1]{ 0 };
	}
	Zona(string denumire, int nrL, int nrR, int* nrLoc) :Zona() {
		this->denumire = denumire;
		this->nrLocuri = nrL;
		this->nrRanduri = nrR;
		locOcupat = new int[this->nrLocuri];
		for (int i = 0; i < this->nrLocuri; i++) {
			locOcupat[i] = nrLoc[i];
		}
	}

	~Zona() { delete[] locOcupat; }

	void setDenumire(string denumire) {
		if (denumire.length() >= 1)
			this->denumire = denumire;
		else cout << "Denumirea trebuie sa contina cel putin un caracter!";
	}
	void setNrLocuri(int nrL) {
		if (nrL >= 1)
			this->nrLocuri = nrL;
		else cout << "Trebuie sa existe cel putin un loc!";
	}
	void setNrRanduri(int nrR) {
		if (nrR >= 1)
			this->nrRanduri = nrR;
		else cout << "Trebuie sa existe cel putin un rand!";
	}
	void setLocOcupat(int* nrLoc) {
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

	string getDenumire() { return denumire; }
	int getNrL() { return nrLocuri; }
	int getNrR() { return nrRanduri; }
	int* getLocOcupat() { return locOcupat; }

	friend istream& operator>>(istream& in, Zona& x) {
		cout << "Denumire:";
		getline(in, x.denumire);
		while (x.denumire.length() < 1) {
			cout << "Denumirea trebuie sa contina cel putin un caracter! incercati din nou!";
			getline(in, x.denumire);
		}

		cout << "Numar locuri: ";
		in >> x.nrLocuri;
		while (cin.fail() || x.nrLocuri < 1) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else
				cout << "Trebuie sa existe cel putin un loc!";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.nrLocuri;
		}

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

		cout << "Locuri ocupate: 1-ocupat 0-liber: " << endl;
		x.locOcupat = new int[x.nrLocuri];
		for (int i = 0; i < x.nrLocuri; i++) {
			cout << "Locul " << i << ": ";
			in >> x.locOcupat[i];
			while (cin.fail() || (x.locOcupat[i] != 0 && x.locOcupat[i] != 1)) {
				if (cin.fail())
					cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
				else cout << "Valorile introduse trebuie sa fie in multimea {0, 1}! incercati din nou: ";
				cin.clear();
				cin.ignore(100, '\n');
				in >> x.locOcupat[i];
			}
		}

		in.get();
		return in;
	}

	friend ostream& operator<<(ostream& out, Zona x) {
		out << "Denumire zona: " << x.denumire << endl;
		out << "Numar locuri: " << x.nrLocuri << endl;
		out << "Numar randuri: " << x.nrRanduri << endl;
		//out << "Numar locuri pe rand: " << x.getNumarLocuri_peRand() << endl;
		out << "Locuri ocupate: 1-ocupat 0-liber" << endl;
		for (int i = 0; i < x.nrLocuri; i++) {
			out << "locul " << i << ": " << x.locOcupat[i] << endl;
		}
		return out;
	}

	Zona(const Zona& x) {
		denumire = x.denumire;
		nrLocuri = x.nrLocuri;
		nrRanduri = x.nrRanduri;
		locOcupat = new int[x.nrLocuri];
		for (int i = 0; i < x.nrLocuri; i++)
			locOcupat[i] = x.locOcupat[i];
	}

	//supraincarcare operator []
	int operator[](int index)
	{
		if (index >= 0 && index < nrLocuri)
		{
			return locOcupat[index];
		}
		else return -1;
	}

	//supraincarcare operator +
	Zona operator+(int k) { 
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
		for (int i = x.nrLocuri; i < x.nrLocuri+k; i++)
			x.locOcupat[i] = 0;
		x.nrLocuri += k;
		delete[] copie;
		return x;
	}

	//supraincarcare operator =
	Zona operator=(const Zona& i) {
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
};
