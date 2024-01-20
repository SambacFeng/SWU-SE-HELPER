#include<iostream>
#include "driver.h"    // declares hashmapDriver class
#include <math.h>
using namespace std;

unsigned long hash_func::operator() (const string key)
{
    //please implement this!
    long hash = 0;
    for (int i = key.length()-1; i >= 0; i--) {
        hash = hash + key[i] * pow(128, i);
    }
    return hash;
}

void HashMapDriver::setUpFiles()
{
    const string INFILE_PROMPT =
        "Please enter the path for the input file: ";

    const string IN_FAILURE =
        "*** Error opening input file: ";

    string inFileName;

    cout << INFILE_PROMPT;
    cin >> inFileName; //get input file path and name
    inFile.open(inFileName.c_str(), ios::in); //open input file

    while (inFile.fail())
    {
        cout << endl << IN_FAILURE << inFileName << endl;
        cout << endl << INFILE_PROMPT;
        cin >> inFileName;
        inFile.open(inFileName.c_str(), ios::in); //open input file
    } // if input file incorrect

    getline(cin, inFileName);//eat ENTER key
} // setUpFiles

void HashMapDriver::readAndProcess()
{
    string curr_line;

    while (getline(inFile, curr_line)) //repeatealy read a new line into curr_line
                                        //from input file until EOF
                                        //and meanwhile set up the dictionary
    {
        //please implement this processing!
        //每一行取空格之前的单词为key,后面的为value
        int i = 0;
        string key, value;
        while (1) {
            if (curr_line[i] == ' ') {
                key = curr_line.substr(0, i);
                value = curr_line.substr(i, curr_line.length());
                break;
            }
            i++;
        }
        //向哈希表中对应下标处存放键值对
        key_value_pair<const string, string> p(key, value);
        dict.insert(p);

    } // while
    
    inFile.close(); //close input file
} // readAndProcess

void HashMapDriver::testDictionary()
{
    system("chcp 65001"); //set the encoding of console to UTF-8 if necessary

    string word;
    cout << "load_factor: " << dict.getLoad_factor() << endl;
    cout << "Max Comparisons: " << dict.getMaxComparisons() << endl;
    cout << "Average Comparisons: " << dict.getAverageComparisons();

    cout << endl << "Please input a word; input QUIT to quit." << endl;
    getline(cin, word); //read a new word from user input

    while (word != "QUIT") {
        hash_map<string, string, hash_func>::iterator itr;
        itr = dict.find(word);
        cout << "\t" << (*itr).second ;

        cout << endl << "Please input a word; input QUIT to quit." << endl;
        getline(cin, word); //read a new word from user input
    }

    //please implement the testing!
        
}