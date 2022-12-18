#pragma once
#include <iostream>
#include <string>
#include "Zona.h"
#include "Eveniment.h"
using namespace std;

class Locatie
{
	static int nrLocuriDisponibile;
	string denumireLocatie="necunoscuta";
	int nrZone=1;
	float ratingLocatie=5;
	int index = 1; //folosit pentru a contoriza rating-urile primite
	//Zona* zone;
public:
	Locatie();
	Locatie(string denumire, int nrZone, int nrLocuriDisponibile, float rating);
	Locatie(const Locatie& x);

	//metode
	int locuriNeutilizate(); //in cazul in care sunt mai putine bilete decat locuri disponibile
	void acordareRating(float rating); //rating=[1.0 stele; 5.0 stele]

	//setteri
	void setDenumireLocatie(string denumire);
	void setNrZone(int nrZone);
	void setNrLocuriDisponibile(int nrLocuriDisponibile);
	void setRating(float rating);

	//gettteri
	string getDenumire();
	int getNrZone();
	int getNrLocuriDisponobile();
	float getRating();

	//supraincarcari
	friend istream& operator>>(istream&, Locatie&);
	friend ostream& operator<<(ostream&, Locatie);

	bool operator==(const Locatie y);
	explicit operator int();
};