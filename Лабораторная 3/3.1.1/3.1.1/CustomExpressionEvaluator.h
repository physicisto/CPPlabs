#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator :
	public ExpressionEvaluator,
	public IShuffle
{
public:
	CustomExpressionEvaluator();

	//���������� ���������� IShuffle:
	//����������� ���������� ��������:
	void shuffle();
	//���������� ��������, ����������� �� �������� i � j:
	void shuffle(int i, int j);

	void print();
	double calculate();

	~CustomExpressionEvaluator();
};

