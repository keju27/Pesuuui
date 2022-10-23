// Program to demonstrate the use of vector
#include <iostream>
#include <array>
using namespace std;

int main()
{
   	int ia[] = {0,1,2,3,4,5,6,7,8,9}; // ia is an array of ten ints
	int *beg = begin(ia); // pointer to the first element in ia
	int *last = end(ia); // pointer one past the last element in ia

	// Display the elements of the array
	while (beg != last)
    {
        cout << "Element is: " << *beg << endl;
        cout << "Pointer is: " << beg << endl;
        beg ++;
    }
}
