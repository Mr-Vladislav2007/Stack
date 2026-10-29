
#include "ArithmeticExpressions.h"

ArithmeticExpression::ArithmeticExpression(string expr) : infix(expr)
{
	priority["+"] = 1;
	priority["-"] = 1;
	priority["*"] = 2;
	priority["/"] = 2;

	Parse();
	ToPostfix();
}

void ArithmeticExpression::Parse()
{
	string currentNum = "";

	for (size_t i = 0; i < infix.length(); i++)
	{
		char c = infix[i];
		if (isdigit(c) || c == '.')
			currentNum += c;
		else
		{
			if (!currentNum.empty())
			{
				lexems.push_back({ currentNum, OPERAND });
				currentNum = "";
			}
		}
	}
}