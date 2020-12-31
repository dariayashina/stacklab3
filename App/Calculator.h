#pragma once
#include "Stack.h"
#include <string>

using namespace std;

class TCalculator
{
private:
	string infix;// Строка в инфиксной записи
	string postfix; //Строка в постфиксной записи
	TStack<char> st;

	TStack<double> st2;
	int Priority(char elem)
	{
		switch (elem)
		{
		case 's':
		case '(':
		case ')':return 1;
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 3;
		default: throw elem;
		}
	}
public:
	TCalculator() : st(100), st2(200)
	{
		infix = "";
		postfix = "";
	}
	string GetExpression()
	{
		return infix;
	}
	void SetExpression(string expr)
	{
		infix = expr;
	}
	string GetPostfix()
	{
		return postfix;
	}
	//Перевод выражения из инфиксной в постфиксную форму
	void ToPostfix()
	{
		postfix = "";
		string src = "(" + infix + ")";
		char elem = '!';
		unsigned int i = 0;
		st.clear();
		while (i < src.size())
		{
			if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/')
			{
				postfix += " ";
				elem = st.pop();
				while (Priority(elem) >= Priority(src[i]))
				{
					postfix += elem;
					elem = st.pop();
				}
				st.push(elem);
				st.push(src[i]);
			}
			else
				if (src[i] == '(')
				{
					st.push(src[i]);
				}
				else
					if (src[i] == ')')
					{
						elem = st.pop();
						while (elem != '(')
						{
							postfix += elem;
							elem = st.pop();
						}
					}
					else
						if (src[i] >= '0' && src[i] <= '9')
						{
							postfix += src[i];
						}
			i++;
		}
	}
	//Вычисление выражения по постфиксной форме
	double CalcPostfix()
	{
		unsigned int i = 0;
		int tmp2 = 0;
		st2.clear();
		while (i < postfix.size())
		{
			if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
			{
				double k2 = st2.pop();
				double k1 = st2.pop();
				switch (postfix[i])
				{
				case '+': {st2.push(k1 + k2); break; }
				case '-': {st2.push(k1 - k2); break; }
				case '*': {st2.push(k1 * k2); break; }
				case '/': {st2.push(k1 / k2); break; }
				}
			}

			if (postfix[i] >= '0' && postfix[i] <= '9')
			{
				double tmp = atoi(&postfix[i]);// = перевести символ в число
				st2.push(tmp);
				tmp2 = to_string((int)tmp).length();
			}
			i += tmp2;
			tmp2 = 1;
		}

		return st2.peek();
	}
	//Вычисление выражения за 1 проход по инфиксной форме  
	double Calc()
	{
		if (!CheckBrackets())
			throw -1;
		ToPostfix();
		return CalcPostfix();
	}

	bool CheckBrackets()
	{
		st.clear();
		for (int i = 0; i < infix.size(); i++)
		{
			if (infix[i] == '(')
				st.push(infix[i]);
			if (infix[i] == ')')
			{
				if (st.IsEmpty() == true)
					return false;
				st.pop();
			}
		}
		return st.IsEmpty();
	}
};