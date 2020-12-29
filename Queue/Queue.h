#pragma once
#include "Stack.h"
template<class A>
class TQueue : public TStack<A>
{
protected:
	int head, count;

public:
	TQueue() :TStack<A>() { head = 0; count = 0; }
	TQueue(const TQueue& _q) :TStack<A>(_q) { head = _q.head; count = _q.count; }
	TQueue(int _size) :TStack<A>(_size) { head = 0; count = 0; }
	TQueue(const std::initializer_list<A>& list) :TStack<A>(list) { head = 0; this->tail = 0; count = this->size; }
	~TQueue() { head = 0; count = 0; }

	void push(A elem)
	{
		if (this->IsFull())
			throw logic_error("queue full");
		count++;
		this->arr[this->tail] = elem;
		this->tail = (this->tail + 1) % this->size;
	}

	A pop()
	{
		if (this->IsEmpty())
			throw logic_error("queue empty");
		count--;
		A temp = this->arr[head];
		head = (head + 1) % this->size;
		return temp;
	}

	bool IsFull()
	{
		if (count == this->size)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& ostr, const TQueue<A>& lhs)
	{
		if (lhs.tail == lhs.head)
			for (int i = lhs.head; i < lhs.size; i++)
				ostr << lhs.arr[i] << ' ';
		else
			if (lhs.tail > lhs.head)
				for (int i = lhs.head; i < lhs.tail; i++)
					ostr << lhs.arr[i] << ' ';
			else
			{
				int t = lhs.tail + lhs.head + lhs.head + 1;
				for (int i = lhs.head; i < t; i++)
					ostr << lhs.arr[i % lhs.size] << ' ';
			}
		return ostr;
	}

	int GetCount()
	{
		return count;
	}
};
