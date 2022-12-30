#pragma once
#include <iostream>
#include <fstream>
#include "Bilet.h"
#include "Zona.h"
using namespace std;
class Generator
{
private:
public:
	void TEXTgenereazaBilete(Bilet b[], int x, Zona z[], int y) {
		ofstream g("fisier.txt");
		int i = 0, j = 0, k = 0, counterLoc=0, loc_pe_rand, rand=0, loc_de_ocupat = 0;
		int id = 0;
		loc_pe_rand = z[k].locuriPerRand();
		while (i < x) {
			g << "Bilete de tip " << b[i].getTip() << endl;
			j = 0;
			while (j < b[i].getNumar()) {
				g << "id " << id+1 << "		";
				g << "tip " << b[i].getTip() << "		";
				g << "pret aplicat " << b[i].getPret() << "		";
				g << z[k].getDenumire() << "		";
				g << "locul " << loc_de_ocupat+1<< "		";
				g << "randul " << rand+1 << endl;
				j++;
				id++;
				loc_de_ocupat++;
				counterLoc++;
				if (j == z[k].getNrL()) {
					rand = 0;
					loc_de_ocupat = 0;
					k++;
					loc_pe_rand = z[k].locuriPerRand();
				}
				if (counterLoc == loc_pe_rand-1) {
					counterLoc = 0;
					rand++;
				}
			}
			i++;
		}
	}

	void BINARgenereazaBilete(Bilet b[], int x, Zona z[], int y) {
		ofstream g("fisier.bin", ios::out | ios::binary);
		int i = 0, j = 0, k = 0, counterLoc = 0, loc_pe_rand, rand = 0, loc_de_ocupat = 0;
		int id = 0;
		loc_pe_rand = z[k].locuriPerRand();
		while (i < x) {
			g.write("Bilete de tip ", 15);
			string tip = b[i].getTip();
			g.write((char*)&tip, sizeof(tip) + 1);
			j = 0;
			while (j < b[i].getNumar()) {
				g.write("id", 3);
				g.write((char*)&id+1, sizeof(id));
				g.write("tip", 4);
				g.write((char*)&tip, sizeof(tip) + 1);
				g.write("pret aplicat", 13);
				float pret = b[i].getPret();
				g.write((char*)&pret, sizeof(pret) + 1);
				string denumire = z[k].getDenumire();
				g.write((char*)&denumire, sizeof(denumire) + 1);
				g.write("locul", 6);
				g.write((char*)&loc_de_ocupat + 1, sizeof(loc_de_ocupat));
				g.write("randul", 7);
				g.write((char*)&rand + 1, sizeof(rand));
				id++;
				j++;
				loc_de_ocupat++;
				counterLoc++;
				if (j == z[k].getNrL()) {
					rand = 0;
					loc_de_ocupat = 0;
					k++;
					loc_pe_rand = z[k].locuriPerRand();
				}
				if (counterLoc == loc_pe_rand - 1) {
					counterLoc = 0;
					rand++;
				}
			}
			i++;
		}
	}
};