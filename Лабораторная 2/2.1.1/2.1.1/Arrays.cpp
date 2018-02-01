#include "Arrays.h"
#include <iostream>
#include <iomanip>
using namespace std;

double Factorial(int i) {
	if (i == 0) {
		return 1;
	}
	else
		return i*Factorial(i - 1);
}


Vector::Vector()
{ 
	vector = new double[15];
}

Vector::Vector(int N)
{
	vector = new double[N];
}

Vector::Vector(double* v)
{
	vector = new double[15];
	for (int i = 0; i < 15; i++) {
		vector[i] = v[i];
	}
	delete[]v;
}
Vector::Vector(const Vector& v)
{
	vector = new double[15];
	for (int i = 0; i < 15; i++) {
		vector[i] = v.vector[i];
	}
}


double& Vector::operator[](int i)
{
	return vector[i];
}

void Vector::printVector() {

	cout << endl;
	for (int i = 0; i < 15; i++) {
		cout << setw(8) << vector[i];
	}
}
/*Vector& Vector::operator=(double* v) {
	Vector v2;
	
	for (int i = 0; i < 15; i++) {
		v2[i] = v[i];
	}
	v2.printVector();
	return v2;
}*/

Vector& Vector::operator++() {
	for (int i = 0; i < 15; i++) {
		vector[i] ++ ;
	}
	return *this;
}
Vector Vector::operator++(int) {
	Vector v(*this);
	for (int i = 0; i < 15; i++) {
		vector[i] ++;
	}
	return v;
}
Vector& Vector::operator--() {
	for (int i = 0; i < 15; i++) {
		vector[i] --;
	}
	return *this;
}
Vector Vector::operator--(int) {
	Vector v(*this);
	for (int i = 0; i < 15; i++) {
		vector[i] --;
	}
	return v;
}
Vector::~Vector()
{
	delete[]vector;
}
//-------------------------------------Matrix---------------------------------------

Matrix::Matrix() {
	matrix = new double*[5]; // пять строк в массиве
	for (int i = 0; i < 5; i++)
		matrix[i] = new double[5]; // и пять столбцов
	//инициализация
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j] = Factorial(i + j);
		}
	}
}

 
double Matrix::at(int i, int j) const {

	return matrix[i][j];
}

void Matrix::setAt(int i, int j, double val) {
	matrix[i][j] = val;
}

void Matrix::printMatrix() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cout << setw(8) << matrix[i][j];
		cout << endl;
	}
}

double* Matrix::transArray() {
	double* v = new double[15];
	for (int i = 0; i < 5; i += 2) {
		for (int j = 0; j < 5; j++) {
			static int d = 0;           // "как бы" глобальная переменная, хранящая сдвиг
			v[d] = matrix[i][j];
			d++;
		}
	}
	return v;
}

void Matrix::operator++() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			matrix[i][j]++;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < 5; i++) {
		delete []matrix[i];
	}
	delete[]matrix;
}

