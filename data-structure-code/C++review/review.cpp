/*/codes for problem 5
#include <iostream>
#include <string>
using namespace std;


int main() {
	//variables
	string a = "welcome, dear student";
	//displaying 
	cout << "The string:: " << a << endl;
	cout << "The length of the string:: "<< a.length() << endl;
    cout << "The char at index 3 of the string:: "<< a[3] << endl;
    cout << "The char at index 1 of the string [using array]:: " << a[1] << endl;
    cout << "Is the string empty:: " << a.empty() << endl;
    cout << "Retrieve the sub-string from 10th position for 4 characters:: " << a[9] << a[10] << a[11] << a[12] << endl;

    //replace
    a[9]='g';
    a[10]='o';
    a[11]='o';
    a[12]='d';
    cout << "Replace the previous sub-string by 'good':: " << a << endl;


	
    return 0;
}*/

//problem 6
//Write a program to read a sequence of integers and print mode values of the sequence. 
//The number of integers is greater than or equals to 1 and less than or equals to 100. 
//Note: The mode of a set of data values is the value that appears most often.
/*#include <iostream>
#include <string>
using namespace std;
// function prototype
int mode(int[], int);

int main() {
    int num[7] = {4,4,4,6,7,3,3};

    cout << "Mode is " << mode(num, sizeof(num)/sizeof(num[0])) << endl;
    return 0;
}
//function def
int mode(int a[], int size)
{
    int mode, max=0, count;

    for (int i=0; i<size; i++)
    {
        count=0;
        for (int j=0; j<size; j++)
        {
            if (a[i]==a[j])
                count++;
        }
        if (count > max)
            {
                max = count;
                mode = a[i];
            }
    }
    return mode;
}*/

//problem 7
/*#include <iostream>
#include <string>
using namespace std;

string check(int num[], const int size) {

	int diff_arith = num[1] - num[0]; // for arith: we are looking for the subtractions 
    int diff_geo = num[1] / num[0]; //for geo: we are looking for the multifications 
	bool arith_flag = true, geo_flag = true;

	for (int y = 0; y < size-1; y++) // loop to check aru
	{
		if (num[y] + diff_arith != num[y + 1])
		{
			arith_flag = false;
            break;
		}
	}
	for (int z = 0; z < size - 1; z++)//loop to check geo
	{
		if (num[z] * diff_geo != num[z + 1])
		{
			geo_flag = false;
            break;
		}
	}
    //return message
	if (arith_flag)
		return "Arithmetic";
	else if (geo_flag)
		return "Geometric";
	else
		return "-1";
}

int main() {

	int num1[] = { 1, 3, 5, 7 };
	int num2[] = { 2, 4, 8, 16, 32 };
	int num3[] = { 1, 2, 3, 4, 5, 6, 8 };
	cout << check(num1, sizeof(num1) / sizeof(num1[0])) << endl;
	cout << check(num2, sizeof(num2) / sizeof(num2[0])) << endl;
	cout << check(num3, sizeof(num3) / sizeof(num3[0])) << endl;
	
	return 0;
}*/

//problem 8
//Write a program to sum of all positive integers in a sentence.
//Sample string: There are 7 chairs, 10 desks, 3 blackboard and 5 fans. 
//Output: 25
/*#include <iostream>
#include <string>
#include <cctype>
using namespace std;
//functuion prototype
int sum (string, int);

int main(){
    string a = "There are 7 chairs, 10 desks, 3 blackboard and 5 fans.";
    //cout << a.length();

    cout << "Output:" << sum(a,a.length()) << endl;

    return 0;
}
//function def
int sum(string a, int len)
{
    int sum = 0;
    int temp = 0;
    for (int i=0; i<len; i++)
    {
        if (isdigit(a[i]))
        {
            temp = a[i]-48; //converting char to int
            //cout << temp << endl;
            for (int j=i+1; j<len; j++)
            {
                if (isdigit(a[j]))//checking whether there is 2-digit or more-digit number
                {
                    int tempj = a[j]-48; //converting char to int 
                    temp = temp*10 + tempj ;
                    i = j+1; //palce the flag to the next char of the integer
                }
                else 
                    break;
            }
            sum = sum+temp;
        }
    }
    return sum;
}*/

//problem 9
//Write a program to read three ints and to print them in ascending order.
#include <iostream>
using namespace std;

int main(){
    int n1, n2, n3;
    cout << "Enter three integers to place in ascending order.";
    cin  >> n1 >> n2 >> n3;

    if (n3< n2 && n2< n1)
		cout << n3 << ", " << n2 << ", " << n1 << "." << endl;
	if (n2< n3 && n3< n1)
		cout << n2 << ", " << n3 << ", " << n1 << "." << endl;
	if (n3< n1 && n1< n2)
		cout << n3 << ", " << n1 << ", " << n2 << "." << endl;
	if (n1< n3 && n3< n2)
		cout << n1 << ", " << n3 << ", " << n2 << "." << endl;
	if (n1< n2 && n2< n3)
		cout << n1 << ", " << n2 << ", " << n3 << "." << endl;
	if (n2< n1 && n1< n3)
		cout << n2 << ", " << n1 << ", " << n3 << "." << endl;
    return 0;
}