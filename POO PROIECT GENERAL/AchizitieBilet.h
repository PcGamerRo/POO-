#pragma once
#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"

using namespace std;

class AchizitieBilet
{
	int* numarBilete; //din fiecare tip de bilete
	int nrTipuriBilete;
	int totalBilete;
public:
	//metoda generica #1
	float valoareAchizitie(Bilet* x) {
		float sum = 0;
		int len = sizeof(numarBilete) / sizeof(int) + 1;
		for (int i = 0; i < len; i++) {
			sum = sum + numarBilete[i] * x[i].getPret();
		}
		return sum;
	}

	//metoda generica #2 - metoada statica
	void epuizareBilete(int x) {
		Eveniment::setNrBileteDisponibile(Eveniment::getNrBilete() - x);
	}

	AchizitieBilet() : numarBilete(nullptr), totalBilete(0) { }
	AchizitieBilet(int* numarBilete, int nrTipuri) {
		this->nrTipuriBilete = nrTipuri;
		this->numarBilete = new int[nrTipuri];
		for (int i = 0; i < nrTipuri; i++) {
			this->numarBilete[i] = numarBilete[i];
			totalBilete += numarBilete[i];
		}
		epuizareBilete(totalBilete);
	}

	~AchizitieBilet() {
		delete[] numarBilete;
	}

	friend istream& operator>>(istream& in, AchizitieBilet& x) {
		cout << "Numarul total de biete dorit: ";
		in >> x.totalBilete;
		cout << "Numarul de tipuri de bilete:";
		in >> x.nrTipuriBilete;
		x.numarBilete = new int[x.nrTipuriBilete];
		for (int i = 0; i < x.nrTipuriBilete; i++) {
			cout << "Numarul de bilete de tip " << i << ": " << endl;
			in >> x.numarBilete[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, AchizitieBilet x) {
		out << "Numarul total de biete: " << x.totalBilete << endl;
		out << "Numarul de tipuri de bilete: " << x.nrTipuriBilete << endl;
		for (int i = 0; i < x.nrTipuriBilete; i++) {
			cout << "Numarul de bilete de tip " << i << ": " << x.numarBilete[i] << endl;
		}
	}

};