#include "gtest/gtest.h"
#include "Pila.h"
class TestStack: public::testing::Test
{
public:
	void SetUp(){
		myst.push(10);
		myst.push(20);
	}
	void TearDown(){
	
	}
	myStack<int> myst;
};
TEST_F(TestStack, pushtest){
	myst.push(20);
	myst.push(30);
	myst.push(40);
	EXPECT_EQ(5,myst.size());	
}
TEST_F(TestStack, poptest){
	myst.pop();
	EXPECT_EQ(1,myst.size());
}
