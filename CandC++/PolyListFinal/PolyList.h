/*************************************************************
Name: PolyList.h Header File

Author: Oakley Hall
CSCI 235 - Stamos

Date: September 21, 2009

Purpose: PolyList is designed to create and store polynomials
as a linked lists in and array. It also allows users to print
the polynomial, delete specific terms or the entire poly and
to quit the application when finished.

***************************************************************/
#ifndef POLYLIST_H
#define POLYLIST_H
#include "ListException.h"
#include "ListIndexOutOfRangeException.h"
typedef int ListItemType;
const int MAX_P = 20;
static int index;
class List
{
public:
// Constructors and destructor:
   List();//Default constructor.
   List(const List& aList);//Copy constructor

//Polynomial List operations
   ~List();//Destructor.
   void createNewList();//create new list
   bool isEmpty() const;
   int getLength() const;
   void remove(int index)//remove individual terms from poly
      throw(ListIndexOutOfRangeException);
    void destroy();//delete entire poly
    void print();//print poly
//end list ooperations

private:

   struct PolyNode//node with which link list items will be constructed.
   {

      double coefficient;//data items
      int exponent;//data item
      PolyNode *next;//poiter to next node in the list.
   }; // end PolyNode



   int size;//number of items in the list
   PolyNode *head; //pointer to head node.
   PolyNode *p;//pointer to list body node.

   PolyNode *find(int index) const;//Located specific node in linked list
                                //index is desired node, returns pointer to index'th node.

}; // end List
// End of header file.
#endif
