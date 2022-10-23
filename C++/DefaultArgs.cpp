// CPP Program to demonstrate Default Arguments
#include <iostream>
using namespace std;

// A function with default arguments,
// it can be called with 2 arguments or 3 arguments or 4 arguments.

int sum(int x, int y, int z = 0, int w = 0) //assigning default values to z,w as 0
{
	return (x + y + z + w);
}


int main()
{
	// Statement 1
	cout << sum(10,50) << endl;

	// Statement 2
	cout << sum(10, 15, 25) << endl;

	// Statement 3
	cout << sum(10, 15, 25, 30) << endl;
	return 0;
}
