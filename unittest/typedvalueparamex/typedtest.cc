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



typedef ::testing::Types<bool,int> implementations;

TYPED_TEST_CASE(Fixture,implementations);
TYPED_TEST(Fixture,implmentations){

	this->parent->doSomething(1);
}
