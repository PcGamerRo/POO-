#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Eveniment
{
	char* denumireEveniment;
	static int nrBileteDisponibile;
	//string data;
	int zi;
	int luna;
	int an;
	string ora;
	int nrCategoriiBilete;
public:
	//metoda #1
	void zileRamase(int x, int y, int z) { // cate zile mai sunt pana la eveniment (aproximativ)
		//x-zi y-luna z-an -> data curenta
		int zileR, luniR, aniR; //R-ramase/ramasi
		if (z > an || (y > luna && z == an) || (x > zi && y == luna && z == an))
			cout << "Evenimentul a trecut!" << endl;
		else {
			aniR = an - z - 1;
			if (luna >= y)
				luniR = luna - y;
			else
				luniR = 12 - y + luna;
			if (zi > x)
				zileR = zi - x;
			else
				zileR = 31 - x + zi;
			cout << zileR << " zile; " << luniR << "luni; " << aniR << "ani; " << endl;
		}
	}
	//metoda #2 ( statica )
	static void epuizareBilete(int x) {
		nrBileteDisponibile -= x;
	}

	//Bilet* bilete;
	Eveniment() {
		denumireEveniment = new char[11];
		strcpy_s(denumireEveniment, 11, "Necunoscut");

		nrBileteDisponibile = 0;

		zi = 1;
		luna = 1;
		an = 2023;
		
		ora = "necunoscuta";

		nrCategoriiBilete = 0;
	}
	Eveniment(char* denumire, int zi, int luna, int an, string ora, int nrCategorii/*, const Bilet* bilete*/) {
		denumireEveniment = new char[strlen(denumire) + 1];
		strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);

		this->zi = zi;
		this->luna = luna;
		this->an = an;

		this->ora = ora;

		this->nrCategoriiBilete = nrCategorii;

		//if (nrCategoriiBilete > 0 && bilete != NULL) {
		//	delete[] this->bilete;
		//	this->bilete = new Bilet[nrCategoriiBilete];
		//}
		//for (int i = 0; i < nrCategoriiBilete; i++) {
		//	this->bilete[i] = bilete[i];
		//}
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

	void setZi(int x) { this->zi = x; }
	void setLuna(int x) { this->luna = x; }
	void setAn(int x) { this->an = x; }

	void setOra(string ora) { this->ora = ora; }
	static void setNrBileteDisponibile(int x) { nrBileteDisponibile = x; }

	char* getDenumire() { return denumireEveniment; }
	static int getNrBilete() { return nrBileteDisponibile; }
	
	int getZi() { return zi; }
	int getLuna() { return luna; }
	int getAn() { return an; }

	string getOra() { return ora; }
	int getNrCategorii() { return nrCategoriiBilete; }

	static int getBileteDisp() { return Eveniment::nrBileteDisponibile; }

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
		
		cout << "Zi: ";
		in >> x.zi;
		cout << "Luna: ";
		in >> x.luna;
		cout << "An: ";
		in >> x.an;

		cout << "Ora: ";
		getline(in, x.ora);
		cout << "Numar categorii de bilete (VIP/NORMAL/etc...): ";
		in >> x.nrCategoriiBilete;
		return in;
	}

	friend ostream& operator<<(ostream& out, Eveniment x) {
		out << "Denumire eveniment: " << x.denumireEveniment << endl;
		out << "Numar bilete disponibile: " << x.nrBileteDisponibile << endl;
		out << "Data: " << x.zi << "-" << x.luna << "-" << x.an << endl;
		out << "Ora: " << x.ora << endl;
		return out;
	}

	Eveniment(const Eveniment& x) {
		denumireEveniment = new char[strlen(x.denumireEveniment) + 1];
		strcpy_s(denumireEveniment, strlen(x.denumireEveniment) + 1, x.denumireEveniment);
		zi = x.zi;
		luna = x.luna;
		an = x.an;
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