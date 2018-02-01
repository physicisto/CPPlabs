#include <iostream>
#include "Boutique.h"
#include "ITaxPayment.h"
#include "Pharmacy.h"
#include "Shop.h"
using namespace std;
//демонстрация применения интерфейса, полиморфизма и RTTI
//2 аптеки и 1 бутик, продемонстрировать полиморфизм payTax()
// и все можно продемонстрировать одним действием)))))))
void main() {
	setlocale(0, "RUSSIAN");
	Shop * shop[3];
	shop[0] = new Boutique("Prada", "Donrtsk, str.Universitetska, 12", 2013, Shop::getTypeWork(1));
	shop[1] = new Pharmacy("Illich", "Makeevka", 2009, Shop::getTypeWork(1));
	shop[2] = new Pharmacy("Panazeya", "Gorlovka", 2000, Shop::getTypeWork(0));
	//демонстрирация полиморфизма payTax()
	shop[0]->sale(100);
	shop[1]->sale(100);
	shop[2]->sale(100);
	shop[0]->printProfit();
	shop[1]->printProfit();
	shop[2]->printProfit();
	//демонстрация RTTI и полиморфизма, и применения интерфейса
	for (int i = 0; i < 3; i++) {
		ITaxPayment* tax = dynamic_cast<ITaxPayment*>(shop[i]);
		cout <<"Налог на прибыль: "<< tax->payTax() << endl;
	}

	system("pause");
}