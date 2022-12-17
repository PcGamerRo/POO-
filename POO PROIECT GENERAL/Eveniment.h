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
	//date:
	int zi;
	int luna;
	int an;
	//time:
	int ora;
	int minute;
public:
	Eveniment();
	Eveniment(char* denumire, int zi, int luna, int an, int ora, int minute, int nrCategorii);
	~Eveniment();

	void evenimentRatat(int x, int y, int z);
	static void epuizareBilete(int x);

	//setters
	void setDenumire(char* denumire);
	static void setNrBileteDisponibile(int x);
	void setZi(int x);
	void setLuna(int y);
	void setAn(int z);
	void setTime(int ora, int minute);
	void setCategoriiBilete(int nr);
	
	//getters
	char* getDenumire();
	static int getNrBilete();
	int getZi();
	int getLuna();
	int getAn();
	int getOra();
	int getMinute();
	int getNrCategorii();
	static int getBileteDisp();

	//validated
	friend istream& operator>>(istream& in, Eveniment &x) {
		cout << "Denumire eveniment: ";
		char buff[500];
		in.getline(buff, 50);
		x.denumireEveniment = new char[strlen(buff) + 1];
		strcpy_s(x.denumireEveniment, strlen(buff) + 1, buff);
		
		cout << "Numar bilete disponibile: ";
		in >> x.nrBileteDisponibile;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			in >> x.nrBileteDisponibile;
		}

		cout << "Data: (numere intregi)" << endl;
		cout << "-	Zi: ";
		in >> x.zi;
		while (x.zi > 31 || x.zi < 1) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else 
				cout << "ziua trebuie sa fie cuprinsa intre 1 si 31! incercati din nou: ";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.zi;
		}
		
		cout << "-	Luna: ";
		in >> x.luna;
		while (x.luna > 12 || x.luna < 1) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else 
				cout << "luna trebuie sa fie cuprinsa intre 1 si 12! incercati din nou: ";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.luna;
		}
		
		cout << "-	An: ";
		in >> x.an;
		while (x.an < 0 || cin.fail())
		{
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else 
				cout << "anul nu poate fi negativ! incercati din nou: ";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.an;
		}

		cout << "Timpul: "<<endl;
		cout << "-	Ora: ";
		in >> x.ora;
		while (cin.fail() || x.ora > 23 || x.ora<0) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else cout << "Ora trebuie sa aiba valoarea cuprinsa intre 00 si 23! incercati din nou: ";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.ora;
		}
		cout << "-	Minute: ";

		in >> x.minute;
		while (cin.fail() || x.minute > 59 || x.minute <0) {
			if (cin.fail())
				cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			else cout << "Minutele trebuie sa aiba valoarea cuprinsa intre 00 si 59! incercati din nou: ";
			cin.clear();
			cin.ignore(100, '\n');
			in >> x.minute;
		}

		cout << "Numar categorii de bilete (VIP/NORMAL/etc...): ";
		in >> x.nrCategoriiBilete;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
			in >> x.nrCategoriiBilete;
		}
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

	//supraincarcare operator >
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

	//supraincarcare operator++
	Eveniment operator++() { //pre incrementare
		zi++;
		return *this;
	}
	//supraincarcare operator++
	Eveniment operator++(int) { //post incrementare
		Eveniment x = *this;
		zi++;
		return x;
	}

	//supraincarcare operator--
	Eveniment operator--() { //pre decrementare
		zi--;
		return *this;
	}
	//supraincarcare operator--
	Eveniment operator--(int) { //post decrementare
		Eveniment x = *this;
		zi--;
		return x;
	}

	//supraincarcare operator =
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