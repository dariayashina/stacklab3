#pragma once
#include "Stack.h"
#include <iostream>
#include <string>
class Calculator
{
	std::string infix;
	std::string postfix;
	TStack<char> st_c;
	TStack<double> st_d;
	void ToPostfix();
	bool CheckBrackets();
public:
	void SetFormula(std::string str);
	double res();
};

int Priority(char c)
{
	switch (c)
	{
	case'+': return 2;
	case'-': return 2;
	case'*': return 3;
	case'/': return 3;
	case'(':return 1;
	case')':return 1;
	case'^':return 4;
	case's':return 1;
	case'c':return 1;
	case'l':return 1;
	case'e':return 1;
	default: return 0;
	}
}
void Calculator::SetFormula(std::string str)
{
	infix = " ";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (str[i] == 's' || str[i] == 'c' || str[i] == 'e' || str[i] == 'l')
		{
			infix += " ";
			infix += str[i];
			i += 3;
			if (i >= str.size() - 2)
				throw 0;
		}
		else
		{
			if (Priority(str[i]) != 0)
				infix += " ";
			infix += str[i];
		}

	}
	infix += ' ';
	if (CheckBrackets() != true)
		throw 0;

	TStack<char> c(infix.size());
	TStack<double> d(infix.size());
	st_c = c;
	st_d = d;
}
bool Calculator::CheckBrackets()
{
	st_c.clear();
	st_d.clear();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(' || infix[i] == 's' || infix[i] == 'c' || infix[i] == 'e' || infix[i] == 'l')
			st_c.push(infix[i]);
		if (infix[i] == ')')
		{
			if (st_c.IsEmpty() == true)
				return false;
			st_c.pop();
		}
	}
	return st_c.IsEmpty();
}
void Calculator::ToPostfix()
{
	st_c.clear();
	st_d.clear();
	postfix = "";
	std::string tmp = "(" + infix + ")";
	for (unsigned int i = 0; i < tmp.size(); i++)
	{
		if (Priority(tmp[i]) == 0)
			postfix += tmp[i];
		else
		{
			if (tmp[i] == '(' || tmp[i] == 's' || tmp[i] == 'c' || tmp[i] == 'l' || tmp[i] == 'e')
				st_c.push(tmp[i]);
			else
			{
				if (tmp[i] == ')')
				{
					while (st_c.peek() != '(' && st_c.peek() != 's' && st_c.peek() != 'c' && st_c.peek() != 'l' && st_c.peek() != 'e')
					{
						char a = st_c.pop();
						postfix += ' ';
						postfix += a;
					}
					if (st_c.peek() == '(')
						st_c.pop();
					else
					{
						char a = st_c.pop();
						postfix += ' ';
						postfix += a;
					}
				}
				else
				{
					while (Priority(st_c.peek()) >= Priority(tmp[i]))
					{
						char a = st_c.pop();
						postfix += ' ';
						postfix += a;
					}
					st_c.push(tmp[i]);
				}
			}
		}
	}
	if (!st_c.IsEmpty())
		throw 0;
}
double Calculator::res()
{
	ToPostfix();
	st_c.clear();
	st_d.clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		double a, b;
		switch (postfix[i])
		{
		case'+': a = st_d.pop(); b = st_d.pop();
			st_d.push(a + b);
			break;
		case'-': a = st_d.pop(); b = st_d.pop();
			st_d.push(b - a);
			break;
		case'*': a = st_d.pop(); b = st_d.pop();
			st_d.push(b * a);
			break;
		case'/': a = st_d.pop(); b = st_d.pop();
			st_d.push(b / a);
			break;
		case'^': a = st_d.pop(); b = st_d.pop();
			st_d.push(pow(b, a));
			break;
		case's': a = st_d.pop(); st_d.push(sin(a));
			break;
		case'c': a = st_d.pop(); st_d.push(cos(a));
			break;
		case'e': a = st_d.pop(); st_d.push(exp(a));
			break;
		case'l': a = st_d.pop(); st_d.push(log(a));
			break;
		default:
			if (postfix[i] != ' ')
			{
				unsigned int k = i, point = 0, flag = 0;;
				while (postfix[k] != ' ' && k != postfix.size())
				{
					if (postfix[k] == '.')
					{
						point = k;
						flag = 1;
					}
					k++;
				}
				unsigned int delta = k - i - flag;
				if (flag == 1)
					point = k - point - flag;
				k = i;
				double z = 0;
				while (postfix[k] != ' ' && k != postfix.size())
				{
					if (postfix[k] != '.')
					{
						delta--;
						z += (postfix[k] - '0') * pow(10, delta);
					}
					k++;
				}
				if (flag == 1)
					z /= pow(10, point);
				st_d.push(z);
				i = k;
			}
			break;
		}
	}
	if (st_d.GetCount() != 1)
		throw 0;

	return st_d.pop();
}