


#ifndef STACK_H_
#define STACK_H_

#include <iostream>

using namespace std;

template <class T>

class Stack
{
private:
	T* pMem;									// Динамический массив
	size_t sz;									// Вместимость
	int top;									// Индекс вершины (-1 - стек пуст)

public:
	Stack(int n = 1);							// Конструктор присваивания
	Stack(const Stack& other);					// Конструктор копирования
	Stack& operator=(const Stack& other);		// Оператор присваивания
	~Stack();									// Деструктор


	void Push(const T& val);
	void Pop();
	T Top() const;
	bool IsEmpty() const;
	bool IsFull() const;
	size_t size() const;
	void clear();


	template<class U>
	friend ostream& operator<<(ostream& ostr, const Stack<U>& s);

	template<class U>
	friend istream& operator>>(istream& istr, Stack<U>& s);

};



template <class T>
Stack<T>::Stack(int n) : pMem(new T[(size_t)n]), sz((size_t)n), top(-1) {}

template <class T>
Stack<T>::Stack(const Stack& other) : pMem(new T[other.sz]), sz(other.sz), top(other.top)
{
	for (int i = 0; i <= other.top; i++)
		pMem[i] = other.pMem[i];
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this == &other)
		return *this;

	T* newMem = new T[other.sz];
	for (int i = 0; i <= other.top; i++)
		newMem[i] = other.pMem[i];

	delete[] pMem;
	pMem = newMem;

	sz = other.sz;
	top = other.top;

	return *this;
}

template<class T>
Stack<T>::~Stack()
{
	delete[] pMem;
}

template<class T>
bool Stack<T>::IsEmpty() const
{
	return top < 0;
}

template<class T>
bool Stack<T>::IsFull() const
{
	return top >= (int)sz - 1;
}

template<class T>
void Stack<T>::Push(const T& val)
{
	if (!IsFull())
		pMem[++top] = val;
}

template<class T>
void Stack<T>::Pop()
{
	if (!IsEmpty())
		--top;
}

template<class T>
T Stack<T>::Top() const
{
	/*if (IsEmpty())
		throw -1;*/
	T tmp = pMem[top];
	return tmp;
}

template<class T>
size_t Stack<T>::size() const
{
	return (size_t)(top + 1);
}

template<class T>
void Stack<T>::clear()
{
	top = -1;
}

template<class T>
ostream& operator<<(ostream& ostr, const Stack<T>& s)
{
	ostr << "[";
	for (int i = 0; i <= s.top; i++)
	{
		if (i > 0)
			ostr << " ";
		ostr << s.pMem[i];
	}
	ostr << "]";

	return ostr;
}

template<class T>
istream& operator>>(istream& istr, Stack<T>& s)
{
	T val;
	while (!s.IsFull() && (istr >> val))
		s.Push(val);

	return istr;
}


#endif