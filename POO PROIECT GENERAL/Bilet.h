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
	Bilet();
	Bilet(string ID, string Tip, float Pret);
	Bilet(const Bilet& x);
	//metode
	void checkValoare(int cantitate);
	void aplicareReducereGenerala(float procente);
	//settei
	void setTip(string tip);
	void setPret(float x);
	//getteri
	string getId();
	string getTip();
	float getPret();

	//supraincarcari
	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet);

	Bilet operator+(int i);
	Bilet operator-(int i);
	Bilet operator=(const Bilet& i);
};