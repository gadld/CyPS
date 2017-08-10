#include "gtest/gtest.h"
TEST(TestCaseName,TestName)
{
	EXPECT_FALSE(true);
}
TEST(TestCaseName, TestNameDos){
	ASSERT_TRUE(true);
}
TEST(TestCaseName, BinEq){
	ASSERT_EQ(1,2);
}
TEST(TestCaseName, BinNeq){
	ASSERT_NE(1,1);
}
TEST(TestCaseName, LT){
	EXPECT_LT(5,7);
}
TEST(TestCaseName, LE){
	EXPECT_LE(6,6);
}
TEST(TestCaseName, GT){
	ASSERT_GT(5,5);
}
TEST(TestCaseName, GE){
	ASSERT_GE(5,5);
}
TEST(TestCaseName, STREQ){
	EXPECT_STREQ("a","A");
}
TEST(TestCaseName, STRNE){
	EXPECT_STRNE("a","A");
}
TEST(TestCaseName, StrCaseEEQ){
	EXPECT_STRCASEEQ("a","A");
}
TEST(TestCaseName, StrCASENE){
	EXPECT_STRCASENE("a","A");
}/*
TEST(TestCaseName, THROW){
	ASSERT_THROW("a",funcion());
}
TEST(TestCaseName, ANY_THROW){
	ASSERT_ANY_THROW(funcion());
}
TEST(TestCaseName, NO_THROW){
	EXPECT_NO_THOW(funcion());
}*/
TEST(TestCaseName, FLOAT_EQ){
	EXPECT_FLOAT_EQ(1.5,1.50);
}
TEST(TestCaseName, DOUBLE_EQ){
	EXPECT_DOUBLE_EQ(1.5,1.50);
} 
TEST(TestCaseName, NEAR){
	EXPECT_NEAR(1.5,1.52,.03);
}

