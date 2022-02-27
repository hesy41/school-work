#include <iostream>
#include "util.h"
/* Implement all util functions */


/* Search for v in list[first...last]. If v appears in the sublist, return the index 
 * of its appearance; if v does not appear in the sublist, return the insert location
 * if v=[2,4,5,7,9], first=0, last=4, v=8, the function return 4
 * if v=[2,4,5,7,9], first=0, last=4, v=1, the function return 0
 * if v=[2,4,5,7,9], first=3, last=4, v=7, the function returns 3
 @param list: a vector of int, sorted in ascending order
 @param first, last: specify the range of vector where we search v in
 @param v: the value we are searching for
 @return: the index or insert location
 */
int BinarySearch (const vector<int> & list, int first, int last, int v)
{
	if (first == last){ //base case 1
		if (list[first] == v)
			return first;
		else if ( v > list[first])
			return first+1;
		else 
			return first;
	}

	if (first +1 == last){ //base case 2, when we have only 2 elements in the sublist
		if (v> list[last])
			return last+1;
		else if (v<list[first])
			return first;
		else
			return last;
	}

	int mid = (last+first)/2;
	if (list[mid] == v)
		return mid;
	else if (list[mid]<v)
		return BinarySearch (list, mid, last, v);
	else
   		return BinarySearch (list, first, mid, v);
}

/* sort the list with insertion sort iteratively
 @param list: a vector of int that needs to be sorted
 @return: no explictly return but the orginal list would be sorted
 */ 
void InsertionSort (vector<int> & list)
{
	for (int i=0; i<list.size()-1; ++i)
	{
		int min=i;
		for(int j=i+1; j<list.size(); ++j)
		{
			if (list[j]<list[min])
				min = j;
		}
		//put the minimal element of the unsorted sublist into the right position of the sorted list
		list.insert(list.begin()+BinarySearch(list, 0, i, list[min]), list[min]);
		//delete that element 
		list.erase(list.begin()+min+1);
	}
}

/* sort the list with insertion sort recursively
 @param list: a vector of int that needs to be sorted
 @return: no explictly return but the orginal list would be sorted
 */ 
void InsertionSort (vector<int> & list, int first, int last)
{
	if (first+1 == last)
		return;

	int min=first;
	for(int j=first+1; j<=last; ++j)
	{
		if (list[j]<list[min])
			min = j;
	}	
	//put the minimal element of the unsorted sublist into the right position of the sorted list
	list.insert(list.begin()+BinarySearch(list, 0, first, list[min]), list[min]);
	//delete that element 
	list.erase(list.begin()+min+1);
	//recursive call
	InsertionSort(list, first+1, last);
}

/* Return a vector storing all distinct values in the input vector
@param list: contain the data set
@pre: list has been initialized with a certain number of elements
@post: return a vector storing elements from list, all duplicates are removed, and
values keep the order of their ﬁrst occurrences in list, i.e., as 2 appears ﬁrst in list, it will
also appears ﬁrst in the returned vector.
***********running time analysis*****************
T(N)= N(N-1) for the total array access
In the inner loop, T(N)= N(N-1)/2 for accessing result[j] and list[i]
*/
vector<int> Distinct(vector<int> & list)
{
	vector<int> result;
	if (list.size()<2)
		return list;
	else{
		result.push_back(list[0]);
		for (int i=1; i<list.size(); i++)
		{
			bool duplicateFound = false;
			for (int j=0; j<result.size(); j++)
			{
				if (result[j]==list[i]){
					duplicateFound=true;
					break;
				}
			}
			if (duplicateFound==false)
			{
				result.push_back(list[i]);
			}
		}
		return result;
	}
}


/* Given two vectors of integers, check if the two vectors contain same set of values:
	@param list1, list2: two vectors of integers
	@pre: list1, list2 have been initialized
	@post: return true if list1 and list2 stores same values (in
		same or different order); return false, if not. */
bool SameSet (const vector<int> & list1, const vector<int> & list2)
{
	//for each value in list1, check if it appears in list2, if not, return false
	for (int i=0; i<list1.size(); i++)
	{
		bool found = false;
		for (int j=0; j<list2.size();j++)
		{
			if (list1[i] == list2[j]){
				found = true;
				break;
			}
		}
		if (!found)
			return false;
	}

	//for each value in list2, check if the value appears in list1, if not return false
	for (int i=0; i<list2.size(); i++)
	{
		bool found = false;
		for (int j=0; j<list1.size();j++)
		{
			if (list2[i] == list1[j]){
				found = true;
				break;
			}
		}
		if (!found)
			return false;
	}
	return true;
}

/* Given two vectors of chars, check if the two vectors are permutations of each other,
	i.e., they contains same values, in same or different order.
	@param list1, list2: two vectors of chars
	@pre: list1, list2 have been initialized
	@post: return true if list1 and list2 stores same values (in 
		same or different order); return false, if not. */
bool SameMultiSet (vector<char>  list1, vector<char>  list2)
{
	//we consider whether the two vectors are permutations of each other 
	//only if they have same number of items
	if (list1.size()!=list2.size()) 
		return false; 
	
	for (int i=0; i<list1.size(); ++i)
	{
		bool found = false;
		for (int j=0; j<list2.size(); ++j)
		{
			if (list1[i]==list2[j])
			{
				//since the vector is passed by value, 
				//editing directly on vector2 won't hurt the on in main
				list2.erase(list2.begin()+j);
				found = true;
			}
		}
		if (!found)
			return false;
	}

	if (list2.size()!=0)
		return false;

	return true;
}


