#include "Eveniment.h"

Eveniment::Eveniment() {
	denumireEveniment = new char[11];
	strcpy_s(denumireEveniment, 11, "Necunoscut");

	zi = 1;
	luna = 1;
	an = 2023;

	ora = 00;
	minute = 00;

	nrCategoriiBilete = 0;
}
Eveniment::Eveniment(char* denumire, int zi, int luna, int an, int ora, int minute, int nrCategorii) {
	denumireEveniment = new char[strlen(denumire) + 1];
	strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);

	this->zi = zi;
	this->luna = luna;
	this->an = an;

	this->ora = ora;
	this->minute = minute;

	this->nrCategoriiBilete = nrCategorii;
}
Eveniment::~Eveniment() { delete denumireEveniment; }

void Eveniment::evenimentRatat(int x, int y, int z) {
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
void Eveniment::epuizareBilete(int x) {
	if (nrBileteDisponibile >= x)
		nrBileteDisponibile -= x;
	else cout << endl << "Nu sunt suficiente bilete! valoarea maxima este: " << nrBileteDisponibile << endl << endl;

}

//setters
void Eveniment::setDenumire(char* denumire) {
	if (denumire != nullptr) {
		if (strlen(denumire) == 0)
			cout << "Denumirea trebuie sa aibe cel putin un caracter!";
		else {
			if (denumireEveniment != nullptr)
				delete[] denumireEveniment;

			denumireEveniment = new char[strlen(denumire) + 1];
			strcpy_s(denumireEveniment, strlen(denumire) + 1, denumire);
		}
	}
	else cout << "denumirea trebuie sa fie diferita de nullptr!" << endl;
}
void Eveniment::setNrBileteDisponibile(int x) {
	if (x < 0)
		cout << "Numarul de bilete disponibile nu poate fi negativ!";
	else
		nrBileteDisponibile = x;
}
void Eveniment::setZi(int x) {
	if (x > 31 || x < 1) {
		cout << "ziua trebuie sa aiba o valoare cuprinsa intre 1 si 31!" << endl;
	}
	else
		this->zi = x;
}
void Eveniment::setLuna(int y) {
	if (y > 12 || y < 1)
		cout << "luna trebuie sa aiba o valoare cuprinsa intre 1 si 12!" << endl;
	else
		this->luna = y;
}
void Eveniment::setAn(int z) {
	if (z < 0)
		cout << "Anul nu poate fi negativ!" << endl;
	else
		this->an = z;
}
void Eveniment::setTime(int ora, int minute) {
	if (ora < 0 || ora > 23 || minute < 0 || minute > 59) {
		cout << "Timpul trebuie cuprins intre 00:00 si 23:59";
	}
	else {
		this->ora = ora;
		this->minute = minute;
	}
}
void Eveniment::setCategoriiBilete(int nr) {
	this->nrCategoriiBilete = nr; 
}

//getters
char* Eveniment::getDenumire() { return denumireEveniment; }
int Eveniment::getNrBilete() { return nrBileteDisponibile; }
int Eveniment::getZi() { return zi; }
int Eveniment::getLuna() { return luna; }
int Eveniment::getAn() { return an; }
int Eveniment::getOra() { return ora; }
int Eveniment::getMinute() { return minute; }
int Eveniment::getNrCategorii() { return nrCategoriiBilete; }
int Eveniment::getBileteDisp() { return Eveniment::nrBileteDisponibile; }