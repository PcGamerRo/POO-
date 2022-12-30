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
	void genereazaBilete(Bilet b[], int x, Zona z[], int y) {
		ofstream g("date.txt");
		int i = 0, j = 0, k = 0, loc_de_ocupat = 0;
		string id="18488c5f-15ea-4318";
		while (i < x) {
			g << "Bilete de tip " << b[i].getTip() << endl;
			j = 0;
			while (j < b[i].getNumar()) {
				g << "id " << loc_de_ocupat << "		";
				g << "tip " << b[i].getTip() << "		";
				g << "pret aplicat " << b[i].getPret() << "		";
				g << z[k].getDenumire() << "	";
				g << "locul " << loc_de_ocupat << endl;
				j++;
				loc_de_ocupat++;
				if (j == z[k].getNrL()) {
					loc_de_ocupat = 0;
					k++;
				}
			}
			i++;
		}
	}
 };