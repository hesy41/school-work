#include <iostream>
#include <string>
using namespace std;

string life(int& age, bool is_alive, string birthday, string today)
{
    string message;
    if (is_alive == true && today == birthday)
        age ++;
    message = to_string(age);
    message = "Happy " + message + " Birthday!" ;
    return message;
}

int main()
{
    int age = 18;
    string birthday = "Dec 18";
    string today = "Dec 18";
    bool is_alive = true;
    string LoveYou = life(age, is_alive, birthday, today);
    cout << LoveYou << endl;
    return 0;
}