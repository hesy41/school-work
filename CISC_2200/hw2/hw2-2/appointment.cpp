/* homework2_problem2_appointment.cpp
    author: Siyi He
    created: 2021-10-1
*/

#include <iostream>
#include "appointment.h"
using namespace std;

struct nodeType
{
    int year;
    int month;
    int day;
    nodeType* next;
};

appointment::appointment()
{
    length = 0;
    listData = NULL;
}

appointment::~appointment()
{
    nodeType* temp;

    while (listData != NULL)
    {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
}

void appointment::PutItem(int newY, int newM, int newD)
{
    //because this list is unsorted, we can simply add a node from the head
    nodeType* newItem;
    newItem = new nodeType; //creat a new node here

    //store the target information into newItem
    newItem->year=newY;
    newItem->month=newM;
    newItem->day=newD;
    newItem->next=listData; //add the newItem to the front of the list

    listData=newItem;//make the head pointer(listData) pointing to the new first node
    length++;//length increasement
}

void appointment::deleteItem(int dYear, int dMonth, int dDay)
{
    nodeType* location=listData;
    nodeType* deletion;

    if (dYear==location->year && dMonth==location->month && dDay==location->day)
    {
        //when we want to delete the first node
        deletion=location;
        listData=listData->next;
    }
    else //when we need to delete an item in the middle of linked list
    {
        //check whether the location->next is the target to delete
        while ((location->next)->year!=dYear || 
               (location->next)->month!=dMonth || (location->next)->day!=dDay)
        {
            //if it is not, move location points to the next node
            location = location->next;
        }
        //if it is, delete location->next
        deletion=location->next; //move deletion pointer to the target node
        location->next=(location->next)->next; //make new connection to the gap
    }
    delete deletion;
    length--;
}

bool appointment::isfull() const
{
    nodeType* location;
    try
    {
        //try whether it is possible to make a new node 
        location= new nodeType; 
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

bool appointment::compareAppointment(nodeType* a, nodeType* b)
{
    if (a!=NULL && b!=NULL)
    {
        if (a->year==b->year && a->month==b->month && a->day==b->day)
            return true;
        else
            return false;
    }
    return (a==NULL && b==NULL);
    //if a&b are both null, return true, overwise, return false
}

bool appointment::SearchItem(int tyear, int tmonth, int tday)
{
    nodeType* location = listData;
    if (location == NULL)
        return false;
    else 
    {
        while (location != NULL)
        {
            if (location->year==tyear && location->month==tmonth && location->day==tday)
                return true;
            else
            {
                location = location->next;
            }
        }
        return false;
    }
}

void appointment::EmptyList()
{
    nodeType* temp;

    while (listData!=NULL)
    {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
    length = 0;
}

void appointment::PrintList()
{
    nodeType* temp;
    temp = new nodeType;
    temp = listData;

    while (temp!=NULL)
    {
        cout << "Appointment info:" << endl;
        cout << "year: " << temp->year << "; month: " << temp->month;
        cout << "; day: "<< temp->day << endl;
        temp = temp->next;
    }
}