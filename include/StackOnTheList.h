

#ifndef STACH_ON_THE_LIST_
#define STACH_ON_THE_LIST_


#include <iostream>
#include "List.h"

using namespace std;

template <class T>

class Stack
{
private:
	List<T> list;

public:
	Stack(int n = 1) { (void)n; }
	~Stack() {}

	void Push(const T& val);

	void Pop();

	T Top() const;

	bool IsEmpty() const;

	size_t size() const;

	void clear();

	template <class U>
	friend ostream& operator<<(ostream& ostr, const Stack<U>& s);
};


template <class T>
void Stack<T>::Push(const T& val)
{
	list.Push(val);
}


template <class T>
void Stack<T>::Pop()
{
	if (!list.IsEmpty())
		list.Pop();
}


template <class T>
T Stack<T>::Top() const
{
	return list.Back();
}


template <class T>
bool Stack<T>::IsEmpty() const
{
	return list.IsEmpty();
}


template <class T>
size_t Stack<T>::size() const
{
	return list.Size();
}


template <class T>
void Stack<T>::clear()
{
	list.Clear();
}


template <class T>
ostream& operator<<(ostream& ostr, const Stack<T>& s)
{
	ostr << s.list;
	return ostr;
}

#endif