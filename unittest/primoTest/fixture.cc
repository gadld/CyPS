#include "gtest/gtest.h"
#include "primo.h"
class TestPrimo: public::testing::Test
{
public:
	void SetUp(){
		//myst.push(10);
		//myst.push(20);
	}
	void TearDown(){
	
	}
	//myStack<int> myst;
};
TEST_F(TestPrimo, esPrimoCircular){
	//myst.push(20);
	//myst.push(30);
	//myst.push(40);
	EXPECT_EQ(1,esPrimoCircular("0"));
	EXPECT_EQ(1,esPrimoCircular("1"));
	EXPECT_EQ(1,esPrimoCircular("199"));
//	EXPECT_EQ(1,esPrimoCircular("23"));	
	EXPECT_EQ(1,esPrimoCircular("197"));
	EXPECT_EQ(1,esPrimoCircular("193"));

}
TEST_F(TestPrimo, poptest){
	//myst.pop();
	//EXPECT_EQ(1,myst.size());
}
