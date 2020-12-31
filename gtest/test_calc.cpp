#include "gtest.h"
#include "../App/Calculator.h"

TEST(calculator, addition)
{
	TCalculator a;
	a.SetExpression("1+1");
	EXPECT_EQ(2, a.Calc());
}

TEST(calculator, subtraction)
{
	TCalculator a;
	a.SetExpression("2-1");
	EXPECT_EQ(1, a.Calc());
}

TEST(calculator, multiplication)
{
	TCalculator a;
	a.SetExpression("3*4");
	EXPECT_EQ(12, a.Calc());
}

TEST(calculator, division)
{
	TCalculator a;
	a.SetExpression("10/5");
	EXPECT_EQ(2, a.Calc());
}

TEST(calculator, braces)
{
	TCalculator a;
	a.SetExpression("(2*3) - 1");
	EXPECT_EQ(5, a.Calc());
}

TEST(calculator, braces2)
{
	TCalculator a;
	a.SetExpression("1-(2*3)");
	EXPECT_EQ(-5, a.Calc());
}

TEST(calculator, braces3)
{
	TCalculator a;
	a.SetExpression("((5*4)-(2*3))*2- 10");
	EXPECT_EQ(18, a.Calc());
}

TEST(calculator, incorrect_braces)
{
	TCalculator a;
	a.SetExpression("(2+3");
	ASSERT_ANY_THROW(a.Calc());
}