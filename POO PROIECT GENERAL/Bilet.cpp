#include "Bilet.h"

Bilet::Bilet() : IdBilet("x") {
	tipBilet = "Necunoscut";
	pret = 0.0;
}
Bilet::Bilet(string ID, string Tip, float Pret) : IdBilet(ID) {
	tipBilet = Tip;
	pret = Pret;
}
Bilet::Bilet(const Bilet& x) {
	tipBilet = x.tipBilet;
	pret = x.pret;
}

//metode
void Bilet::checkValoare(int cantitate) {
	cout << pret * cantitate;
}
void Bilet::aplicareReducereGenerala(float procente) {
	pret = pret - pret * procente / 100;
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

//getteri
string Bilet::getId() { return IdBilet; }
string Bilet::getTip() { return tipBilet; }
float Bilet::getPret() { return pret; }

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
	in.get();
	return in;
}
ostream& operator<<(ostream& out, Bilet x) {
	out << endl;
	out << "Tip bilet:  " << x.tipBilet << endl;
	out << "Pret: " << x.pret << endl;
	out << endl << endl;
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
	return x;
}