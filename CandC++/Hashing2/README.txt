Name: Hashing2 
Author: Oakley Hall
CSCI 235 - Stamos
Date: December 10, 2009


The Hashing2 program implements 3 seperate programs any of which can be selected 
from the menu at the start of the program.  Creates a hash table from the words.txt
file, indexed by hash values.  These hash tables uses separate chaining to deal with
collisions.

1. Implements the bas hash function given to us with the assignment.  This program
prints the Word Count, Total Collisions and the bucket in which the most collisions
occurred.

2. Same as 1 only this time using a good hash function designed to minimize the 
number of collisions.  This program also prints the algorithm used for this improved
hash function.

3. A spell checker.  This program creates a hash table using the good hash function
and then compares words from infile.txt to the words stored in the hash table.  The 
program prints the words not found in the hash table and on tha assumption that they
are misspelled, offered suggested alternatives that ARE in the hash table.
