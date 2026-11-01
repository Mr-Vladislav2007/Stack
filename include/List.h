

#ifndef LIST_H_
#define LIST_H_


#include <iostream>

using namespace std;


template<class T>
class Node									// вспомогательная структура для списка (ячейка)
{
public:
	T value;								// значение ячейки
	Node* prev;								// указатель на предыдущую ячейку
	Node* next;								// указатель на следующую ячейку

	Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
};


template<class T>
class List
{
private:
	Node<T>* start;							// указатель на первый элемент
	Node<T>* finish;						// указатель на последний элемент
	size_t size;							// размер списка

public:
	List();									// конструктор по умолчанию
	List(const List& other);				// конструктор копирования
	List& operator=(const List& other);		// оператор присваивания
	~List();								// деструктор


	void Clear();							// очистка списка
	void Push(const T& val);				// добавить в конец
	void Pop();								// удалить последний элемент

	T Back() const;							// вернуть последний элемент
	T Front() const;						// вернуть первый элемент

	bool IsEmpty() const;					// список пуст

	size_t Size() const;					// размер списка


	friend ostream& operator<<(ostream& os, const List<T>& list) 
	{
		Node<T>* current = list.start;
		os << "[";
		while (current != nullptr) 
		{
			os << current->value;
			if (current->next != nullptr) os << ", ";
			current = current->next;
		}
		os << "]";

		return os;
	}
};




template<class T>
List<T>::List() : start(nullptr), finish(nullptr), size(0) {}


template<class T>
List<T>::List(const List& other) : start(nullptr), finish(nullptr), size(0)
{
	Node<T>* current = other.start;
	while (current != nullptr)
	{
		Push(current->value);
		current = current->next;
	}
}


template<class T>
List<T>&  List<T>::operator=(const List& other)
{
	if (this == &other)
		return *this;

	Clear();

	Node<T>* current = other.start;
	while (current != nullptr)
	{
		Push(current->value);
		current = current->next;
	}

	return *this;
}


template<class T>
List<T>::~List()
{
	Clear();
}


template<class T>
void List<T>::Clear()
{
	Node<T>* tmp = start;

	while (tmp != nullptr)
	{
		Node<T>* NextNode = tmp->next;
		delete tmp;
		tmp = NextNode;
	}

	start = finish = nullptr;
	size = 0;
}


template<class T>
void List<T>::Push(const T& val)
{
	Node<T>* tmp = new Node<T>(val);

	if (start == nullptr)
		start = finish = tmp;
	else
	{
		tmp->prev = finish;
		finish->next = tmp;
		finish = tmp;
	}
	size++;
}


template<class T>
void List<T>::Pop()
{
	if (finish == nullptr)
		return;

	Node<T>* tmp = finish;
	finish = finish->prev;

	if (finish != nullptr)
		finish->next = nullptr;
	else
		start = nullptr;

	delete tmp;
	size--;
}


template<class T>
T List<T>::Back() const
{
	if (finish != nullptr)
		return finish->value;
}


template<class T>
T List<T>::Front() const
{
	if (start != nullptr)
		return start->value;
}


template<class T>
bool List<T>::IsEmpty() const
{
	return size == 0;
}


template<class T>
size_t List<T>::Size() const
{
	return size;
}





#endif