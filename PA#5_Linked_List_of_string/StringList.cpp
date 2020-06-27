// File Name: assign5_s_b611.cpp
// Author: Sonali Bante
// Date: 04/10/2019
// Assignment Number: 5
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
/* Implementation of an interface that manipulates a list of strings.  */

#include "StringList.h"
#include <string>
#include<iostream>
using namespace std;

/************************************************************************
* Constructor name: StringList - Function to set default value          *
************************************************************************/
StringList::StringList()
{
    head = NULL;            //initially list is empty
}

/****************************************************************************
* Destructor name: ~StringList - Function deallocates all the nodes in the  *
                                 list                                       *
****************************************************************************/
StringList::~StringList()
{
    while (head)
    {
        remove (head->next);  //removes each element coming in position of head
    }
}

/******************************************************************************
* function name: remove - removes the node that m points to from the          *
                          linked list                                         *
* param-1: *m  -  a new node in the list                                      *
******************************************************************************/
void StringList:: remove(StringNode *m)
{
    if(m==NULL)                      // if empty return nothing.
        return;

    if (m == head)                   // if its head node
    {
        head = head->next;           // make it to next pointer
        delete m;                    // and then delete it
    }
    else
    {
        StringNode *n=head;          // new node initialize to head
        while(n->next !=NULL && n->next!=m)
        {
            n = n->next;             // iterate till last node arrive
        }
        if(n)
        {
            n->next = m->next;      // put next node in last position of n
            delete m;               // then delete m
        }
    }
}


/******************************************************************************
* function name: maximum -returns a pointer of  last in alphabetical ordering *
* returns: max -  returns a pointer to the node containing the string that    *
                  would come last in alphabetical (ascii) ordering.           *
******************************************************************************/
StringList::StringNode * StringList:: maximum()
{
    StringNode *p=head;
    StringNode * max = head;  // to compare max value to each element
    if(head==NULL)
        return NULL;          // if empty return nothing.
    else
    {
        while(p)
        {
            if(p->data > max->data)    // finding max value
                max = p;
            p = p->next;               // progressing through each node.
        }
        return max;                   // return maximum value
    }
}

/******************************************************************************
* function name: count -s the total number of strings (nodes) in the list     *
* returns: count -  returns total count                                       *
******************************************************************************/
int StringList:: count()
{
    StringNode *p = head;  //p is a temporary pointer,
                           //initialize to point to first node
    int count = 0;
    while (p != NULL)      // till list is empty
    {
        count++;           // count each element
        p = p->next;       // progress through each node
    }
    return count;          // return final count
}

/******************************************************************************
* function name: push_front -  Adds a new node containing the string to the   *
                               front of the list                              *
* param-1: aData  - a string data to be used to add in list                   *
******************************************************************************/
void StringList:: push_front(string aData)
{
    StringNode *newNode = new StringNode; // new node is dynamically allocated
    newNode->data = aData;  // setting string to newnode
    newNode->next = head;
    head = newNode;         // making newnode head of the list
}

/******************************************************************************
* function name: push_back -   Adds a new node containing the string to the   *
                               end of the list                                *
* param-1: aData  - a string data to be used to add in list                   *
******************************************************************************/
void StringList::push_back(string aData)
{
    StringNode *newNode;

    newNode = new StringNode;
    newNode->data = aData;
    newNode->next = NULL;

    if (head==NULL)
        head = newNode;

    else
    {
        StringNode *p = head;
        while (p->next!=NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}

/******************************************************************************
* function name: pop_front - removes the first node, if the list is not empty *
******************************************************************************/
void StringList::  pop_front()
{
    if (head)
    {
        StringNode *p = head;
        head = head->next;
        delete p;
    }
}


/******************************************************************************
* function name: display -   displays the strings in the list to the screen   *
******************************************************************************/
void StringList:: display()
{
    StringNode *p = head;
    while (p!=NULL)
    {
        cout << p->data  << endl;
        p = p->next;
    }

}

/******************************************************************************
* function name: sort -   work according to given algorithm in question       *
******************************************************************************/
void StringList:: sort()
{

   StringNode *newList = NULL;
   StringNode *p = head;
   //head=NULL;

    while(p)
    {
      StringNode *newNode = new StringNode;
      StringNode *temp = maximum();
      newNode->data = temp->data;
      newNode->next = newList;
      newList = newNode;
      remove(temp);

      p = head;
    }
    head = newList;
}
