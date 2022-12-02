#include<iostream>
#include "02 - Preprocessing.cpp"
#include<fstream>
#include<vector>
#include<sstream>       //for stringstream class
#include<map>
int main()
{
    //definning an object of class Preprocessing
    Preprocessing obj;
    //definning a pair having both the values as string
    std::pair<std::string,std::string> val;
    //definning a temporary variable
    std::string temp;
    //variable named label for storing the label
    int label;
    std::pair<std::vector<std::string>,std::vector<std::string>> tokenised,removedStopWords;

    std::ifstream in;
    in.open("Final Dataset.csv");
    std::string line = "";
    getline(in,line);

    //definning the pair named stemmedWords 
    std::vector<std::string> stemmedwords;

    std::unordered_set<std::string> tempTotalWords;
    std::vector<std::string> totalWords;
    //definning the map to append each of the row of the dataset into it
    std::map<int,std::vector<std::string>> row; 
    std::vector<std::string>::iterator it;

    std::ofstream outProcess;
    outProcess.open("03 - processed data.txt");

    line = "";
    int i=0;
    while(getline(in,line))
    {
        // getline(in,line);
        std::stringstream inStr(line);
        //getting the subject and storing it into the first variable of pair val
        getline(inStr,val.first,',');
        //getting the message and storing it into the second variable of the pair val
        getline(inStr,val.second,',');
        //getting the label
        getline(inStr, temp,',');
        //converting it into integer from string type
        // label = atoi(temp.c_str());

        //removing the special characters from the dataset and storing it into the ROSC.csv
        val = obj.removeSpecialChar(val);

        //converting all the uppercase alphabet to lowercase
        val = obj.lowercaseConversion(val);

        //calling the tokenization function of the preprocessing class 
        tokenised = obj.tokenize(val);

        //removing the stop words
        removedStopWords = obj.removalOfStopWords(tokenised);

        //performing stemming
        stemmedwords = obj.stemWords(removedStopWords);
        for(it = stemmedwords.begin();it!=stemmedwords.end();it++)
        {
            // std::cout<<*it<<" ";
            tempTotalWords.insert(*it);
        }
        // i++;
        // if(i==1)
        // break;
        std::cout<<i+1<<std::endl;
        i++;


        //to clear the contents of vector

        // for(int i=0;i<stemmedwords.size();i++)
        // {
        //     outProcess<<stemmedwords[i];
        //     if(i!=stemmedwords.size()-1)
        //     outProcess<<",";
        // }
        // outProcess<<std::endl;
        stemmedwords.clear();
        line="";
    }
    
    std::ofstream twords;
    twords.open("uniquewords.txt");
    std::unordered_set<std::string>::iterator its ;
    for(its = tempTotalWords.begin();its != tempTotalWords.end();its++)
    {
        // totalWords.push_back(*its);
        twords << *its <<" ";    
    }
    twords.close();

    return 0;
}