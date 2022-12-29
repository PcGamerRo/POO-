#pragma once
#include <iostream>
#include <string>
#include "Bilet.h"

using namespace std;

class Eveniment
{
private:
	char* denumireEveniment;
	static int nrBileteDisponibile;
	int nrCategoriiBilete;
	int zi;
	int luna;
	int an;
	int ora;
	int minute;
public:
	Eveniment();
	Eveniment(const char* denumire, int zi, int luna, int an, int ora, int minute, int nrCategorii);
	Eveniment(const Eveniment& x);
	~Eveniment();
	//metode
	void evenimentRatat(int x, int y, int z); //x-zi //y-luna //z-an (data curenta)
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

	//supraincarcari
	friend istream& operator>>(istream&, Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment);

	bool operator>(Eveniment& y);
	Eveniment operator++();
	Eveniment operator++(int);
	Eveniment operator--();
	Eveniment operator--(int);
	Eveniment operator=(const Eveniment i);
};