#include <iostream>
#include "Shop.h"
#include <vector>
using namespace std;


void main() {
//------------------------------------------------------------------------------
//�������� ���������
	Shop shop1("Amstor","Makeevka, str. Lenina, 45",2000);	//� �����
	Shop* shop2 = new Shop;									//� ����
	Shop* shop3 = new Shop;									//� ����
	shop3->deserialize();									//3-� �������� �� �����
	shop2->setName("Objora");
	shop2->setAddres("Donetsk, str. Universitetska, 67");
	shop2->setYear(2008);
	shop3->printShop();
	cout << endl;
//------------------------------------------------------------------------------
//������ � ����
	shop1.serialize();
	shop2->serialize("D:\\�����\\����������� ������� ���������\\2 ����\\���\\������������\\������������ 2\\2.3.1\\2.3.1\\DataShop.txt");
//------------------------------------------------------------------------------
//������� �� 1 �����
	shop1.sale(300, 1);
	shop2->sale(350, 1);
	shop3->sale(900, 1); 
//������� �� 2 �����
	shop1.sale(300, 2);   //+0
	shop2->sale(300, 2);  //-50
	shop3->sale(800, 2);  //-100
//������� �� 3 �����
	shop1.sale(250, 3);   //-50
	shop2->sale(400, 3);  //+100
	shop3->sale(750, 3);  //-50
//------------------------------------------------------------------------------
	vector<Shop> vecShop = {shop1, *shop2, *shop3};
			 
//����� � ������� �������� �� ����� �������
	Shop::bigSmallPpofit(vecShop);
//����� � ������� �������� �������� �������� �������
	Shop::bigSmallIncrease(vecShop);
	delete shop2;
	delete shop3;
	system("pause");
}