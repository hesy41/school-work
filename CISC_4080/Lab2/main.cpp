/* Starter code for lab2
 */
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "util.h"
#include <assert.h>
using namespace std;

bool TestBinarySearch()
{

	// case 1
	vector<int> input1{2, 4, 8, 12, 20, 30};

	int output1 = BinarySearch(input1, 0, input1.size() - 1, 1);

	if (output1 != 0) // if fails this, don't continue to next one
		return false;

	// case 2
	int output2 = BinarySearch(input1, 0, input1.size() - 1, 8);
	if (output2 != 2)
		return false;

	// case 3
	int output3 = BinarySearch(input1, 0, input1.size() - 1, 18);
	if (output3 != 4) // is the output as expected?
		return false;

	return true;
}

bool TestInsertionSort()
{
	vector<int> input1{3, 2, 4, 8, 12, 1, 5};
	vector<int> expected_output1{1, 2, 3, 4, 5, 8, 12};

	InsertionSort(input1);

	if (input1 != expected_output1)
		return false;
	else
		return true;
}

bool TestInsertionSortRecursive()
{
	vector<int> input1{3, 2, 4, 8, 12, 1, 5};
	vector<int> expected_output1{1, 2, 3, 4, 5, 8, 12};

	InsertionSort(input1, 0, input1.size() - 1);

	if (input1 != expected_output1)
		return false;
	else
		return true;
}

bool TestDistinct()
{

	// case 1
	vector<int> input1{3, 2, 4, 8, 2, 2, 3}; // unique mode: 2
	vector<int> expected_output{3, 2, 4, 8};
	vector<int> output1 = Distinct(input1);
	if (output1 != expected_output) // if fails this, don't continue to next one
		return false;

	// case 2
	vector<int> input2{3, 3, 2, 4, 4, 4, 8, 2, 2, 3}; // have three modes
	vector<int> expected_output2{3, 2, 4, 8};
	vector<int> output2 = Distinct(input2);

	// is the output as expected?
	if (output2 != expected_output2)
	{
		return false;
	}
	return true;
}

bool TestSameSet()
{
	vector<int> v1{3, 2, 4, 2};
	vector<int> v2{2, 3, 4};
	if (!SameSet(v1, v2))
		return false;

	vector<int> v3{3, 1, 4, 2};
	vector<int> v4{2, 3, 4};
	if (SameSet(v3, v4) != false)
		return false;

	vector<int> v5;
	vector<int> v6{2, 3, 4};
	if (SameSet(v5, v6) != false)
		return false;
	return true;
}

bool TestSameMultiSet()
{
	vector<char> v1{'a', 'b', 'd', 'a', 'b'};
	vector<char> v2{'a', 'b', 'd'};
	if (SameMultiSet(v1, v2) != false)
		return false;

	vector<char> v3{'a', 'a', 'b'};
	vector<char> v4{'b', 'a', 'a'};
	if (SameMultiSet(v3, v4) != true)
		return false;

	vector<char> v5{'h', 'e', 'l', 'l', 'o'};
	vector<char> v6{'e', 'o', 'h', 'l', 'l', 'l'};
	if (SameMultiSet(v5, v6) != false)
		return false;

	return true;
}

int main(int argc, char **argv)
{
	// uncomment these functions call one by one
	if (argc == 2)
	{
		if (!strcmp(argv[1], "binarysearch"))
			if (TestBinarySearch())
			{
				cout << "Passed BinarySearch test cases\n";
				return 0;
			}
			else
			{
				cout << "Failed BinarySearch test cases\n";
				return 1;
			}
		else if (!strcmp(argv[1], "insertionsort"))
			if (TestInsertionSort())
			{
				cout << "Passed InsertionSort test cases\n";
				return 0;
			}
			else
			{
				cout << "Failed InsertionSort test cases\n";
				return 1;
			}
		else if (!strcmp(argv[1], "recursive_insertionsort"))
			if (TestInsertionSortRecursive())
			{
				cout << "Passed Recursive InsertionSort test cases\n";
				return 0;
			}
			else
			{
				cout << "Failed InsertionSort test cases\n";
				return 1;
			}

		else if (!strcmp(argv[1], "distinct"))
			if (TestDistinct())
			{
				cout << "Passed Distinct test cases\n";
				return 0;
			}
			else
			{
				cout << "Failed Distinct test cases\n";
				return 1;
			}

		else if (!strcmp(argv[1], "sameset"))
			if (TestSameSet())
			{
				cout << "Passed SameSet test cases\n";
				return 0;
			}
			else
			{
				cout << "Failed SameSet test cases\n";
				return 1;
			}

		else if (TestSameMultiSet())
		{
			cout << "Passed SameMultiSet test cases\n";
			return 0;
		}
		else
		{
			cout << "Failed SameMultiSet test cases\n";
			return 1;
		}
	}
	else
	{

		if (TestBinarySearch())
			cout << "Passed BinarySearch test cases\n";
		else
			cout << "Failed BinarySearch test cases\n";
		if (TestInsertionSort())
			cout << "Passed InsertionSort test cases\n";
		else
			cout << "Failed InsertionSort test cases\n";
		if (TestDistinct())
			cout << "Passed Distinct test cases\n";
		else
			cout << "Failed Distinct test cases\n";

		if (TestSameSet())
			cout << "Passed SameSet test cases\n";
		else
			cout << "Failed SameSet test cases\n";

		if (TestSameMultiSet())
			cout << "Passed SameMultiSet test cases\n";
		else
			cout << "Failed SameMultiSet test cases\n";
	}
}
