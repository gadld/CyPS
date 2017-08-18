#include "gtest/gtest.h"
#include "jerarquia.h"

template <class T>
class Fixture : public ::testing::Test
{
public:
	void SetUp()
	{
		parent=new T;
	}
	void TearDown()
	{
		delete parent;
	}

	Parent *parent;	
};



typedef ::testing::Types<Bubble,Quick> implementations;

TYPED_TEST_CASE(Fixture,implementations);
TYPED_TEST(Fixture,implmentations){
	int lista[]={4,2,7};
	this->parent->sort(lista,3);
	EXPECT_EQ(2,lista[0]);
}
