#include "Shop.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
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
Shop::Shop(const Shop& s) {
	shop.name = s.shop.name;
	shop.address = s.shop.address;
	shop.year = s.shop.year;
	shop.NShop = s.shop.NShop;
	shop.profit = s.shop.profit;
	establihment = s.establihment;
	typeWork = s.typeWork;
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
void Shop::setTime(int a, int b) {
	time_of_work[0] = a;
	time_of_work[1] = b;
}
void Shop::setActionClients(int x) {
	action_clients+=x;
}
//------------------------------------------------------------------------------
//Дополнительные функции
void Shop::printShop() {
	cout<< "name:   " << shop.name << std::endl
		<< "addres: " << shop.address << std::endl
		<< "year:   " << shop.year << std::endl
		<< "number: " << right << setw(6) << setfill('0') << shop.NShop << std::endl
		<< "profit: " << shop.profit << std::endl;
}
void Shop::printName() {
	cout << shop.name << endl;
}
void Shop::printProfit() {
	cout <<"Прибыль за вычетом налогов: "<< shop.profit << endl;
}
//------------------------------------------------------------------------------
//Деструктор
Shop::~Shop()
{
}
