#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"
#include "Generator.h"
#include <fstream>

using namespace std;

int Eveniment::nrBileteDisponibile = 200;
int Locatie::nrLocuriDisponibile = 600;
 
int main()
{
	Eveniment e1((char*)"meci fotbal", 27, 12, 2022, 20, 00, 2);
	Locatie loc("stadion vaslui", 2, 100, 4.5);
	Zona z1("tribuna 1", 100, 10);
	Zona z2("tribuna 2", 100, 10);
	Zona zone[2] = { z1,z2 };
	Bilet b1("vip", 35, 150);
	Bilet b2("normal", 25, 50);
	Bilet bilete[] = { b1,b2};


	cout << e1;
	cout << loc;

	Generator gen;
	gen.genereazaBilete(bilete, 2, zone, 2);
	return 0;
}