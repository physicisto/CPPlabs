#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
class CustomExpressionEvaluator :
	public ExpressionEvaluator,
	public IShuffle
{
public:
	CustomExpressionEvaluator();

	//Реализация интерфейса IShuffle:
	//Произвольно перемешать операнды:
	void shuffle();
	//Перемешать операнды, находящиеся на позициях i и j:
	void shuffle(int i, int j);

	void print();
	double calculate();

	~CustomExpressionEvaluator();
};

