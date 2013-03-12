/*************************************************************
Name: Hashing2 Main

Author: Oakley Hall
CSCI 235 - Stamos

Date: December 10, 2009

Purpose: Hashing2 implements three programs.  One using a bad hash
function, one using a good hash function and one is a spell checker
Please see README.txt for more details.
***************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Hash.h"
#include "ListP.h"
#include <cstddef>
#include <locale>
using namespace std;



/***********************
• Requirements for a hash function
   – Is easy and fast to compute
   – Places items evenly throughout the hash table
   – Involves the entire search key
   – Uses a prime base, if it uses modulo arithmetic

**********************************/
//


int main()
{
int functSelect = 0;
        //h.createTable();
while (functSelect != 4)
{
        cout<<"\nChoose a Hash Function!"<<endl;
        cout<<"(1) for Bad Hash Table"<<endl;
        cout<<"(2) for Good Hash Table"<<endl;
        cout<<"(3) for Spell Checker"<<endl;
        cout<<"(4) to Quit"<<endl;
        cin>>functSelect;

    switch (functSelect)
    {
        case 1 : /*****BAD HASH FUNCTION**********/
        {
        string line; //string for each word in 'words' file
        Hash h; //instance of Hash
        h.mostCollisions=0;
        h.totalCollisions=0;
        h.mostCollisionBucket=0;
        int wordCount=0;
        int sum = 0;//place holder for sum returned from hash funct

/**->->->*/ifstream myfile ("words.txt");//select document to input
            if (myfile.is_open())
              {while (! myfile.eof() )
                {getline (myfile,line);
                    if (line.size()>0)//eliminate words that are just /0
                    {//sum = h.Goodhashfunction(line);
                        sum = h.Badhashfunction(line);
                        wordCount++;//counting words for convenience
                        //cout<<line<<" Code: "<<sum<<endl;
                        h.populateTable (sum, line);//i
                    }//end if
                   //cout<<"Bad hash fucntion: "<<h.Badhashfunction(line);//outputs retuen value of Badhashfunction, which is sum of words ascii values, mod BUCKET_SIZE
                }//end while
                 myfile.close();
              }//end if
             else
              {cout << "Unable to open file";}

        cout<<"\n____________"<<endl<<"Word Count: "<<wordCount<<endl;
        //h.printTable();
        cout<<"Total Collisions: "<<h.totalCollisions<<endl;
        cout<<"Most Collisions: "<<h.mostCollisions<<" occurred in bucket ";
        cout<<h.mostCollisionBucket<<endl;
        break;
        }//end case 1









        case 2 :/*****GOOD HASH FUNCTION**********/
        {
            string line; //string for each word in 'words' file
            Hash h; //instance of Hash
            h.mostCollisions=0;
            h.totalCollisions=0;
            h.mostCollisionBucket=0;
            int wordCount=0;
            int sum = 0;//place holder for sum returned from hash funct
           cout<<"\n\n\nThe 'Good' Hash Function uses the following algorithm: \n";
           cout<<"KEY += (((int)word[i]) * 32^i%5))% BUCKET_SIZE\nor the sum of the ASCII";
           cout<<"values of each letter of the word, \nmultiplied by 32 to the power ";
           cout<<"of the letter's position in the word.  \nAll modulus the number of buckets."<<endl;


/**->->->*/ifstream myfile ("words.txt");/**select document to input<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-*/
            if (myfile.is_open())
              {while (! myfile.eof() )
                {getline (myfile,line);
                    if (line.size()>0)//eliminate words that are just /0
                    {sum = h.Goodhashfunction(line);
                      //  sum = h.Badhashfunction(line);
                        wordCount++;//counting words for convenience
                        //cout<<line<<" Code: "<<sum<<endl;
                        h.populateTable (sum, line);//i
                    }//end if
                   //cout<<"Bad hash fucntion: "<<h.Badhashfunction(line);//outputs retuen value of Badhashfunction, which is sum of words ascii values, mod BUCKET_SIZE
                }//end while
                 myfile.close();
              }//end if
             else
              {cout << "Unable to open file";}

        cout<<"\n____________"<<endl<<"Word Count: "<<wordCount<<endl;
        //h.printTable();
        cout<<"Total Collisions: "<<h.totalCollisions<<endl;
        cout<<"Most Collisions: "<<h.mostCollisions<<" occurred in bucket ";
        cout<<h.mostCollisionBucket<<endl;

        break;
        }//end case 2

        case 4 :
        {
        return 0;
        break;
        }//end case 3















        case 3 :/**********SPELLCHECKER***************/
        {
            string line; //string for each word in 'words' file
            Hash h; //instance of Hash
            h.mostCollisions=0;
            h.totalCollisions=0;
            h.mostCollisionBucket=0;
            int wordCount=0;
            int sum = 0;//place holder for sum returned from hash funct
/**-<-*/ifstream myfile ("words.txt");/**Load Dictionary into spell checker TestDict<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-*/
            if (myfile.is_open())
              {while (! myfile.eof() )
                {getline (myfile,line);

                    /**convert input to lowercase*/
                    locale loc;
                    for (size_t i=0; i<line.length(); ++i)
                    line[i]=tolower(line[i],loc);

                    if (line.size()>0)//eliminate words that are just /0
                    {sum = h.Goodhashfunction(line);
                      //  sum = h.Badhashfunction(line);
                        wordCount++;//counting words for convenience
                        //cout<<line<<" Code: "<<sum<<endl;
                        h.populateTable (sum, line);//i
                    }//end if
                   //cout<<"Bad hash fucntion: "<<h.Badhashfunction(line);//outputs retuen value of Badhashfunction, which is sum of words ascii values, mod BUCKET_SIZE
                }//end while
                 myfile.close();
              }//end if
             else
              {cout << "Unable to open file";}
   /**************Input Text****************************/
            ifstream myfile2 ("infile.txt");/**select document to be checked TestIn.txt<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-*/
            if (myfile2.is_open())
              {while (! myfile2.eof() )
                {getline (myfile2,line);

                    /**convert input to lowercase*/
                    locale loc;
                    for (size_t i=0; i<line.length(); ++i)
                    line[i]=tolower(line[i],loc);
                    //cout<<line<<" text code "<<h.Goodhashfunction(line)<<endl;

                    /**tokenize string*/
                    int SIZE = line.length()+1;
                    char str[SIZE];

                    for (unsigned int i=0; i<line.length()+1; ++i)
                    str[i]=line[i];

                    char * pch;
                    pch = strtok (str," ,.-;:!\r");


                   while (pch)
                    {
                    string temp = pch;
                    h.spellCheck(temp);//insert tokens into sspellchecker
                    pch = strtok (NULL, " ,.-;:!\r");
                    //cout<<pch<<" text code "<<h.Goodhashfunction(pch)<<endl;

                    }//end while

                }//end while

                 myfile2.close();
              }//end if
             else
              {cout << "Unable to open file";}
        break;
        }//end case 4

    }//end switch



}//end while

return 0;

}

