

#ifndef ARITHMETIC_EXPRESSION_H_
#define ARITHMETIC_EXPRESSION_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
//#include "Stack.h"
#include "StackOnTheList.h"

using namespace std;


class ArithmeticExpression
{
private:
	string infix;				// исходная выражение в виде строки
	string postfix;				// обратная польская запись
	vector<char> lexem;			// массив лексем
	map<char, int> priority;	// приоритеты операций
	map<char, double> operands;	// значения переменных


	void Parse();				// разбиение строки на лексемы
	void ToPostfix();			// перевод строки в обратную польскую запись


public:
	ArithmeticExpression(string str_infix);
	~ArithmeticExpression() {}

	vector<char> GetOperands() const;
	string GetInfix() const;
	string GetPostfix();
	double Calculate(const map<char, double>& values);
};


#endif 