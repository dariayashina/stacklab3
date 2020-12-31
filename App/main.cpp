#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main()
{
	TCalculator calc;
	char input[100];
	cout << "Simple calculator" << endl;
	while (1 == 1)
	{
		cin.getline(input, sizeof(input));
		calc.SetExpression(input);
		cout << input << " = " << calc.Calc() << endl;
		system("pause");
	}
	return 0;
}
