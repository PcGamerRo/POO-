#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"
#include "AchizitieBilet.h"

using namespace std;

int Eveniment::nrBileteDisponibile = 200;

int main()
{	
	//		VERIFICARE FUNCTIONALITATE CLASE
	//Clasa Eveniment.h
	
	Eveniment event1((char*)"eveniment de calitate", 17, 12, 2022, 22, 00, 1);
	cout << event1.getDenumire() << endl;
	cout << event1.getZi() << endl;
	cout << event1.getLuna() << endl;
	cout << event1.getAn() << endl;
	cout << event1.getOra() << endl;
	cout << event1.getMinute() << endl;
	cout << event1.getNrCategorii() << endl;
	cout << event1.getBileteDisp() << endl;
	return 0;
}