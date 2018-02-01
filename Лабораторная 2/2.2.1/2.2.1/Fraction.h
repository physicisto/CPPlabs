#pragma once
class Fraction
{
	int x, y;
	static int nCount;

private:
	Fraction();

public:
	Fraction(const Fraction& f);
	Fraction(int inputF);
	Fraction(double inputF);
	Fraction(int i, int j);
	~Fraction();

	Fraction operator+(const Fraction& inputF);
	Fraction operator-(const Fraction& inputF);
	Fraction operator*(const Fraction& inputF);
	Fraction operator/(const Fraction& inputF);
	
	void reduce();
	int getCount();
	void print();

	static int gsd(int n1, int n2);
	static void printAsFraction(double dec_fraction);
	static void printAsFraction(char* dec_fraction);
};

