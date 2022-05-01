/* Siyi He
   created time: 2022-01-29
   CISC 4080: computer algorthims lab1
   Goal:
        1.Implement bubble sort, selection sort iteratively and recursively.
        2.Implement linear search.
        3.Familiarize with C++ STL class vector
*/

#include <iostream>
#include <vector>
using namespace std;

/*selection: iterative selection sort function
  @arr: input array 
  @size: size of the input array
  precon: an arry that need to be sorted and the size of the array
  postcon: arr[0..size-1] is sorted */
void selection(vector<int>& arr, int size);

/*rselection: recursive selection sort function
  @arr: input array  
  @size: size of the input array
  precon: an arry that need to be sorted and the size of the array
  postcon: arr[0..size-1] is sorted */
void rselection(vector<int>& arr, int size);

/*bubble: iterative bubble sort function
  @arr: input array 
  @size: size of the input array
  precon: an arry that need to be sorted and the size of the array
  postcon: arr[0..size-1] is sorted */
void bubble(vector<int>& arr, int size);

/*rbubble: recursive bubble sort function
  @arr: input array 
  @size: size of the input array
  precon: an arry that need to be sorted and the size of the array
  postcon: arr[0..size-1] is sorted*/
void rbubble(vector<int>& arr, int size);

int main(){
    vector<int> Mylist;
    int size;
    int n;
    string algo;
    
    //user input
    //cout << "How many number are there in your list?";
    cin  >> size; 
    for (int i = 0; i < size; ++i)
    {
        cin >> n;
        Mylist.push_back(n);
    }

    //cout<< "select your algo";
    cin >> algo;

    if (algo == "selection")
        selection(Mylist,size);
    else if (algo == "rselection")
        rselection(Mylist,size);
    else if (algo == "bubble")
        bubble (Mylist, size);
    else if(algo == "rbubble")
        rbubble(Mylist, size);
    else
        cout<< "invaild command" << endl;

    //print the list
    for (int i = 0; i < size; ++i)
    {
        cout << Mylist[i] << " ";
    }
    cout << endl;

    return 0;
}

/*selection: iterative selection sort function*/
void selection(vector<int>& arr, int size)
{
    for (int i=0; i<size; ++i)
    {
        int smallest=i;
        //linear search for the smallest item in the unsorted part of the list
        for (int j=size-1; j>i; j--)
        {
            if (arr[j]<arr[smallest])
                smallest = j;
        }
        //"select" the smallest and put it in the sorted place
        if (smallest != i)
            swap(arr[i], arr[smallest]);
    }
}

/*rselection: recursive selection sort function
  sss: helper function for recursive selection sort so that users dont think of recursion when using it in main
  sss@ a: the list the need to be sorted
  sss@ size: size of the list
  sss@ position: keep track of the current position for recursive call*/
void sss(vector<int>& a, int size, int position);

void rselection(vector<int>& arr, int size)
{
    int current_position=0;
    sss(arr,size,current_position);
}

void sss(vector<int>& a, int size, int position)
{
    int smallest_position = position;

    if (position < size)
    {
        //linear search for the smallest item in the unsorted part of the list
        for (int i=position; i<size; i++)
        {
            if (a[i] < a[smallest_position])
                smallest_position = i;
        }
        //"select" the smallest and put it in the sorted place
        swap(a[smallest_position], a[position]);

        //move to the next positon
        position++;
        sss(a, size, position);
    }
}

/*bubble: iterative bubble sort function*/
void bubble(vector<int>& arr, int size)
{
    bool swapping = false;
    for (int i=0; i<size; i++)
    {
        for (int j= size-1; j>i; j--)
        {
            if (arr[j]<arr[j-1])
            {
                swap(arr[j], arr[j-1]);
                swapping = true;
            }
        }
        if (swapping == false)
            return;
    }
}

/*rbubble: recursive bubble sort function
  recursively, we decrese "size of the array" to sort the smaller part
  when size is decreased to 1, the array is sorted*/
void rbubble(vector<int>& arr, int size)
{
    //base case
    if (size == 1)
        return;
    
    //bubble down: push the largest element to the right
    for (int i=0; i<size-1; i++)
    {
        if (arr[i]>arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    rbubble(arr, size-1);
}