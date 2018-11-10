#include "lib/customOps.h"
#include <gtest/gtest.h> // googletest header file

// This is the private method to be tested by SubstractOperator
extern "C" void modifyMyPrivateVariable(int value);

TEST(CustomOps, VerifyThatTheMethodReturnsZero) {
	
	modifyMyPrivateVariable(0);
	EXPECT_EQ(0, returnTrueIfAPrivateMethodIsCalled());

}

TEST(CustomOps, VerifyThatTheMethodReturnsOne) {

	modifyMyPrivateVariable(1);
	EXPECT_EQ(1, returnTrueIfAPrivateMethodIsCalled());

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}