#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Bilet
{
	//const string IdBilet;
	static int nrBileteDisponibile;
	string tipBilet;
	float pret;
	int numar; //nr bilete disponibile din acest tip
public:
	friend class Generator;
	Bilet();
	Bilet(string Tip, float Pret, int numar);
	Bilet(const Bilet& x);
	//metode
	void checkValoare(int cantitate);
	void aplicareReducereGenerala(float procente);
	void genereaza();
	//setteri
	void setTip(string tip);
	void setPret(float x);
	void setNumar(int x);
	//getteri
	string getTip();
	float getPret();
	int getNumar();
	static int getNrBilete();

	//supraincarcari
	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet);

	Bilet operator+(int i);
	Bilet operator-(int i);
	Bilet operator=(const Bilet& i);
};