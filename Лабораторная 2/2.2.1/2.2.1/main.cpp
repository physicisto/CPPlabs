#include <iostream>
#include "Fraction.h"
using namespace std;


void main() {
	setlocale(LC_ALL, "RUSSIAN");

	Fraction f1(-5);
	Fraction f2(2, 18);
	Fraction f3(3.14);

	Fraction f4 = f2 + f2;
	Fraction f5 = f4 - f2;
	Fraction f6 = f4 * f2;
	Fraction f7 = f4 / f6;

	cout << f1.getCount() << " הנמבוי:" << endl;
	cout << "f1 = -5 = ";
	f1.print();
	cout << "f2 = 2/18 = ";
	f2.print();
	cout << "f3 = 3.14 = ";
	f3.print();
	cout << "f4 = 1/9 + 1/9 = ";
	f4.print();
	cout << "f5 = 2/9 - 1/9 = ";
	f5.print();
	cout << "f6 = 2/9 * 1/9 = ";
	f6.print();
	cout << "f7 = 2/9 / 2/81 = ";
	f7.print();

	cout << "ֽ־ִ 12 ט 18: " << Fraction::gsd(18, 12) << endl;
	Fraction::printAsFraction(3.1415);
	Fraction::printAsFraction("-2,71828");

	system("pause");
}