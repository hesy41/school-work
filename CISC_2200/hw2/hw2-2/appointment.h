/* homework2_problem2_appointment.h
    author: Siyi He
    created: 2021-10-1
*/

#include <iostream>
using namespace std;

struct nodeType; 

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

class appointment
{
    public:
        appointment();
        /*constructor*/

        ~appointment();
        /*destructor*/

        void PutItem(int year, int month, int day);
        /*put a new item in to the head of the list*/

        void deleteItem(int year, int month, int day);
        /*delete an existing appointment*/

        bool isfull() const;
        /*check whether the memory for creating new items is full
           retrun true if it is full, otherwise, return false
        */

        bool compareAppointment(nodeType* a, nodeType* b);
        /*compare two appointments
           retrun true if they are identical, otherwise, return false
        */

       bool SearchItem(int year, int month, int day);
       /*search whether an appointment exists in the list of appointments or not
         return true if there exists the target, otherwise, return false 
       */

       void EmptyList();
       /*empty the list of appointments*/

       void PrintList();
       /*display the list of existing appointments*/
        
    private:
        nodeType* listData;
        nodeType* currentPosition;
        int length;
};

#endif
