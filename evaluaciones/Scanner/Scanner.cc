#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <regex>
using namespace std;
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::TestEventListeners;
using ::testing::UnitTest;
using ::testing::TestPartResult;
using ::testing::TestInfo;
using ::testing::TestCase;
using ::testing::ValuesIn;
using ::testing::Range;
class Scanner : public EmptyTestEventListener
{
	vector<int> openPorts;
	
	 
public:
	static int leakedScanners;
	Scanner(){
		
		char buf[10000];
		FILE *p=popen("netstat -l","r");
		string s;
		for(size_t count;(count=fread(buf,1,sizeof(buf),p));){
			s+=string(buf,buf+count);
		}
		smatch matches;
		
		regex r("[0-9]{5}");
		sregex_iterator next(s.begin(),s.end(),r);
		sregex_iterator end;
		while(next!=end){
			smatch match =*next;
			//cout<<match.str();
			openPorts.push_back(atoi(match.str().c_str()));
			next++;
		}

	}
	void *operator new(size_t sz){
		leakedScanners++;
		return ::operator new(sz);
	}
	void operator delete(void* p){
		leakedScanners--;
		::operator delete(p);
		//return ::operator delete(s);
	}
	static int getLeakedScanners()
	{
		//eturn 0;
		return leakedScanners;
	}

	
	bool isOpen(int a){
		for(int i=0;i<openPorts.size();i++){
			if(openPorts.at(i)==a){
				return true;
			}
		}
		return false;
	}
	
	vector<int> getOpenPorts(){
		return openPorts;
	}
};
int Scanner::leakedScanners=0;

class EventListener : public EmptyTestEventListener
{
public:
	

	/*virtual void OnTestProgramStart(const UnitTest&){
		fp=freopen("log.txt","w",stdout);
		printf("Iniciando Test\n");
		//printf("%s",UnitTest::GetInstance()->current_test_info()->name());
	}*/
	virtual void OnTestProgramEnd(const UnitTest& ut){
		EXPECT_EQ(0,Scanner::getLeakedScanners());
	}
	
};
class Fixture : public ::testing ::TestWithParam<int>{};
class RangeG : public ::testing ::TestWithParam<int>{};
TEST(TcnUno, tname)
{

	Scanner a=Scanner();
	
	cout<<a.isOpen(17718);
	cout<<a.isOpen(12);


	cout<<Scanner::getLeakedScanners();

	EXPECT_EQ(0,Scanner::getLeakedScanners());

}
TEST(TcnDos, tname)
{

	Scanner *b=new Scanner();
	
	delete b;
	
	EXPECT_EQ(0,Scanner::getLeakedScanners());

}
TEST(TcnTres, tname)
{

	Scanner *b=new Scanner();
	
	delete b;
	
	EXPECT_EQ(0,Scanner::getLeakedScanners());

}
TEST_P(Fixture, test)
{
	Scanner *b=new Scanner();
	//delete b;
	
	EXPECT_EQ(1,b->isOpen(GetParam()));
	delete b;
	//printValue(GetParam());
}
TEST_P(RangeG, test)
{
	Scanner *b=new Scanner();
	
	
	EXPECT_EQ(1,b->isOpen(GetParam()));
	delete b;
	//printValue(GetParam());
}
int a[]={10000,200,18763};
INSTANTIATE_TEST_CASE_P(caracteres,Fixture,ValuesIn(a));

INSTANTIATE_TEST_CASE_P(rangos,RangeG,Range(10000,11000,1));
//INSTANTIATE_TEST_CASE_P(enteros,Fixture,Values(10000,15049));

int main (int argc, char **argv)
{
	InitGoogleTest(&argc,argv);
	TestEventListeners& listeners=UnitTest::GetInstance()->listeners();
	listeners.Append(new EventListener);
	
	return RUN_ALL_TESTS();
}