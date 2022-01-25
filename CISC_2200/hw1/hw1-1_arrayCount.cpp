/*homework1-problem1_arrayCount.cpp: counting the frequency of each element in a array
  author: Siyi He
  created on 2021-9-15 */
#include <iostream>
using namespace std;

//function prototype
void count(int arr[][5]);

int main() {
    int array[4][5]={1,2,3,4,5,6,7,8,1,2,3,4,1,2,3,4,1,2,3,4};
    
    count(array);
}

//function def
void count(int array[][5])
{
    int count_1=0, count_2=0, count_3=0, count_4=0, count_5=0;
    int count_6=0, count_7=0,count_8=0, count_9=0; //initialize all counters

    //count 
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        {
            switch(array[i][j])
            {
                case 1: {
                    count_1++;
                    break;
                }
                case 2: {
                    count_2++;
                    break;
                }
                case 3: {
                    count_3++;
                    break;
                }
                case 4: {
                    count_4++;
                    break;
                } 
                case 5: {
                    count_5++;
                    break;
                }
                case 6: {
                    count_6++;
                    break;
                }
                case 7: {
                    count_7++;
                    break;
                }
                case 8: {
                    count_8++;
                    break;
                }
                case 9: {
                    count_9++;
                    break;
                }
            }
        }
    }


    //output
    cout << "'1' repeated " << count_1 << " time(s);" << endl;
    cout << "'2' repeated " << count_2 << " time(s);" << endl;
    cout << "'3' repeated " << count_3 << " time(s);" << endl;
    cout << "'4' repeated " << count_4 << " time(s);" << endl;
    cout << "'5' repeated " << count_5 << " time(s);" << endl;
    cout << "'6' repeated " << count_6 << " time(s);" << endl;
    cout << "'7' repeated " << count_7 << " time(s);" << endl;
    cout << "'8' repeated " << count_8 << " time(s);" << endl;
    cout << "'9' repeated " << count_9 << " time(s);" << endl;
}