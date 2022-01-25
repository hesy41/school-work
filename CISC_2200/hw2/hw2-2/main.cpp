/* homework2_problem2_main.cpp (bounus question)
    author: Siyi He
    created: 2021-10-1
*/

#include <iostream>
#include "appointment.h"
//#include "appointment.cpp"
using namespace std;

int main()
{
    appointment appointmentList;
    char answer, command;
    answer = 'y';
    int year, month, day;

    //first put 2 appointments in the list
    appointmentList.PutItem(2021,10,1);
    appointmentList.PutItem(2019,5,19);

    while (answer == 'y')
    {
        cout << "Command list: " << endl;
        cout << "(D)isplay: display all appointments" << endl;
        cout << "(A)dd: add a new appointment. If there is already an appointment on the date, reports error. " << endl;
        cout << "(S)earch: search for an appointment on a user specified date " << endl;
        cout << "D(e)lete: delete an appointment on a user specified date" << endl;
        cout << "(Q)uit: to quite the program" << endl;
        cout << "What's your command? ";
        cin  >> command;

        switch (command)
        {
        case 'D':
        case 'd':
            appointmentList.PrintList();
            break;

        case 'A':
        case 'a':
        {
            cout << "Enter the year of the appointment : ";
            cin  >> year;
            cout << "Enter the month of the appointment: ";
            cin  >> month;
            cout << "Enter the day of the appointment: ";
            cin  >> day;
            if (appointmentList.SearchItem(year, month, day))
                cout << "Error: appoinment existed." << endl;
            else if (appointmentList.isfull())
                cout << "Error: the appointment list is full." << endl;
            else
            {
                appointmentList.PutItem(year,month,day);
                cout << "appointment added" << endl;
            }
            break;
        }

        case 'S':
        case 's':
        {
            cout << "Enter the year of the appointment: ";
            cin  >> year;
            cout << "Enter the month of the appointment: ";
            cin  >> month;
            cout << "Enter the day of the appointment: ";
            cin  >> day; 
            if (appointmentList.SearchItem(year,month,day))
                cout << "This appointment already existed." << endl;
            else 
                cout << "The target appointment does not exist." << endl;
            break;
        }

        case 'e':
        case 'E':
        {
            cout << "Enter the year of the appointment: ";
            cin  >> year;
            cout << "Enter the month of the appointment: ";
            cin  >> month;
            cout << "Enter the day of the appointment: ";
            cin  >> day;  
            if (!appointmentList.SearchItem(year,month,day))
                cout << "Error: the target appointment does not exist in the list." << endl;
            else
            {
                appointmentList.deleteItem(year,month,day);
                cout << "Appointment deleted." << endl;
            }
            break;
        }

        case 'Q':
        case 'q':
        {
            answer = 'n';
            cout << "program ended." << endl;
            break;
        }
        default:
            break;
        }
        cout << endl; //make a line empty between each command
    }
    return 0;
}