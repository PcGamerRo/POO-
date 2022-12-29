#pragma once
#include <iostream>
#include "Bilet.h"
#include "Zona.h"
using namespace std;
class Generator
{
private:
public:
	void genereazaBilete(Bilet b[], int x, Zona z[], int y) {
		int i = 0, j = 0, k = 0, loc_de_ocupat = 0;
		while (i < x) {
			cout << "Bilete de tip " << b[i].getTip() << endl;
			j = 0;
			while (j < b[i].getNumar()) {
				cout <<	"id " << j << "		";
				cout << b[i].getTip() << "		";
				cout << "pret aplicat " << b[i].getPret() << "		";
				cout << z[k].getDenumire() << "	";
				cout << "locul " << loc_de_ocupat << endl;
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