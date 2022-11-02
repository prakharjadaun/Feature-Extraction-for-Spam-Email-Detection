#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<fstream>
#include "Preprocessing.cpp"
#pragma once
class FeatureExtraction
{
    public :
        //declaration
        void BagOfWords(std::vector<std::string> totalWords);
};

void FeatureExtraction::BagOfWords(std::vector<std::string> totalWords)
{
    //definning an object of class Preprocessing
    Preprocessing obj;
    //definning a pair having both the values as string
    std::pair<std::string,std::string> val;
    //definning a temporary variable
    std::string temp;

    std::pair<std::vector<std::string>,std::vector<std::string>> tokenised,removedStopWords;

    std::ifstream in;
    in.open("Final Dataset.csv");
    std::string line = "";
    getline(in,line);

    //definning the pair named stemmedWords 
    std::vector<std::string> stemmedwords;
    std::vector<std::string>::iterator it;
    std::map<std::string,int> rowWords;
    std::ofstream outBagOfWords;
    outBagOfWords.open("C:\\Users\\Prakhar Jadaun\\Desktop\\Study\5th sem\\Project\\Main\\Final Analysis\\Feature Extraction\\output\\BagOfWords.csv");

    for(it = totalWords.begin();it!=totalWords.end();it++)
    {
        outBagOfWords<<*it;
        if(++it!=totalWords.end())
        outBagOfWords<<",";
    }
    outBagOfWords<<std::endl;

    // line = "";
    // int i=0;
    // while(getline(in,line))
    // {
    //     // getline(in,line);
    //     std::stringstream inStr(line);
    //     //getting the subject and storing it into the first variable of pair val
    //     getline(inStr,val.first,',');
    //     //getting the message and storing it into the second variable of the pair val
    //     getline(inStr,val.second,',');
    //     //getting the label
    //     getline(inStr, temp,',');
    //     //converting it into integer from string type
    //     // label = atoi(temp.c_str());

    //     //removing the special characters from the dataset and storing it into the ROSC.csv
    //     val = obj.removeSpecialChar(val);
    //     // outROSC<<val.first<<","<<val.second<<","<<label<<std::endl;

    //     //converting all the uppercase alphabet to lowercase
    //     val = obj.lowercaseConversion(val);
    //     // outLower<<val.first<<","<<val.second<<","<<label<<std::endl;

    //     //calling the tokenization function of the preprocessing class 
    //     tokenised = obj.tokenize(val);

    //     //removing the stop words
    //     removedStopWords = obj.removalOfStopWords(tokenised);

    //     //performing stemming
    //     stemmedwords = obj.stemWords(removedStopWords);

    //     for(it = stemmedwords.begin();it!=stemmedwords.end();it++)
    //     {
    //         rowWords[*it]++;
    //     }
        
    // }

}