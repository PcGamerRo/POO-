#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Eveniment
{
	char* denumireEveniment;
	static int nrBileteDisponibile;
	string data;
	string ora;
	//int* ListaPreturi;
	int nrCategoriiBilete;
public:
	Bilet* bilete;
	Eveniment() {
		denumireEveniment = new char[11];
		strcpy_s(denumireEveniment, 11, "Necunoscut");

		nrBileteDisponibile = 0;

		data = "necunoscuta";
		ora = "necunoscuta";

		nrCategoriiBilete = 0;
	}
	Eveniment(char* denumire, string data, string ora, int nrCategorii, const Bilet* bilete) {
		denumireEveniment = new char[strlen(denumire) + 1];
		strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);

		this->data = data;
		this->ora = ora;

		this->nrCategoriiBilete = nrCategorii;

		if (nrCategoriiBilete > 0 && bilete != NULL) {
			delete[] this->bilete;
			this->bilete = new Bilet[nrCategoriiBilete];
		}
		for (int i = 0; i < nrCategoriiBilete; i++) {
			this->bilete[i] = bilete[i];
		}
	}
	~Eveniment() {
		delete denumireEveniment;
	}

	void setDenumire(char* denumire) {
		if (denumire != nullptr) {

			if (denumireEveniment != nullptr)
				delete[] denumireEveniment;

			denumireEveniment = new char[strlen(denumire) + 1];
			strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);
		}
		else throw exception("denumirea trebuie sa fie diferita de nullptr!");
	}

	void setData(string data) { this->data = data; }
	void setOra(string ora) { this->ora = ora; }
	static void setNrBileteDisponibile(int x) { nrBileteDisponibile = x; }

	char* getDenumire() { return denumireEveniment; }
	static int getNrBilete() { return nrBileteDisponibile; }
	string getData() { return data; }
	string getOra() { return ora; }
	int getNrCategorii() { return nrCategoriiBilete; }

	friend istream& operator>>(istream& in, Eveniment &x) {
		cout << "Denumire eveniment: ";
		char buff[500];
		in.getline(buff, 50);
		x.denumireEveniment = new char[strlen(buff) + 1];
		strcpy_s(x.denumireEveniment, strlen(buff) + 1, buff);
		cout << "Numar bilete disponibile: ";
		in >> x.nrBileteDisponibile;
		cout << "Data: ";
		in.get();
		getline(in, x.data);
		cout << "Ora: ";
		getline(in, x.ora);
		cout << "Numar categorii de bilete (VIP/NORMAL/etc...): ";
		in >> x.nrCategoriiBilete;
		return in;
	}

	friend ostream& operator<<(ostream& out, Eveniment x) {
		out << "Denumire eveniment: " << x.denumireEveniment << endl;
		out << "Numar bilete disponibile: " << x.nrBileteDisponibile << endl;
		out << "Data: " << x.data << endl;
		out << "Ora: " << x.ora << endl;
		return out;
	}

	Eveniment(const Eveniment& x) {
		denumireEveniment = new char[strlen(x.denumireEveniment) + 1];
		strcpy_s(denumireEveniment, strlen(x.denumireEveniment) + 1, x.denumireEveniment);
		data = x.data;
		ora = x.ora;
	}

	//operator =
	//Eveniment operator=(const Eveniment i) {
	//	Eveniment& x = *this;
	//	x.denumireEveniment = new char[strlen(i.denumireEveniment) + 1];
	//	strcpy_s(x.denumireEveniment, strlen(i.denumireEveniment) + 1, i.denumireEveniment);
	//	x.data = i.data;
	//	x.ora = i.ora;
	//}
};