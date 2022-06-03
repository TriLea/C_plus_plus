/*
* Author: Tristan Lea
* Date: 5/25/22
* description: C++ custom arrayList implementation.
*/

#include <IOStream>
#include <string>
#include <sstream>

#pragma once

template <typename E>

class ArrayList
{
public:


	ArrayList();
	ArrayList(int capacity);

	void add(E value);
	void add(int index, E value);
	void addAll(ArrayList<E> other); //ArrayList<E> other
	void clear();
	bool contains(E value);
	E get(int index);
	int indexOf(E value);
	bool isEmpty();
	void remove(int index);
	void set(int index, E vlaue);
	int size();
	std::string to_string();

	static const int DEFAULT_CAPACITY = 10;


private:

	void ensureCapacity(int capacity);

	E *elementData;
	int Size;
	int capacity;
};

//Constructors:

template <typename E>
ArrayList<E>::ArrayList()
{
	this->capacity = DEFAULT_CAPACITY;
	this->elementData = new E[DEFAULT_CAPACITY];
	this->Size = 0;
}

template <typename E>
ArrayList<E>::ArrayList(int capacity)
{	
	if (capacity < 0) {
		throw;
	}
	this->capacity = capacity;

	this->elementData = new E[capacity];
	this->Size = 0;
}

//Member functions:

template <typename E>
void ArrayList<E>::add(E value)
{
	ensureCapacity(Size + 1);
	elementData[Size] = value;
	Size++;
}

template <typename E>
void ArrayList<E>::add(int index, E value)
{
	if (index < 0 || index > Size) {
		throw;
	}
	ensureCapacity(Size + 1);
	for (int i = Size; i >= index + 1; i--) {
		elementData[i] = elementData[i - 1];
	}
	elementData[index] = value;
	Size++;
}

template <typename E>
void ArrayList<E>::addAll(ArrayList<E> other)
{
	ensureCapacity(Size + other.Size);

	for (int i = 0; i < other.Size; i++) {
		
		this->elementData[Size + i] = other.elementData[i];
	}
	Size += other.Size;
}

template <typename E>
void ArrayList<E>::clear()
{
	Size = 0;
}

template <typename E>
bool ArrayList<E>::contains(E value)
{
	return indexOf(value) >= 0;
}

template <typename E>
E ArrayList<E>::get(int index)
{
	if (index < 0 || index >= Size) {
		throw;
	}
	return elementData[index];
}

template <typename E>
int ArrayList<E>::indexOf(E value)
{
	for (int i = 0; i < Size; i++)
	{
		if (elementData[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template <typename E>
bool ArrayList<E>::isEmpty()
{
	return Size == 0;
}

template <typename E>
void ArrayList<E>::remove(int index)
{
	if (index < 0 || index >= Size) {
		throw;
	}

	for (int i = index + 1; i < Size; i++)
	{
		elementData[i - 1] = elementData[i];
	}
	Size--;
}

template <typename E>
void ArrayList<E>::set(int index, E value)
{
	if (index < 0 || index >= Size) {
		throw;
	}
	elementData[index] = value;
}

template <typename E>
int ArrayList<E>::size()
{
	return Size;
}


//the commented out stuff is if you'd like to make it look more like the
//java file output.
template <typename E>
std::string ArrayList<E>::to_string()
{
	std::ostringstream out;

	//out << "[";

	for (int i = 0; i < Size; i++) {
		//out << ", ";
		out << " " << elementData[i];
	}
	//out << "]";

	return out.str();
}

template <typename E>
void ArrayList<E>::ensureCapacity(int capacity)
{
	if (capacity > this->capacity)
	{
		int newCapacity = this->capacity * 2 + 1;

		if (newCapacity < capacity)
		{
			newCapacity = capacity;
		}
		
		//Juggling as to not overwrite or change the original.
		E* temporary = this->elementData;

		this->elementData = new E[newCapacity];

		for (int i = 0; i < Size; i++)
		{
			this->elementData[i] = temporary[i];
		}

		this->capacity = newCapacity;
	}
}