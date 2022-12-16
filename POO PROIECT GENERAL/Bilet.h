#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bilet
{
	const string IdBilet;
	string tipBilet;
	float pret;
public:
	//metoda #1
	void checkValoare(int cantitate) {
		cout << pret * cantitate;
	}
	//metoda #2
	void aplicareReducereGenerala(float procente) {
		pret = pret - pret * procente / 100;
	}

	Bilet() : IdBilet("x") {
		tipBilet = "Necunoscut";
		pret = 0.0;
	}
	Bilet(string ID, string Tip, float Pret) : IdBilet(ID) {
		tipBilet = Tip;
		pret = Pret;
	}

	void setTip(string tip) { 
		if (tip.length() < 1)
			cout << "Tipul biletului trebuie sa aiba cel putin un caracter!";
		this->tipBilet = tip; 
	}
	void setPret(float x) { 
		if (x < 0)
			cout << "Pretul nu poate fi negativ!";
		this->pret = x; 
	}

	string getId() { return IdBilet; }
	string getTip() { return tipBilet; }
	float getPret() { return pret; }

	friend istream& operator>>(istream &in, Bilet &x){
		cout << "Tip bilet:  ";
		in.get();
		getline(in, x.tipBilet);
		cout << "Pret: ";
		in >> x.pret;
		return in;
	}

	friend ostream& operator<<(ostream& out, Bilet x) {
		out << "Tip bilet:  " << x.tipBilet << endl;
		out << "Pret: " << x.pret << endl;
		return out;
	}

	Bilet(const Bilet& x) {
		tipBilet = x.tipBilet;
		pret = x.pret;
	}

	Bilet operator+(int i) {
		Bilet& x = *this;
		x.pret += i;
		return x;
	}

	Bilet operator-(int i) {
		Bilet& x = *this;
		x.pret -= i;
		return x;
	}

	Bilet operator=(const Bilet& i) {
		Bilet& x = *this;
		//x.IdBilet = i.IdBilet;
		x.tipBilet = i.tipBilet;
		x.pret = i.pret;
		return x;
	}
};