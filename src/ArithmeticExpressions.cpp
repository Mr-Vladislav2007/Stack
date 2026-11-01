
#include "ArithmeticExpressions.h"

ArithmeticExpression::ArithmeticExpression(string str_infix)
{
	infix = str_infix;

	priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'(', 0} };

	ToPostfix();
}

void ArithmeticExpression::Parse()
{
	for (char c : infix)
		if (c != ' ')
			lexem.push_back(c);
}

void ArithmeticExpression::ToPostfix()
{
	Parse();
	Stack<char> st((int)lexem.size() + 1);
	char StackItem;

	for (char Item : lexem)
	{
		switch (Item)
		{
		case ('('):
			st.Push(Item);
			break;
			
		case (')'):
			StackItem = st.Top();
			st.Pop();

			while (StackItem != '(')
			{
				postfix += StackItem;
				StackItem = st.Top();
				st.Pop();
			}
			break;

		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty())
			{
				StackItem = st.Top();
				st.Pop();

				if (priority[Item] <= priority[StackItem])
					postfix += StackItem;
				else
				{
					st.Push(StackItem);
					break;
				}
			}
			st.Push(Item);
			break;

		default:
			operands.insert({ Item, {0.0} });
			postfix += Item;
			break;
		}
	}

	while (!st.IsEmpty())
	{
		StackItem = st.Top();
		st.Pop();
		postfix += StackItem;
	}
}


double ArithmeticExpression::Calculate(const map<char, double>& values)
{
	for (auto& val : values)
		operands.at(val.first) = val.second;

	Stack<double> st((int)postfix.size() + 1);
	double left, right;

	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			right = st.Top();
			st.Pop();
			left = st.Top();
			st.Pop();
			st.Push(left + right);
			break;

		case '-':
			right = st.Top();
			st.Pop();
			left = st.Top();
			st.Pop();
			st.Push(left - right);
			break;

		case '*':
			right = st.Top();
			st.Pop();
			left = st.Top();
			st.Pop();
			st.Push(left * right);
			break;

		case '/':
			right = st.Top();
			st.Pop();
			left = st.Top();
			st.Pop();
			st.Push(left / right);
			break;

		default:
			st.Push(operands[lexem]);
			break;
		}
	}

	return st.Top();
}


vector<char> ArithmeticExpression::GetOperands() const
{
	vector<char> op;
	for (const auto& item : operands)
	{
		op.push_back(item.first);
	}
	return op;
}

string ArithmeticExpression::GetInfix() const
{
	return infix;
}


string ArithmeticExpression::GetPostfix()
{
	return postfix;
}

