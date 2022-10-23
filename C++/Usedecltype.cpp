// C++ program to demonstrate use of decltype
#include <typeinfo>
#include <string>
#include <iostream>
using namespace std;

int function1()
{
	return 24;
}
float function2()
{
	return 1.1;
}

int main()
{
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(function1()) x;
    decltype(function2()) y;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    return 0;
}
