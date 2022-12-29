#include "Bilet.h"
#include <fstream>

Bilet::Bilet() {
	tipBilet = "Necunoscut";
	pret = 0.0;
	numar = 1;
}
Bilet::Bilet(string Tip, float Pret, int numar) {
	tipBilet = Tip;
	pret = Pret;
	this->numar = numar;
	//generare();
}
Bilet::Bilet(const Bilet& x) {
	tipBilet = x.tipBilet;
	pret = x.pret;
	numar = x.numar;
}

//metode
void Bilet::checkValoare(int cantitate) {
	cout << "Valoarea totala pentru " << cantitate << " bilete este : " << pret * cantitate;
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
}


//getteri
string Bilet::getTip() { return tipBilet; }
float Bilet::getPret() { return pret; }
int Bilet::getNumar() { return numar; }

//supraincarcari
istream& operator>>(istream& in, Bilet& x) {
	cout << "Tip bilet:  ";
	getline(in, x.tipBilet);

	cout << "Pret: ";
	in >> x.pret;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		in >> x.pret;
	}
	cout << "Numar exemplare: ";
	in >> x.numar;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Valoarea introdusa nu este un numar intreg! incercati din nou: ";
		in >> x.numar;
	}
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