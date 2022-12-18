#include <iostream>
#include "Eveniment.h"
#include "Bilet.h"
#include "Locatie.h"
#include "Zona.h"

using namespace std;

int Eveniment::nrBileteDisponibile = 200;

int main()
{	
	//		VERIFICARE FUNCTIONALITATE CLASE
	//Clasa Eveniment.h
	//Eveniment event1;
	//cin >> event1;
	//cout << event1;
	//event1.evenimentRatat(18, 12, 2022); //metoda1
	//event1.epuizareBilete(15); //metoda2 - statica
	//cout << "Bilete ramase: " << event1.getBileteDisp() << endl;
	//Eveniment event2((char*)"concert rock", 18, 01, 2023, 17, 00, 2);
	//cout << event2;

	//if ((event2 > event1) == 1)
	//	cout << "Evenimentul 2 incepe mai tarziu decat evenimentul 1";
	//else
	//	cout << "Evenimentul 2 NU incepe mai tarziu decat evenimentul 1";
	
	/*Bilet bilet1;
	cout<<bilet1.getId();*/
	//Locatie locatie1;
	//cin >> locatie1;
	//cout << locatie1;

	Zona zona1;
	cin >> zona1;
	cout << zona1;
	
	return 0;
}