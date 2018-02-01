#pragma once
#include <iostream>
#include "ILoggable.h"
using namespace std;

class ExpressionEvaluator : public ILoggable
{
public:
	int nOperands;
	double* operands;
	static int number;
public:
	ExpressionEvaluator();
	ExpressionEvaluator(int n);

	//Заполнение массива:
	void setOperand(int pos, double value);
	void setOperands(double ops[], int N);

	//Реализация интерфейса ILoggable:
	//Запись лога всего выражения на консоль:
	void logToScreen();
	//Добавление записи лога всего выражения в файл лога:
	void logToFile(std::string filename);

	virtual void print() = 0;
	virtual double calculate() = 0;

	virtual ~ExpressionEvaluator();
};

