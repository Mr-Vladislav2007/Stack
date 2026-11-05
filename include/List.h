

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


	void Clear();								// очистка списка
	void PushBack(const T& val);				// добавить в конец
	void PopBack();								// удалить последний элемент
	void InsertAt(size_t index, const T& val);	// вставить в позицию index
	void RemoveAt(size_t index);				// удалить элемент с позиции index

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

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
		PushBack(current->value);
		current = current->next;
	}
}


template<class T>
List<T>& List<T>::operator=(const List& other)
{
	if (this == &other)
		return *this;

	Clear();

	Node<T>* current = other.start;
	while (current != nullptr)
	{
		PushBack(current->value);
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
void List<T>::PushBack(const T& val)
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
void List<T>::PopBack()
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
void List<T>::InsertAt(size_t index, const T& val)
{
	Node<T>* new_node = new Node<T>(val);

	if (index == 0)
	{
		new_node->next = start;
		if (start != nullptr)
			start->prev = new_node;
		start = new_node;
		if (finish == nullptr)
			finish = new_node;
	}

	else if (index == size)
	{
		new_node->prev = finish;
		finish->next = new_node;
		finish = new_node;
	}

	else
	{
		Node<T>* current = start;
		for (size_t i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		new_node->next = current->next;
		new_node->prev = current;
		current->next->prev = new_node;
		current->next = new_node;
	}

	size++;
}


template<class T>
void List<T>::RemoveAt(size_t index)
{
	Node<T>* curremt;
	if (index == 0)
	{
		current = start;
		start = start->next;
		if (start != nullptr)
			start->prev = nullptr;
		else
			finish = nullptr;
	}

	else if (index == size - 1)
	{
		current = finish;
		finish = finish->prev;
		finish->next = nullptr;
	}

	else
	{
		current = start;
		for (size_t i = 0; i < index; i++)
			current = current->next;

		curren->prev->next = current->next;
		curren->next->prev = current->prev;
	}

	delete current;
	size--;
}


template<class T>
T& List<T>::operator[](size_t index)
{
	Node<T>* current = start;
	for (size_t i = 0; i < index; i++)
		current = current->next;

	return current->value;
}


template<class T>
const T& List<T>::operator[](size_t index) const
{
	Node<T>* current = start;
	for (size_t i = 0; i < index; i++)
		current = current->next;

	return current->value;
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