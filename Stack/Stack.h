#pragma once
#include <iostream>

using namespace std;
template<class T>
class TStack
{
protected:
	T* Array;
	int size;
	int first;
	int last;
	int DataCount;

public:
	TStack()
	{
		Array = 0;
		size = 0;
		first = 0;
		last = -1;
		DataCount = 0;
	}
	TStack(int _size)
	{
		if (_size < 0)
			throw logic_error("incorrect size");

		Array = new T[_size];
		size = _size;
		first = 0;
		last = -1;
		DataCount = 0;

		for (int i = 0; i < size; i++)
			Array[i] = 0;

	}
	TStack(const TStack& _s)
	{
		Array = new T[_s.size];
		size = _s.size;
		first = _s.first;
		last = _s.last;
		DataCount = _s.DataCount;

		for (int i = 0; i < size; i++)
			Array[i] = _s.Array[i];
	}

	void clear()
	{
		first = 0;
		last = -1;
		DataCount = 0;

		for (int i = 0; i < size; i++)
			Array[i] = 0;
	}
	bool IsEmpty()
	{
		return(DataCount == 0);
	}
	bool IsFull()
	{
		return(DataCount == size);
	}
	void push(T _s)
	{
		if (IsFull())
			throw logic_error("stack is full");
		if (Array == 0)
			throw logic_error("memory error");

		last++;
		Array[last] = _s;
		DataCount++;
	}
	T pop()
	{
		if (this->IsEmpty())
			throw logic_error("stack is empty");
		if (Array == 0)
			throw logic_error("memory error");

		T tmp = Array[last];
		Array[last] = 0;
		last--;
		DataCount--;
		return (tmp);
	}

	T peek()
	{
		if (this->IsEmpty())
			throw logic_error("stack is empty");
		if (Array == 0)
			throw logic_error("memory error");

		return (Array[last]);
	}

	int GetSize()
	{
		return size;
	}
	int GetCount()
	{
		return DataCount;
	}
	int GetFirst()
	{
		return first;
	}
};