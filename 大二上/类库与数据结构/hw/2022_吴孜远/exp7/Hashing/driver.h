#include <fstream>     // declares << and >> for files
#include <string>      // declares the string class
#include "hash_map.h"    // declares and defined the hash_map class

class hash_func
{
public:

    unsigned long operator() (const string key); //hash function from string to ussinged long
                                                //to be implemented

}; // class hash_func


class HashMapDriver
{
protected:

    fstream inFile; //for processing the dictionary file

    hash_map <string, string, hash_func> dict; //the dictionary hash map
                                                //key:string, value:string
                                                //hash_func:string to unsigned long 

public:

    // Postcondition: The input file has been created
    //                with their names read in from the keyboard.
    void setUpFiles();

    // Postcondition: All of the words in the dictionary file have been read in and processed.
    void readAndProcess();

    void testDictionary(); //test the dictionary

}; // class HashMapDriver
