

#ifndef ARITHMETIC_EXPRESSION_H_
#define ARITHMETIC_EXPRESSION_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Stack.h"

using namespace std;

enum LexemType
{
	OPERAND = 0,
	OPERATOR = 1,
	LPAREN = 2,
	RPAREN = 3
};

struct Lexem
{
	string name;
	int type;
};


class ArithmeticExpression
{
private:
	string infix;				// исходная выражение в виде строки
	vector<Lexem> lexems;		// массив лексем
	vector<Lexem> postfix;		// обратная польская запись
	map<string, int> priority;	// приоритеты операций


	void Parse();				// разбиение строки на лексемы
	void ToPostfix();			// перевод строки в обратную польскую запись


public:
	ArithmeticExpression(string expr);
	~ArithmeticExpression();

	void Evaluate();
	void PrintPostfix() const;
};


#endif 