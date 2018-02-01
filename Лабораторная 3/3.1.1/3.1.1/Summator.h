#pragma once
#include "ExpressionEvaluator.h"
class Summator :
	public ExpressionEvaluator
{
public:
	Summator();
	void print();
	double calculate();
	~Summator();
};

