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
	int i=0;
	int a[10]={2,3,5,7,11,13,17,31,37,71};
	while(i<10){
		EXPECT_EQ(1,esPrimoCircular(a[i]))<<i;
		i++;
	}/*
	EXPECT_EQ(1,esPrimoCircular(0));
	EXPECT_EQ(1,esPrimoCircular(1));
	EXPECT_EQ(1,esPrimoCircular(199));
//	EXPECT_EQ(1,esPrimoCircular("23"));	
	EXPECT_EQ(1,esPrimoCircular(197));
	EXPECT_EQ(1,esPrimoCircular(193));
*/
}
TEST_F(TestPrimo,todosPrimosCirculares){
	int i=0;
	while(i<100){
                EXPECT_EQ(1,esPrimoCircular(i))<<i;
                i++;
        }
}

