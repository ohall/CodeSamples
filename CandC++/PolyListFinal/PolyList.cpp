/*************************************************************
Name: PolyList.cpp Implementation File

Author: Oakley Hall
CSCI 235 - Stamos

Date: September 21, 2009

Purpose: PolyList is designed to create and store polynomials
as a linked lists in and array. It also allows users to print
the polynomial, delete specific terms or the entire poly and
to quit the application when finished.

***************************************************************/
#include <iostream>
#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "PolyList.h"     // header file

using namespace std;



List::List() : size(0), head(NULL)//implememntation of default comstructor, initializing list values
{
}

void List::createNewList()//create a new Polynomial by linking nodes
{

     cout<<"Create: enter number of terms"<<endl;
            cin >> List::size;
            head = new PolyNode;

            cout<<"enter coefficient 1 "<<endl;
            cin >> head->coefficient; //place user assigned value in head node
            cout<<"enter exponent 1 "<<endl;
            cin >> head->exponent;

            head->next=NULL;//sets pointer from head to NULL
            p = head;//sets head as current node p

           for (int i=1;i<size;i++)
              {
                p->next = new PolyNode;//P node points to new node
                p = p->next;
                cout<<"enter coefficient "<<i+1<<endl;
                cin>>p->coefficient;
                cout<<"enter exponent "<<i+1<<endl;
                cin>>p->exponent;
                }//end for
                p->next = NULL;

              PolyNode *cur = head;
              int i=0;
              cout<<"\nPolynomial entered  = ";
              while (cur != NULL)
                {
                    cout<<cur->coefficient<<"x^"<<cur->exponent;

                    cur = cur->next;
                        if (i < size-1)//if statement avoids extraneous '+' sign
                        {
                        cout <<" + ";
                        i++;
                        }//end if

                }//end for
                cout<<"\n";
}//end creatNewList

List::List(const List& aList)//copy constructor
   : size(aList.size)
{
   if (aList.head == NULL)
      head = NULL;  // original list is empty

   else
   {  // copy first node
      head = new PolyNode;
      head->coefficient = aList.head->coefficient;

      // copy rest of list
      PolyNode *newPtr = head;  // new list pointer
      // newPtr points to last node in new list
      // origPtr points to nodes in original list
      for (PolyNode *origPtr = aList.head->next;
	   origPtr != NULL;
	   origPtr = origPtr->next)
      {  newPtr->next = new PolyNode;
         newPtr = newPtr->next;
	 newPtr->coefficient = origPtr->coefficient;
      }  // end for

      newPtr->next = NULL;


   }  // end if
}  // end copy constructor

List::~List()//destructor
{
   while (!isEmpty())
      remove(1);
}  // end destructor

bool List::isEmpty() const//finds empty list and returns boolean value
{
   return size == 0;
}  // end isEmpty

int List::getLength() const// gets the size of the polynomial
{
   return size;
}  // end getLength

List::PolyNode *List::find(int index) const// find fumction finds specific nodes within list
{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {  PolyNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }  // end if
}  // end find

void List::remove(int index) throw(ListIndexOutOfRangeException)//remove, deletes specific nodes
{
   PolyNode *cur;


 if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException(
	 "ListIndexOutOfRangeException: remove index out of range");
   else
   {
       --size;
      if (index == 1)
      {  // delete the first node from the list
         cur = head;  // save pointer to node
         head = head->next;
      }

      else
      {  PolyNode *prev = find(index - 1);
         // delete the node after the node to which prev points
         cur = prev->next;  // save pointer to node
	 prev->next = cur->next;
      }  // end if

      // return node to system
      cur->next = NULL;
      delete cur;
      cur = NULL;
   }  // end if
}  // end remove

void List::print()//used to print entire polynomials
{
    int i = 0;
    if (head == NULL)//
    cout<<"No Polynomial to print\n";

    else
    {   cout<<"\n";
        for (PolyNode *cur = head; cur != NULL; cur = cur->next)
        {
        cout<<cur->coefficient<<"x^"<<cur->exponent;
        if (i < size-1)//if statement avoids extraneous '+' sign
               {
               cout <<" + ";
               i++;
               }//end if
        }//end for
    }//end else
    cout<<"\n";
}//end print()

void List::destroy()//deletes entire polynomial
{                   //uses same structure as destructor
  if (head == NULL)
  cout<<"No Polynomial to Delete\n";

  else
  {
   while (!isEmpty())
      remove(1);
  }
}// end destroy

