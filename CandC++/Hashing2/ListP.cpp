/*************************************************************
Name: Hashing2 ListP.cpp
Author: Oakley Hall
CSCI 235 - Stamos

Date: December 10, 2009

Purpose: Hashing2 implements three programs.  One using a bad hash
function, one using a good hash function and one is a spell checker
Please see README.txt for more details.
***************************************************************/

#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "ListP.h"   // header file
#include <string>

using namespace std;

// definitions of methods follow:
//   . . .
List::List() : size(0), head(NULL)//implememntation of default comstructor, initializing list values
{
}


List::List(const List& aList)
   : size(aList.size)
{
   if (aList.head == NULL)
      head = NULL;  // original list is empty

   else
   {  // copy first node
      head = new ListNode;
      head->word = aList.head->word;

      // copy rest of list
      ListNode *newPtr = head;  // new list pointer
      // newPtr points to last node in new list
      // origPtr points to nodes in original list
      for (ListNode *origPtr = aList.head->next;
	   origPtr != NULL;
	   origPtr = origPtr->next)
      {  newPtr->next = new ListNode;
         newPtr = newPtr->next;
	 newPtr->word = origPtr->word;
      }  // end for

      newPtr->next = NULL;
   }  // end if
}  // end copy constructor

List::~List()
{
   while (!isEmpty())
      remove(1);
}  // end destructor

bool List::isEmpty() const
{
   return size == 0;
}  // end isEmpty

int List::getLength() const
{
   return size;
}  // end getLength

List::ListNode *List::find(int index) const
{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {  ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }  // end if
}  // end find

void List::retrieve(int index,
                    string dataItem) const
{
   if ( (index < 1) || (index > getLength()) )
      cout<<"ListIndexOutOfRangeException: retrieve index out of range"<<endl;
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->word;
      cout<<dataItem<<" ";
   }  // end if
}  // end retrieve

void List::insert(int index, string newItem)
{
   int newLength = getLength() + 1;

   if ( (index < 1) || (index > newLength) )
      cout<<"ListIndexOutOfRangeException: insert index out of range"<<endl;
   else
   {  // try to create new node and place newItem in it
     ListNode *newPtr = new ListNode;
	 size = newLength;
	 newPtr->word = newItem;

	 // attach new node to list
	 if (index == 1)
	 {  // insert new node at beginning of list
	    newPtr->next = head;
	    head = newPtr;
	 }//end if
	 else
	 {  ListNode *prev = find(index-1);
            // insert new node after node
            // to which prev points
            newPtr->next = prev->next;
	    prev->next = newPtr;
	 }  // end else
   }  // end else
}  // end insert

void List::remove(int index)
{
   ListNode *cur;

   if ( (index < 1) || (index > getLength()) )
      cout<<"ListIndexOutOfRangeException: remove index out of range"<<endl;
   else
   {  --size;
      if (index == 1)
      {  // delete the first node from the list
         cur = head;  // save pointer to node
         head = head->next;
      }

      else
      {  ListNode *prev = find(index - 1);
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


void List::createNewList(string word)//create a new Polynomial by linking nodes
{
            head = new ListNode;
            head->word = word; //place user assigned value in head node
            head->next=NULL;//sets pointer from head to NULL
            //ListNode * curr = head;//sets head as current node p
}//end creatNewList

void List::print()//used to print
{
         for (ListNode *cur = head; cur != NULL; cur = cur->next)
            cout<<cur->word<<" ";
         cout<<"\n";
}//end print()

bool List::compare(string text)//used to print entire polynomials
{
        ListNode *cur = head;
        while (cur != NULL )
        {

            if (cur->word==text)
            return true;
            else
            cur = cur->next;

        }//end while
        return false;

}//end compare()


