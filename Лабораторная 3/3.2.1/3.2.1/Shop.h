#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Shop
{
protected: 
	struct DataShop {
		char* name;
		char* address;
		int year;
		int profit;
		int NShop;
	};
	enum TypeWork {all_day, not_all_day};
	vector<int> establihment;
	static int number;
	DataShop shop;
	string filename = "DataShop.txt";
	int nalog = 12;							//земельный налог
	int time_of_work[2];					//время работы
	int action_clients;						//клиенты со скидкой
	TypeWork typeWork;						//тип работы (круглосуточно или нет)
public:
	Shop();
	Shop(const Shop& s);
	~Shop();

	void setName(char* sName);
	void setAddres(char* sAddres);
	void setYear(int sYear);
	void setTime(int a, int b);
	void setActionClients(int x);
	static TypeWork getTypeWork(int i) {
		if (i == 1)
			return not_all_day;
		return all_day;
	};

	void printName();
	void printShop();
	void printProfit();

	virtual void sale(int sum)=0;
};

