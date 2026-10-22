


#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

class Stack
{
private:
	int* data;									// Динамический массив
	size_t sz;									// Вместимость
	size_t cnt;									// Текущее количество элементов

public:
	Stack();									// Конструктор присваивания
	Stack(const Stack& other);					// Конструктор копирования
	Stack& operator=(const Stack& other);		// Оператор присваивания
	~Stack();									// Деструктор


	void push(int value);
	void pop();
	int top() const;
	bool empty() const;
	size_t size() const;
	void clear();


};



#endif