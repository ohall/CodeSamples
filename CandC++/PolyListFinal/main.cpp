/*************************************************************
Name: PolyList Main

Author: Oakley Hall
CSCI 235 - Stamos

Date: September 21, 2009

Purpose: PolyList is designed to create and store polynomials
as a linked lists in and array. It also allows users to print
the polynomial, delete specific terms or the entire poly and
to quit the application when finished.

***************************************************************/


#include <iostream>
#include "PolyList.h"
using namespace std;
char selection;//char fpr menu selection
int polyNum;//position within array of polynomials
List arrayL[MAX_P];



int main()

{

cout<<"Welcome to the Polynomial List\n";

  do{
    cout<<"\nPlease select one of the following options: \n";
        cout<< "c for create\n";
        cout<< "d for delete\n";
        cout<< "t for deletion of term\n";
        cout<< "p for print\n";
        cout<< "q for quit\n\n";
        cin>>selection;


        if (selection == 'c') //create polynomial
        {
         //List aList;yNu
         cout<<"Provide polynomial number" << endl;
         cin>>polyNum;
         arrayL[polyNum].createNewList();
        }

        else if (selection == 'p')//print polynomial
        {
         cout<<"\nEnter polynomial to print" << endl;
         cin>>polyNum;
         arrayL[polyNum].print();

        }//end elsif

        else if (selection == 'd')//delete polynomial
        {

         cout<<"\nEnter polynomial to delete" << endl;
         cin>>polyNum;
         arrayL[polyNum].destroy();
         cout<<"\nPolynomial "<<polyNum<<" Deleted\n";

        }
        //end elsif.

        else if (selection == 't')//delete term
        {
         cout<<"\nEnter polynomial to modify" << endl;
         cin>>polyNum;
         cout<<"Enter term to delete "<<endl;
         cin>>index;
         arrayL[polyNum].remove(index);
         cout<<"\nPolynomial "<<polyNum<<" term "<<index<<" Deleted\n";

        }

        else if (selection == 'q')//quit app
          {return 0;}

        else if (selection != ('i'|'q'|'c'|'p'|'d'|'t'))//catchall for erroneous entries
        {
          cout<<"Invalid entry, try again\n";

        }
    } while( true );

        return 0;
}
