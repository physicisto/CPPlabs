#pragma once


class Vector {
	double* vector;
public:
	Vector();
	Vector(int N);
	Vector(double* v);
	Vector(const Vector& v);
	double& operator[](int i);
	void printVector();
	Vector& operator++();   //префиксный
	Vector operator++(int);//постфиксный
	Vector& operator--();   //префиксный
	Vector operator--(int);//постфиксный
	~Vector();
};


class Matrix {
	double ** matrix;
	
public:
	Matrix();
	~Matrix();
	double at(int i, int j) const;
	void setAt(int i, int j, double val);
	void printMatrix();
	double* transArray();
	void operator++();  //префиксный
};

