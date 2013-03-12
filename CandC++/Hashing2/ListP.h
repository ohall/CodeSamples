/*************************************************************
Name: Hashing2 ListP.h
Author: Oakley Hall
CSCI 235 - Stamos

Date: December 10, 2009

Purpose: Hashing2 implements three programs.  One using a bad hash
function, one using a good hash function and one is a spell checker
Please see README.txt for more details.
***************************************************************/
#ifndef ListP_H
#define ListP_H
#include <string>
#include <iostream>


using namespace std;

//typedef int ListItemType;
//typedef string ListItemType;

/** @class List
 * ADT list - Pointer-based implementation. */
class List
{
public:
// Constructors and destructor:

   /** Default constructor. */
   List();

   /** Copy constructor.
    * @param aList The list to copy. */
   List(const List& aList);

   /** Destructor. */
   ~List();

// List operations:
   bool isEmpty() const;
   int getLength() const;
   void insert(int index, std::string newItem);
   void remove(int index);
   void retrieve(int index, std::string dataItem) const;
   void createNewList(std::string word);
   void print();
   bool compare(string);
int       size;
private:
   /** A node on the list. */
   struct ListNode
   {
      /** A data item on the list. */
      std::string word;
      /** Pointer to next node. */
      ListNode    *next;
   }; // end ListNode

   /** Number of items in list. */

   /** Pointer to linked list of items. */
   ListNode *head;
   friend class Hash;

   /** Locates a specified node in a linked list.
    * @pre index is the number of the desired node.
    * @post None.
    * @param index The index of the node to locate.
    * @return A pointer to the index-th node. If index < 1
    *         or index > the number of nodes in the list,
    *         returns NULL. */
   ListNode *find(int index) const;
}; // end List
#endif
// End of header file.
