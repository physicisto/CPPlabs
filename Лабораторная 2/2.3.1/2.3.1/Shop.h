#pragma once
#include <iostream>
#include <vector>
#include <string>
class Shop
{
	struct DataShop{
		std::string name;
		std::string address;
		int year;
		int profit;
		int NShop;
	};
	std::vector<int> establihment;
	static int number;
	DataShop shop;
	std::string filename = "DataShop.txt";

public:
	Shop();
	Shop(char* sName, char* sAddress, int sYear);
	Shop(const Shop& s);
	~Shop();

	void serialize();
	void serialize(std::string filename);
	void deserialize();
	void deserialize(std::string filename);

	void setName(char* sName);
	void setAddres(char* sAddres);
	void setYear(int sYear);

	void printName();
	void printShop();

	void sale(int sum, int month);

	static void bigSmallPpofit(std::vector<Shop> vecShop);
	static void bigSmallIncrease(std::vector<Shop> vecShop);

};

