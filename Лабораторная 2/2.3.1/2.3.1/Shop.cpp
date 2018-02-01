#include "Shop.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
int Shop::number = 1;
//------------------------------------------------------------------------------
//Конструкторы
Shop::Shop() {
	shop.name = "rfrf";
	shop.address = "";
	shop.year = 1900;
	shop.NShop = number++;
	shop.profit = 0;
	establihment = {};
}
Shop::Shop(char* sName, char* sAddress, int sYear) {
	shop.name = sName;
	shop.address = sAddress;
	shop.year = sYear;
	shop.NShop = number++;
	shop.profit = 0;
	establihment = {};
}
Shop::Shop(const Shop& s) {
	shop.name = s.shop.name;
	shop.address = s.shop.address;
	shop.year = s.shop.year;
	shop.NShop = s.shop.NShop;
	shop.profit = s.shop.profit;
	establihment = s.establihment;
}
//------------------------------------------------------------------------------
//Запись данных класса в файл
void Shop::serialize() {
	std::ofstream f(filename, std::ios_base::app); //открываем для дозаписи
	f << shop.name << std::endl
		<< shop.address << std::endl
		<< shop.year << std::endl
		<< shop.NShop << std::endl
		<< shop.profit <<  std::endl;
	f.close();
}
void Shop::serialize(std::string filename) {
	std::ofstream f(filename, std::ios_base::app); //открываем для дозаписи
	f << shop.name << std::endl
		<< shop.address << std::endl
		<< shop.year << std::endl
		<< shop.NShop << std::endl
		<< shop.profit << std::endl;
	f.close();
}
//------------------------------------------------------------------------------
//Чтение данных класса из файла
void Shop::deserialize() {
	std::ifstream f(filename, std::ios_base::in);
	getline(f, shop.name);
	getline(f, shop.address);
	f>>shop.year
		>> shop.NShop 
		>> shop.profit;
	f.close();

}
void Shop::deserialize(std::string filename) {
	std::ifstream f(filename, std::ios_base::in);
	getline(f, shop.name);
	getline(f, shop.address);
	f >> shop.year
		>> shop.NShop
		>> shop.profit;
	f.close();
}
//------------------------------------------------------------------------------
//Сеттеры
void Shop::setName(char* sName) {
	shop.name = sName;
}
void Shop::setAddres(char* sAddres) {
	shop.address = sAddres;
}
void Shop::setYear(int sYear) {
	shop.year = sYear;
}
//------------------------------------------------------------------------------
//Дополнительные функции
void Shop::printShop() {
	std::cout	<< "name:   " << shop.name << std::endl
				<< "addres: " << shop.address << std::endl 
				<< "year:   " << shop.year << std::endl 
				<< "number: " << std::right << std::setw(6) << std::setfill('0') << shop.NShop << std::endl 
				<< "profit: " << shop.profit << std::endl;
}
void Shop::printName() {
	std::cout << shop.name << std::endl;
}
void Shop::sale(int sum, int month) {
	establihment.push_back(sum);
	shop.profit += sum;
	std::cout << establihment[0];
}
void Shop::bigSmallPpofit(std::vector<Shop> vecShop){
	for (int i = 0; i < 2; i++) {
		bool swapped = false;
		for (int j = 0; j < 2 - i; j++) {
			if (vecShop[j].shop.profit < vecShop[j+1].shop.profit) {
				Shop b = vecShop[j];
				vecShop[j] = vecShop[j+1];
				vecShop[j+1] = b;
				swapped = true;
				}
			}		
			if (!swapped)
			break;
		}
	std::cout << "From big to small profit:" << std::endl;
	for (int i = 0; i < 3; i++) {
		vecShop[i].printName();
	}
}
void Shop::bigSmallIncrease(std::vector<Shop> vecShop) {
	int val1 = (vecShop[0].establihment[2]- vecShop[0].establihment[0]) / 2,
		val2 = (vecShop[1].establihment[2]- vecShop[1].establihment[0]) / 2,
		val3 = (vecShop[2].establihment[2]- vecShop[2].establihment[0]) / 2;
	int vals[3] = { val1,val2,val2 };
	std::cout << "From big to small averrage increase:" << std::endl;
	for (int i = 0; i < 2; i++) {
		bool swapped = false;
		for (int j = 0; j < 2 - i; j++) {
			if (vals[j] < vals[j + 1]) {
				Shop b = vecShop[j];
				vecShop[j] = vecShop[j + 1];
				vecShop[j + 1] = b;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	for (int i = 0; i < 3; i++) {
		vecShop[i].printName();
	}
}
//------------------------------------------------------------------------------
//Деструктор
Shop::~Shop()
{
}
