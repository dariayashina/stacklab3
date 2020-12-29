#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main()
{
	Calculator a;
	string str;
	cout << "Simple calculator" << endl;
	while (1 == 1)
	{
		cin >> str;
		a.SetFormula(str);
		cout << str << " = " << a.res() << endl;
		system("pause");
	}
	return 0;
}
