//Siyi He
//Oct. 9, 2020
//R02- hw#5 calculate the grade

#include <iostream>
using namespace std;

int main()
{
    //varible 
    int exerciseNum, exerciseScore, exerciseScoreMax, i, totalScore ; 
    float totalScoreMax;
    double totalPercentage;

    //input
    cout << "How many exercises to input? ";
    cin  >> exerciseNum;
    cout << endl;

    //procesing
    for (i = 0; i < exerciseNum; i++)
    {
        cout << "Score received for exercise " << i + 1 << ": ";
        cin  >> exerciseScore;
        cout <<  "Total points possible for exercise " << i + 1 << ": ";
        cin  >> exerciseScoreMax;
        cout << endl;

        //total score calculation
        totalScore = totalScore + exerciseScore;
        totalScoreMax = totalScoreMax + exerciseScoreMax;
    }

    //percentage processing 
    totalPercentage = (totalScore / totalScoreMax) * 100;

    //output
    cout << "Your total is " << totalScore << " out of " << totalScoreMax << ", or " << totalPercentage << "%." << endl;

    return 0;
}