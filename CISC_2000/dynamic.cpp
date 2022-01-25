#include <iostream>
using namespace std;

/* A function that reads a sequence of integers from input to fill a dynamically allocated array. For example, if the length is 3, and the numbers are 123 345 99 then the array returned will be of size 3, and stores values 123, 345 and 99.
@param size: upon return, stores the size of the array
@return the pointer pointing to the array
*/
int * ReadNumberSequence(int & size)
{
	int * array = NULL; // initialize the pointer to NULL
	do {
		cout << "Enter the length of the number sequence:";
		cin >> size;
	} while (size <= 0);
	// Todo: Write a statement to allocate memory for the array.
	array = new int[size];

	// Note: we know the value of size only at run time, so we need to DYNAMICALLY
	// Todo: write a loop to read size # of int from input, and store in the array
	cout << "Enter " << size << " number of elements to store in the array: ";
	for (int index=0; index<size; index++)
	{
		cin  >> array[index];
	}

	return array;
}
int main()
{
	// Todo: delcare necesssary variables
	int size, *p= NULL;
	// Todo: call the ReadNumberSequence function to read a sequence of numbers 
	p = ReadNumberSequence (size);

	// Todo: write a loop to display the elements in the array returned ...
	for (int i=0; i<size; i++)
	{
		cout << p[i]<< endl;
	}

	// Todo: free the array returned by ReadNumberSequence.
	delete p;

	return 0;
}
