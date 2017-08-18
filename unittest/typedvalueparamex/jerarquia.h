#include <iostream>
using namespace std;

template <class T>
class Parent
{
public:
	void doSomething(T value)
	{
		cout<<value;
	}
};
