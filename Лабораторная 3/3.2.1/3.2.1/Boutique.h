#pragma once
#include "Shop.h"
#include "ITaxPayment.h"

class Boutique :
	public Shop,
	public ITaxPayment
{
public:
	Boutique(char* sName, char* sAddress, int sYear, TypeWork t);
	int payTax();
	void sale(int sum);
	~Boutique();
};

