//Siyi He
//Oct. 8, 2020
//R02- calculate the total grade 

#include <iostream>
using namespace std;

int main ()
{
    //varible 
    int candyNum, edocNum, margorpNum, experience, candies_edoc_transfer = 0; 

    //input 
    cout << "Enter the number of Edoc you have caught: ";
    cin  >> edocNum;
    cout << "Enter the number of Edoc candy in your possession: ";
    cin  >> candyNum;

    //processing
    do
    {
        for (margorpNum = 0; candyNum >= 12 && edocNum >= 1; margorpNum++ )
        {
            //one evolution process
            candyNum = candyNum - 11;
            edocNum = edocNum -1;
            experience =  experience + 500;
        }

        cout << "Evolve " << margorpNum << " into to Margorp." << endl;
        cout << "Now you have " << candyNum << " candies, " << edocNum << " Edoc and " << margorpNum << " Margorp! " << endl;
        cout << endl;

        // transfer all Margrop into candies
        candyNum = candyNum + margorpNum;
        cout << "Transfer all Margorp into candies. And you get " << candyNum << " candies." << endl;
        cout << endl;

        //candies-edoc match 
        for (candies_edoc_transfer = 0; candyNum < 12 && edocNum > 1; candies_edoc_transfer++)
        {
            edocNum = edocNum -1;
            candyNum = candyNum + 1;
        }
        cout << "Transfer " << candies_edoc_transfer << " Edoc into candies." << endl;
        cout << "Now you have " << candyNum << " candies, " << edocNum << " Edoc and " << margorpNum << " Margorp! " << endl; 
        
    }
    while (candyNum >= 12 && edocNum >= 1);
    
    //output
    cout << "Total experience points = " << experience << endl;

    return 0;
}