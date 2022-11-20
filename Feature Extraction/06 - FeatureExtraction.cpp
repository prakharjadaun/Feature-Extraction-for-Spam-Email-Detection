#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include "01 - Preprocessing.cpp"
#pragma once
class FeatureExtraction
{
    public :
        //declaration
        void bagOfWords(std::vector<std::vector<std::string>> processedData);
};

void FeatureExtraction::bagOfWords(std::vector<std::vector<std::string>> processedData)
{
    /*
    Basic steps to perform bag of words
    1. read the unique words (set)

    2. vector<vector<string>> 
    =>  [["hi","hello"],
         ["you","there","hello"]]

    map[word[i][j]]++;
    

    hi -> 1
    helllo -> 1

    index    hi      hello       you     there
    0         1       1           0       0
    1         0       1           1       1
    */

    //1. Reading the unique words from the unique words.text
    std::vector<std::string> uniquewords;
    std::ifstream in;
    in.open("unique words.txt");
    std::string str;

    while(in>>str)
    {
        uniquewords.push_back(str);
    }
    //should be 21768 rows
    std::cout<<"Unique words : "<<uniquewords.size()<<std::endl;

    //2. writing the columns in the output BagOfWords.csv file

}