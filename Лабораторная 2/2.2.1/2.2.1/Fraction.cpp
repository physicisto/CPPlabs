#include <iostream>
#include "Fraction.h"
#include <cmath>
using namespace std;

int Fraction::nCount = 0;
//----------------------------------------------------------------------
//Конструкторы
Fraction::Fraction(){}
Fraction::Fraction(const Fraction& f) {
	x = f.x, y = f.y;
	nCount++;
}
Fraction::Fraction(int inputF) {
	x = inputF, y = 1;
	nCount++;
}
Fraction::Fraction(double inputF){
	x = inputF * 1000000;
	y = 1000000;
	reduce();
	nCount++;
}
Fraction::Fraction(int i, int j){
	if (j == 0)
		cout << "Exeption!" << endl;
	else
		x = i, y = j;
	reduce();
	nCount++;
}
//------------------------------------------------------------------------
//Перегруженные операторы
Fraction Fraction::operator+(const Fraction& inputF) {
	Fraction f(x*inputF.y + inputF.x*y, y*inputF.y);
	return f;
}
Fraction Fraction::operator-(const Fraction& inputF) {
	Fraction f(x*inputF.y - inputF.x*y, y*inputF.y);
	return f;
}
Fraction Fraction::operator*(const Fraction& inputF) {
	Fraction f(x*inputF.x, y*inputF.y);
	return f;
}
Fraction Fraction::operator/(const Fraction& inputF) {
	Fraction f(x*inputF.y, y*inputF.x);
	return f;
}
//---------------------------------------------------------------------------
//Методы класса
void Fraction::reduce() {
	if (y != 0) {
		int temp = gsd(abs(x), abs(y));
		x /= temp, y /= temp;
	}
}
int Fraction::getCount() {
	return nCount;
}
void Fraction::print() {
	cout << x << "/" << y << endl;
}
//------------------------------------------------------------------------
//Статические методы
int Fraction::gsd(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return gsd(n2, n1 % n2);
	}
}
void Fraction::printAsFraction(double dec_fraction) {
	int temp = gsd(abs(dec_fraction * 1000000), 1000000);
	int x = (dec_fraction * 1000000)/temp;
	int y = 1000000 / temp;
	cout << dec_fraction << " = " << x << "/" << y << endl;
}
void Fraction::printAsFraction(char* dec_fraction) {
	double x = atof(dec_fraction);
	int temp = gsd(abs(x * 1000000), 1000000);
	x = (x * 1000000) / temp;
	int y = 1000000 / temp;
	cout << dec_fraction << " = " << x << "/" << y << endl;
}
//----------------------------------------------------------------------------
Fraction::~Fraction(){
	nCount--;
}
