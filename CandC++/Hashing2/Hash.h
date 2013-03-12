/*************************************************************
Name: Hashing2 Hash.h
Author: Oakley Hall
CSCI 235 - Stamos

Date: December 10, 2009

Purpose: Hashing2 implements three programs.  One using a bad hash
function, one using a good hash function and one is a spell checker
Please see README.txt for more details.
***************************************************************/
#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <string>
#include <cstring>
#include "ListP.h"

const int BUCKET_SIZE =25147; //25147
using namespace std;

class Hash
{

    public:

    int Badhashfunction(string word);
    int Goodhashfunction(string word);
    void populateTable(int, string);//inserts word at array location specified by hash function
    void printTable();
    void spellCheck(string);
    bool quickCheck(string);
    void suggest (string);
    int totalCollisions;
    int mostCollisions;
    int mostCollisionBucket;
    private:
    List hashTable [BUCKET_SIZE];
    friend class List;
};
#endif
