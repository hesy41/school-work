#include <iostream>
using namespace std;

void sendEmail (string name, string prize, bool condition);

int main() {
    string SName = "Shauna", JoName = "Jorge", JuName= "Juanita", SPrice = "a stuffed giraffe toy", 
    JoPrice = "a nintendo switch", JuPrice = "nothing";
    bool condition1 = true, condition2 = false;
    
    sendEmail (SName, SPrice, condition1);
    sendEmail (JoName, JoPrice, condition1);
    sendEmail (JuName, JuPrice, condition2);
    return 0;
}

void sendEmail (string name, string prize, bool condition)
{
   cout << "Dear " << name << ","<< endl;

    if (condition == false) 
       cout << "We're sorry that you did not win our raffle for charity."  << endl;
    else 
    {
        cout << "You are the winner of our raffle for charity." << endl;
        cout << "The prize was: " << prize << endl;
    }
    
    cout << "Thank you for giving to charity!" << endl;
    cout << "Sincerely," << endl;
    cout << "The Boolean Foundation" << endl;
    cout << endl;
}
