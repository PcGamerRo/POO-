#include "Bilet.h"
#include <fstream>

Bilet::Bilet() {
	tipBilet = "Necunoscut";
	pret = 0.0;
	numar = 1;
	nrBileteDisponibile = 0;
}
Bilet::Bilet(string Tip, float Pret, int numar) {
	tipBilet = Tip;
	pret = Pret;
	this->numar = numar;
	Bilet::nrBileteDisponibile += numar;
	//generare();
}
Bilet::Bilet(const Bilet& x) {
	tipBilet = x.tipBilet;
	pret = x.pret;
	numar = x.numar;
}

//metode
float Bilet::checkValoare(int cantitate) {
	//cout << "Valoarea totala pentru " << cantitate << " bilete este : " << pret * cantitate;
	return pret * cantitate;
}
void Bilet::aplicareReducereGenerala(float procente) {
	pret = pret - pret * procente / 100;
}

ofstream g("fisier.bin", ios::out | ios::binary);
void Bilet::genereaza() {
	for(int i=0;i<numar;i++){
		g.write((char*)&i, sizeof(i));
	}
	g.close();
}

//setteri
void Bilet::setTip(string tip) {
	if (tip.length() < 1)
		cout << "Tipul biletului trebuie sa aiba cel putin un caracter!";
	this->tipBilet = tip;
}
void Bilet::setPret(float x) {
	if (x < 0)
		cout << "Pretul nu poate fi negativ!";
	this->pret = x;
}
void Bilet::setNumar(int x) {
	this->numar = x;
	Bilet::nrBileteDisponibile += x;
}
void Bilet::setNrBilete(int x) {
	Bilet::nrBileteDisponibile = x;
}


//getteri
string Bilet::getTip() { return tipBilet; }
float Bilet::getPret() { return pret; }
int Bilet::getNumar() { return numar; }
int Bilet::getNrBilete() { return Bilet::nrBileteDisponibile; }

//supraincarcari
istream& operator>>(istream& in, Bilet& x) {
	cout << "Tip bilet:  ";
	getline(in, x.tipBilet);

	cout << "Pret: ";
	in >> x.pret;
	while (cin.fail() || x.pret<0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		if (x.pret < 0)
			cout << "Pretul nu poate fi negativ!";
		else
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		in >> x.pret;
	}
	cout << "Numar exemplare: ";
	in >> x.numar;
	while (cin.fail() || x.numar<=0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		if (x.numar <= 0)
			cout << "trebuie sa existe cel putin un exemplar!";
		else
			cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		in >> x.numar;
	}
	Bilet::nrBileteDisponibile += x.numar;
	in.get();
	return in;
}
ostream& operator<<(ostream& out, Bilet x) {
	out << endl << endl;
	out << "Tip bilet:  " << x.tipBilet << endl;
	out << "Pret: " << x.pret << endl;
	out << "Numar exemplare: " << x.numar << endl;
	out << endl;
	return out;
}

Bilet Bilet::operator+(int i) {
	Bilet& x = *this;
	x.pret += i;
	return x;
}
Bilet Bilet::operator-(int i) {
	Bilet& x = *this;
	x.pret -= i;
	return x;
}
Bilet Bilet::operator=(const Bilet& i) {
	Bilet& x = *this;
	//x.IdBilet = i.IdBilet;
	x.tipBilet = i.tipBilet;
	x.pret = i.pret;
	x.numar = i.numar;
	return x;
}