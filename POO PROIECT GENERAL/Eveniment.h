#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Eveniment
{
	char* denumireEveniment;
	static int nrBileteDisponibile;
	int nrCategoriiBilete;
	//Bilet* bilete;
	//date:
	int zi;
	int luna;
	int an;
	//time:
	int ora;
	int minute;
public:
	//metoda #1
	void evenimentRatat(int x, int y, int z) { 
		//x-zi y-luna z-an -> data curenta
		bool pass = true;
		if (x > 31 || x < 1) {
			cout << endl << "ziua trebuie sa aiba o valoare cuprinsa intre 1 si 31!" << endl;
			pass = false;
		}
		if (y > 12 || y < 1) {
			cout << "luna trebuie sa aiba o valoare cuprinsa intre 1 si 12!" << endl;
			pass = false;
		}
		else if (z < 0) {
			cout << "Anul nu poate fi negativ!" << endl;
			pass = false;
		}
		else if (pass == true) {
			if (z > an || (y > luna && z == an) || (x > zi && y == luna && z == an))
				cout << "Evenimentul a fost ratat!" << endl;
			else if (z == an && y == luna && x == zi)
				cout << "Evenimentul este astazi!" << endl;
			else cout << "Evenimentul nu a inceput inca!" << endl;
		}
	}
	//metoda #2 ( statica )
	static void epuizareBilete(int x) {
		if (x >= nrBileteDisponibile)
			nrBileteDisponibile -= x;
		else cout << "Nu sunt suficiente bilete! valoarea maxima este: " << nrBileteDisponibile << endl;
	}

	Eveniment() {
		denumireEveniment = new char[11];
		strcpy_s(denumireEveniment, 11, "Necunoscut");

		zi = 1;
		luna = 1;
		an = 2023;
		
		ora = 00;
		minute = 00;

		nrCategoriiBilete = 0;
	}
	Eveniment(char* denumire, int zi, int luna, int an, int ora, int minute, int nrCategorii/*, const Bilet* bilete*/) {
		if (denumire != nullptr) {
			denumireEveniment = new char[strlen(denumire) + 1];
			strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);
		}

		this->zi = zi;
		this->luna = luna;
		this->an = an;

		this->ora = ora;
		this->minute = minute;

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

	//setteri (validati)
	void setDenumire(char* denumire) {
		if (denumire != nullptr) {

			if (denumireEveniment != nullptr)
				delete[] denumireEveniment;

			denumireEveniment = new char[strlen(denumire) + 1];
			strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);
		}
		else cout << "denumirea trebuie sa fie diferita de nullptr!" << endl;
	}
	static void setNrBileteDisponibile(int x) {
		if (x < 0)
			cout << "Numarul de bilete disponibile nu poate fi negativ!";
		else
			nrBileteDisponibile = x;
	}
	void setZi(int x) { 
		if (x > 31 || x < 1) {
			cout << "ziua trebuie sa aiba o valoare cuprinsa intre 1 si 31!" << endl;
		}
		else
			this->zi = x;
	}
	void setLuna(int y) {
		if (y > 12 || y < 1)
			cout << "luna trebuie sa aiba o valoare cuprinsa intre 1 si 12!" << endl;
		else
			this->luna = y;
	}
	void setAn(int z) { 
		if (z < 0)
			cout << "Anul nu poate fi negativ!" << endl;
		else
			this->an = z;
	}
	void setTime(int ora, int minute) {
		if (ora < 0 || ora > 23 || minute < 0 || minute > 59) {
			cout << "Timpul trebuie cuprins intre 00:00 si 23:59";
		}
		else {
		this->ora = ora;
		this->minute = minute;
		}
	}
	void setCategoriiBilete(int nr) { this->nrCategoriiBilete = nr; }
	//getteri
	char* getDenumire() { return denumireEveniment; }
	static int getNrBilete() { return nrBileteDisponibile; }
	int getZi() { return zi; }
	int getLuna() { return luna; }
	int getAn() { return an; }
	int getOra() { return ora; }
	int getMinute() { return minute; }
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
		
		cout << "Data: (numere intregi)" << endl;
		cout << "-	Zi: ";
		in >> x.zi;
		cout << "-	Luna: ";
		in >> x.luna;
		cout << "-	An: ";
		in >> x.an;

		cout << "Timpul: "<<endl;
		cout << "-	Ora: ";
		in >> x.ora;
		cout << "-	Minute: ";
		in >> x.minute;
		cout << "Numar categorii de bilete (VIP/NORMAL/etc...): ";
		in >> x.nrCategoriiBilete;
		return in;
	}

	friend ostream& operator<<(ostream& out, Eveniment x) {
		out << "Denumire eveniment: " << x.denumireEveniment << endl;
		out << "Numar bilete disponibile: " << x.nrBileteDisponibile << endl;
		out << "Data: ";
		if (x.zi < 10) out << "0" << x.zi;
		else out << x.zi;
		if (x.luna < 10) out << "-0" << x.luna;
		else out << "-" << x.luna;
		out<< "-" << x.an << endl;
		out << "Timpul: ";
		if (x.ora < 10) out << "0" << x.ora << ":";
		else out << x.ora << ":";
		if (x.minute < 10) out << "0" << x.minute << endl;
		else out << x.minute << endl;
		out << "Numar categorii de bilete (VIP/NORMAL/etc...): " << x.nrCategoriiBilete;
		out << endl;
		return out;
	}

	Eveniment(const Eveniment& x) {
		denumireEveniment = new char[strlen(x.denumireEveniment) + 1];
		strcpy_s(denumireEveniment, strlen(x.denumireEveniment) + 1, x.denumireEveniment);
		zi = x.zi;
		luna = x.luna;
		an = x.an;
		ora = x.ora;
		minute = x.minute;
		nrBileteDisponibile = x.nrBileteDisponibile;
		nrCategoriiBilete = x.nrCategoriiBilete;
	}

	bool operator>(Eveniment& y) { //verif ce eveniment are loc mai tarziu
		Eveniment& x = *this;
		if (x.an > y.an) {
			return true;
		}
		else if (x.luna > y.luna && x.an==y.an)
			return true;
		else if (x.zi > y.zi && x.luna==y.an && x.an==y.an)
			return true;
		return false;
	}

	Eveniment operator++() { //pre incrementare
		zi++;
		return *this;
	}

	Eveniment operator++(int) { //post incrementare
		Eveniment x = *this;
		zi++;
		return x;
	}

	Eveniment operator--() { //pre decrementare
		zi--;
		return *this;
	}

	Eveniment operator--(int) { //post decrementare
		Eveniment x = *this;
		zi--;
		return x;
	}


	//operator =
	Eveniment operator=(const Eveniment i) {
		Eveniment& x = *this;
		x.denumireEveniment = new char[strlen(i.denumireEveniment) + 1];
		strcpy_s(x.denumireEveniment, strlen(i.denumireEveniment) + 1, i.denumireEveniment);
		x.zi = i.zi;
		x.an = i.an;
		x.luna = i.luna;
		x.an = i.an;
		x.ora = i.ora;
		x.minute = i.minute;
		x.nrCategoriiBilete = i.nrCategoriiBilete;
		return x;
	}
};