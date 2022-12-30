#pragma once
#include <iostream>
#include <string>
using namespace std;

class Zona
{
	static int nrLocuriDisponibile;
	string denumire;
	int numarLocuriPeRand;
	int nrLocuri;
	int nrRanduri;
	int* locOcupat; //se marcheaza cu 1-ocupat si 0-liber
public:
	Zona();
	Zona(string denumire, int nrL, int nrR);
	Zona(const Zona& x);
	~Zona();

	//metode
	int locuriPerRand();
	void eliberareLocuri(int* locuri, int n);

	//setteri
	void setDenumire(string denumire);
	void setNrLocuri(int nrL);
	void setNrRanduri(int nrR);
	void setLocOcupat(int* nrLoc);
	static void setNrLocuriDisponibile(int nrLocuriDisponibile);

	//getteri
	string getDenumire();
	int getNrL();
	int getNrR();
	int* getLocOcupat();
	static int getNrLocuriDisponobile();

	//supraincarcari
	friend istream& operator>>(istream&, Zona&);
	friend ostream& operator<<(ostream&, Zona);

	int operator[](int index);
	Zona operator+(int k); // incrementare cu valoarea k a numarului de locuri ale zonei //acele locuri nou adaugate vor primi valoarea 0 - locuri libere;
	Zona operator=(const Zona& i);
};