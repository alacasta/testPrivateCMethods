#include "lib/customMaths.h"
#include <gtest/gtest.h> // googletest header file

// This is the private method to be tested by SubstractOperator
extern "C" int resta(int op1, int op2);


TEST(CustoMathBasics, AddOperator) {
	int result;
	result = suma(1, 1);
	EXPECT_EQ(2, result);
}

TEST(CustoMathBasics, SubstractOperator) {
	int result;
	result = resta(1, 2);
	EXPECT_EQ(-1, result);
}

TEST(CustoMathBasics, SubstractOperatorResultsZero) {
	int result;
	result = resta(1, 1);
	EXPECT_EQ(0, result);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}