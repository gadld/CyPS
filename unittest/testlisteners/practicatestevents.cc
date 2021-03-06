#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctime>
using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::TestEventListeners;
using ::testing::UnitTest;
using ::testing::TestPartResult;
using ::testing::TestInfo;
using ::testing::TestCase;
class EventListener : public EmptyTestEventListener
{
public:
	FILE *fp;
	double sum=0;
	std::clock_t start;

	virtual void OnTestProgramStart(const UnitTest&){
		fp=freopen("log.txt","w",stdout);
		printf("Iniciando Test\n");
		//printf("%s",UnitTest::GetInstance()->current_test_info()->name());
	}
	virtual void OnTestProgramEnd(const UnitTest& ut){
		printf("\nEl tiempo total de ejecucion fue: %f\n",sum);
		
		printf("El numero de tests ejecutados fue %d\n",UnitTest::GetInstance()->total_test_case_count());
		printf("%d Correctos\n",UnitTest::GetInstance()->successful_test_case_count());
		
		printf("%d Incorrectos\n",UnitTest::GetInstance()->failed_test_case_count());
 		

	}
	virtual void OnTestPartResult(const TestPartResult& tpr){
		
		printf("Falla, los detalles son los siguientes:\n");
	
			printf("Linea del error: %d\n",tpr.line_number());
			printf("%s\n",tpr.summary());
		
	}
	virtual void OnTestStart(const TestInfo& t){
		start=std::clock();
		printf("TEST CASE: %s\n",t.test_case_name());
		printf("TEST NAME: %s\n",t.name());
	}

	virtual void OnTestCaseEnd(const TestCase& t){
		sum+=(std::clock()-start)/(double)CLOCKS_PER_SEC;
		const TestInfo* const test_info=UnitTest::GetInstance()->current_test_info();
		printf("El tiempo de ejecucion fue: %f\n",(std::clock()-start)/(double)CLOCKS_PER_SEC);
	}
};

TEST(TcnUno, tname)
{

	EXPECT_EQ(1,2);

}
TEST(TcnDos, tname)
{

	EXPECT_EQ(1,1);
}

int main (int argc, char **argv)
{
	InitGoogleTest(&argc,argv);
	TestEventListeners& listeners=UnitTest::GetInstance()->listeners();
	delete listeners.Release(listeners.default_result_printer());
	listeners.Append(new EventListener);
	

	return RUN_ALL_TESTS();
}