/*************************************************************
Name: Hashing2 Hash.cpp

Author: Oakley Hall
CSCI 235 - Stamos

Date: December 10, 2009

Purpose: Hashning2 implements three programs.  One using a bad hash
function, one using a good hash function and one is a spell checker
Please see README.txt for more details.
***************************************************************/
#include <cstddef>     // for NULL
#include <new>         // for bad_alloc
#include "Hash.h"   // header file
#include <string>
#include <math.h>
#include <algorithm>

void Hash::printTable()
{
    std::cout<<"Table Contents "<<endl;
    for (int i = 0;i<BUCKET_SIZE;++i)
    {
       if(hashTable[i].head!=NULL)
    std::cout<<"Table Contents "<<endl;
    for (int i = 0;i<BUCKET_SIZE;++i)
    {
       {
            //cout<<"Bucket "<<i<<": ";
            hashTable[i].print();
       }//end if
    }//end for
}//end print table

int Hash::Badhashfunction(string word)
{
       int sum = 0;
       int len = word.length();
       for (int i=0; i<len; i++)
         sum += (int)word[i];
       return sum % BUCKET_SIZE;   // B is Table Size - number of Buckets
}//end Badhashfunct

int Hash::Goodhashfunction(string word)
{
       int sum = 0;
       int len = word.length();
       for (int i=0; i<len; i++)
       {
         sum += (((int)word[i]) * pow(32,i%5));  //(32,i%5) gets 9196
         /*cout<<"\n\nletter: "<<word[i]<<endl;//
         cout<<"value:  "<<(int)word[i]<<endl;
         cout<<"32^"<<i<<" = "<<pow(32,i%4)<<endl;
         cout<<"total:  "<<sum<<endl;*/
       }

       return sum % BUCKET_SIZE;   // B is Table Size - number of Buckets
}//end Badhashfunct

void Hash::populateTable(int sum, string word)//inserts word at array location specified by hash function
{

        if (hashTable[sum].head == NULL)
        {
        hashTable[sum].createNewList(word);
        }//end if

        else
        {
            hashTable[sum].insert(hashTable[sum].size+1,word);
            totalCollisions++;//increment collisions
            if (hashTable[sum].size > mostCollisions)
            {
                mostCollisions = hashTable[sum].size-1;
                mostCollisionBucket = sum;
            }

        }//end else

}//popTable


void Hash::spellCheck(string text)
{
    if (hashTable[Goodhashfunction(text)].compare(text) == false)
    {
            cout<<"\n"<<text<<" not found in dictionary."<<endl;
            suggest(text);
            ///return false;
    }

}//end spell check

bool Hash::quickCheck(string target)
{
    bool T = false;
    int x = Goodhashfunction(target);


    if (hashTable[x].compare(target) == false)
    {
        //cout<<"Quickcheck false: "<<target<<endl;
        //cout<<"compared to "<<hashTable[x].head->word<<endl;
        T = false;
    }
    else if (hashTable[x].compare(target) == true)
    {
    //cout<<"Quickcheck true: "<<target<<endl;
    //cout<<"compared to "<<hashTable[Goodhashfunction(target)].head->word<<endl;
    T = true;
    }


    return T;
    //cout<<text<<" ok.\n"<<endl;
}//end spell check

void Hash::suggest(string text)
{
    string swap = text;
    unsigned int i = 0;




    for (i = 0; i<text.length()-1; i++)
        {

            swap[i]=text[i+1];
            swap[i+1]=text[i];
            //cout<<"SWAP "<<swap<<endl;
            if (quickCheck(swap)==true)
            cout<<"Did you mean "<<swap<<"?"<<endl;
            swap = text;
        }//end inner for

    string bword = text;

                   string ing = "ing";
                   string ed = "ed";
                   string e = "e";

                    for (unsigned int i=3;i<text.length();i++)
                        {
                        bword=bword.substr(0, i)+ing;
                        if (quickCheck(bword)==true)
                        cout<<"Did you mean "<<bword<<"?"<<endl;
                        string bword = text;
                        }

                    for (unsigned int i=3;i<text.length();i++)
                        {
                        bword=bword.substr(0, i)+ed;
                        if (quickCheck(bword)==true)
                        cout<<"Did you mean "<<bword<<"?"<<endl;
                        string bword = text;
                        }

                 for (unsigned int j=0;j<text.length();j++)//
                 {
                    for (unsigned int i=97;i<123;i++)
                        {
                            string temp=text.substr(j,text.length());
                            //cout<<"TEMP: "<<temp<<endl;
                            bword=bword.substr(0,j);
                            char x = i;
                           // cout<<"I "<<x<<endl;
                            //cout<<"BWORD "<<bword<<endl;

                            bword.append(1,x);
                            bword=bword+temp;
                            if (quickCheck(bword)==true)
                            cout<<"Did you mean "<<bword<<"?"<<endl;

                            bword = text;


                        }//end inner for

                 }//end outer for*/

                    for (unsigned int i=0;i<text.length();i++)//test substrings
                        {
                        bword=text.substr(0, i);
                        if (quickCheck(bword)==true)
                        cout<<"Did you mean "<<bword<<"?"<<endl;
                        string bword = text;
                        }



                    for (unsigned int i=97;i<123;i++)//append charachters to string
                        {
                        char x = i;
                        bword.append( 1, x );
                        if (quickCheck(bword)==true)
                        cout<<"Did you mean "<<bword<<"?"<<endl;
                        string bword = text;
                        }



}//end suggest
