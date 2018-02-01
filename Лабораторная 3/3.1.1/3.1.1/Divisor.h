#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class Divisor :
	public ExpressionEvaluator,
	public IShuffle
{
public:
	Divisor();

	//���������� ���������� IShuffle:
	//����������� ���������� ��������:
	void shuffle();
	//���������� ��������, ����������� �� �������� i � j:
	void shuffle(int i, int j);

	void print();
	double calculate();

	~Divisor();
};

