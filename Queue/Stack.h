#include <iostream>
using namespace std;
template<class A>
class TStack
{
protected:
	A* arr;
	int size, tail;
public:
	TStack()
	{
		arr = new A[1];
		size = 1;
		tail = 0;
		arr[0] = 0;
	}
	TStack(const TStack& other)
	{
		this->size = other.size;
		this->arr = new A[size];
		this->tail = other.tail;
		for (int i = 0; i < size; i++)
			this->arr[i] = other.arr[i];
	}
	~TStack()
	{
		delete[] arr;
		size = 0;
		tail = 0;
	}
	TStack(int _size)
	{
		if (_size < 0) throw logic_error("invalid_argument");
		size = _size;
		arr = new A[size];

		tail = 0;
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}

	TStack(const std::initializer_list<A>& list)
		: TStack(list.size())
	{
		int count = 0;
		for (auto& element : list)
		{
			this->arr[count] = element;
			++count;
		}
		tail = size;
	}

	//TStack(const TQueue<A>& other)

	void push(A elem)
	{
		if (tail >= size)
			throw logic_error("out of range");
		arr[tail] = elem;
		tail++;
	}
	A pop()
	{
		if (tail == 0)
			throw logic_error("stack empty");
		A temp = arr[tail - 1];
		tail--;
		return temp;
	}

	bool IsFull()
	{
		if (tail == size)
			return true;
		else
			return false;
	}

	bool IsEmpty()
	{
		if (tail == 0)
			return true;
		else
			return false;
	}

	/*friend istream& operator>>(ostream& istr, const TStack<A>& lhs)
	{
		for (int i = 0; i < lhs.size; i++)
			istr << lhs.arr[i];
		return ostr;
	}*/

	friend ostream& operator<<(ostream& ostr, const TStack<A>& lhs)
	{
		for (int i = 0; i < lhs.tail; i++)
			ostr << lhs.arr[i] << ' ';
		return ostr;
	}
};
