//Siyi He
//Dec. 17, 2020
//final#2

#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

//phototype
void issueInput(string[], int);
void ratingInput (string[], double[], int);
void averageCounting (double[], double[], int, int);

int main ()
{
    //varible 
    const int arrSize=5;
    string issue[arrSize], answer;
    int entry=0,i;
    double total[arrSize], aver[arrSize];


    //input
    issueInput(issue, arrSize);
    cout << endl;

    do
    {
        entry ++;
        cout << "Survey Entry # " << entry << endl;

        ratingInput(issue, total, arrSize);
        cout << endl;

        cout << "Do you want to take the survey again? (Yes or No) : ";
        cin  >> answer;
        cout << endl;

    } while (answer == "Yes" || answer == "yes");

    //processing 
    averageCounting (total, aver, arrSize, entry);

    //output 
    cout << "Results for " << entry << "Entries" << endl;
    cout << "Topics" << setw( 10 ) << "Total" << setw( 15 ) << "Average" << endl;
    cout << "------" << setw( 10 ) << "-----" << setw( 15 ) << "-------" << endl;
    
    for (i=0; i< arrSize; i++)
    {
        cout << issue[i] << setw( 10 ) << total[i] << setw( 15 ) << aver[i] << endl;
    }
    cout << endl;
    cout << "Goodbye!" << endl;

    return 0;
}

//function definition 
void averageCounting (double tt[], double a[], int size, int entry)
{
    int i;
    for (i=0; i<size; i++)
    {
        a[i] = tt[i] / entry;
    }
}

void issueInput (string iss[], int size)
{
    int i;
    cout << "Enter 5 current issues to rate:" << endl;
    
    for (i=0; i<size; i++)
    {
        cout << "Enter topic (Politics, Economy, etc.) : ";
        cin  >> iss[i];
    }
}

void ratingInput (string iss[], double tot[], int size)
{
    int i;
    double rate;
    cout << "Please rank the following issues on their importance to you, where 1 is least important and 10 is most important:" << endl;

    for (i=0; i<size; i++)
    {
        cout << iss[i] << ": ";
        cin  >> rate;

        tot[i] = tot[i] + rate;
    }
}