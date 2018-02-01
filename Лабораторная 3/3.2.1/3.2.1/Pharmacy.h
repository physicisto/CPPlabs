#pragma once
#include "Shop.h"
#include "ITaxPayment.h"

class Pharmacy :
	public Shop,
	public ITaxPayment
{
public:
	Pharmacy(char* sName, char* sAddress, int sYear, TypeWork t);
	int payTax();
	void sale(int sum);
	~Pharmacy();
};

