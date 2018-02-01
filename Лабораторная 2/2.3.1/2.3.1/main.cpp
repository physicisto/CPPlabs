#include <iostream>
#include "Shop.h"
#include <vector>
using namespace std;


void main() {
//------------------------------------------------------------------------------
//Создание магазинов
	Shop shop1("Amstor","Makeevka, str. Lenina, 45",2000);	//в стеке
	Shop* shop2 = new Shop;									//в хипе
	Shop* shop3 = new Shop;									//в хипе
	shop3->deserialize();									//3-й читается из файла
	shop2->setName("Objora");
	shop2->setAddres("Donetsk, str. Universitetska, 67");
	shop2->setYear(2008);
	shop3->printShop();
	cout << endl;
//------------------------------------------------------------------------------
//Запись в файл
	shop1.serialize();
	shop2->serialize("D:\\УчДНУ\\Официальная учебная программа\\2 курс\\ООП\\Лабораторные\\Лабораторная 2\\2.3.1\\2.3.1\\DataShop.txt");
//------------------------------------------------------------------------------
//Продажи за 1 месяц
	shop1.sale(300, 1);
	shop2->sale(350, 1);
	shop3->sale(900, 1); 
//Продажи за 2 месяц
	shop1.sale(300, 2);   //+0
	shop2->sale(300, 2);  //-50
	shop3->sale(800, 2);  //-100
//Продажи за 3 месяц
	shop1.sale(250, 3);   //-50
	shop2->sale(400, 3);  //+100
	shop3->sale(750, 3);  //-50
//------------------------------------------------------------------------------
	vector<Shop> vecShop = {shop1, *shop2, *shop3};
			 
//Вывод в порядке убывания по общей прибыли
	Shop::bigSmallPpofit(vecShop);
//Вывод в порядке убывания среднего прироста прибыли
	Shop::bigSmallIncrease(vecShop);
	delete shop2;
	delete shop3;
	system("pause");
}