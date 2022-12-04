#include<iostream>
#include<cctype>            //for isalpha() function
#include<vector>            //for vector class
#include<sstream>           //for stringstream class
#include<unordered_set>     //for unordered_set 
#include "C:\Users\Prakhar Jadaun\Desktop\Study\5th sem\Project\Main\Final Analysis\Feature Extraction\OleanderStemmingLibrary-master\include\olestem\stemming\english_stem.h"
//class preprocessing to perform the preprocessing steps
#pragma once
class Preprocessing
{
    private:
        std::string sub;
        std::string mes;

    public:
        //function to check if the passed character is special or not
        bool checkSpecialChar(char ch);

        //for removing the special characters
        std::pair<std::string,std::string> removeSpecialChar(std::pair<std::string,std::string> val);

        //lowering case
        std::pair<std::string,std::string> lowercaseConversion(std::pair<std::string,std::string> val);

        //tokenization
        std::pair<std::vector<std::string>,std::vector<std::string>> tokenize(std::pair<std::string,std::string> val);

        //function to check whether the passed string is a stop word or not
        bool checkStopWords(std::string s);

        //removal of stop words
        std::pair<std::vector<std::string>,std::vector<std::string>> removalOfStopWords(std::pair<std::vector<std::string>,std::vector<std::string>> tokens);

        //removal of hyperlinks 

        //stemming
        std::vector<std::string> stemWords(std::pair<std::vector<std::string>,std::vector<std::string>> val);

        //lemmitization
};

//function to check if the character passed to the function is a special character or not
//!"#$%&'()*+,-./:;< = >?@[\]^_`{|}~
//removing the numbers from our dataset
bool Preprocessing::checkSpecialChar(char ch)
{
    //switch case
    switch(ch)
    {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '!':
        case '\"':
        case '#':
        case '$':
        case '%':
        case '&':
        case '\'':
        case '(':
        case ')':
        case '*':
        case '+':
        case ',':
        case '-':
        case '.':
        case '/':
        case ':':
        case ';':
        case '<':
        case '=':
        case '>':
        case '?':
        case '@':
        case '[':
        case '\\':
        case ']':
        case '^':
        case '_':
        case '`':
        case '{':
        case '|':
        case '}':
        case '~':
            return true;
        default :
            return false;
    }
}

//function to remove special characters from the subject and message column
std::pair<std::string,std::string> Preprocessing::removeSpecialChar(std::pair<std::string,std::string> val)
{
    //assigning the first and second values to sub and mes 
    sub = val.first;
    mes = val.second;
    
    //iterating all the characters of the subject 
    for(int i=0;i<sub.size();i++)
    {
        //checking if the character is special or not
        if(checkSpecialChar(sub[i]))
        {
            //assigning ' ' at the indices of special character
            sub[i] = ' ';
        }
    }
    //iterating all the characters of the message 
    for(int i=0;i<mes.size();i++)
    {
        //checking if the characters is special or not
        if(checkSpecialChar(mes[i]))
        {
            //assigning ' ' at the indices of special character
            mes[i] = ' ';
        }
    }
    //assigning the updated subject and message
    val.first = sub;
    val.second = mes;

    //returning the pair val 
    return val;
}

//function to convert all characters into lowercase
std::pair<std::string,std::string> Preprocessing::lowercaseConversion(std::pair<std::string,std::string> val)
{
    sub = val.first;
    mes = val.second;

    //iterating all the characters of the subject 
    for(int i=0;i<sub.size();i++)
    {
        //checking if the character is alphabet or not
        if(isalpha(sub[i]))
        {
            //checking if the alphabet is in uppercase or not
            if(isupper(sub[i]))
            {
                //converting the alphabet to lowercase
                sub[i] = tolower(sub[i]);
            }
        }
    }

    //iterating all the characters of the message 
    for(int i=0;i<mes.size();i++)
    {
        //checking if the character is alphabet or not
        if(isalpha(mes[i]))
        {
            //checking if the alphabet is in uppercase or not
            if(isupper(mes[i]))
            {
                //converting the alphabet to lowercase
                mes[i] = tolower(mes[i]);
            }
        }
    }
    //assigning the updated subject and message
    val.first = sub;
    val.second = mes;

    //returning the pair val 
    return val;
}

//function to tokenize the subject and the message of the dataset
std::pair<std::vector<std::string>,std::vector<std::string>> Preprocessing::tokenize(std::pair<std::string,std::string> val)
{
    std::vector<std::string> s1,s2;
    std::stringstream c1(val.first),c2(val.second);

    std::string temp;
    //tokenizing the subject of the mail and storing it into the vector s1
    while(getline(c1,temp,' '))
    {
        s1.push_back(temp);
    }

    //tokenizing the message of the mail and storing it into the vector s2
    while(getline(c2,temp,' '))
    {
        s2.push_back(temp);
    }
    //declaring a pair containing tokenized subject and message as vectors of string
    std::pair<std::vector<std::string>,std::vector<std::string>> val2(s1,s2);
    return val2;
}


/* 
i, me, my, myself, we, our, ours, ourselves, you, you're, you've, you'll, you'd, your, yours, yourself, yourselves, he, him, his, himself, she, she's, her, hers, herself, it, it's, its, itself, they, them, their, theirs, themselves, what, which, who, whom, this, that, that'll, these, those, am, is, are, was, were, be, been, being, have, has, had, having, do, does, did, doing, a, an, the, and, but, if, or, because, as, until, while, of, at, by, for, with, about, against, between, into, through, during, before, after, above, below, to, from, up, down, in, out, on, off, over, under, again, further, then, once, here, there, when, where, why, how, all, any, both, each, few, more, most, other, some, such, no, nor, not, only, own, same, so, than, too, very, s, t, can, will, just, don, don't, should, should've, now, d, ll, m, o, re, ve, y, ain, aren, aren't, couldn, couldn't, didn, didn't, doesn, doesn't, hadn, hadn't, hasn, hasn't, haven, haven't, isn, isn't, ma, mightn, mightn't, mustn, mustn't, needn, needn't, shan, shan't, shouldn, shouldn't, wasn, wasn't, weren, weren't, won, won't, wouldn, wouldn't
*/
//function to return whether the passed string is a stop word or not
bool Preprocessing::checkStopWords(std::string s)
{
    std::unordered_set<std::string> stopwords = {"i","me","my","myself","we","our","ours","ourselves","you","you\'re","you\'ve","you\'ll","you\'d","your","yours","yourself","yourselves","he","him","his","himself","she","she\'s","her","hers","herself","it","it\'s","its","itself","they","them","their","theirs","themselves","what","which","who","whom","this","that","that\'ll","these","those","am","is","are","was","were","be","been","being","have","has","had","having","do","does","did","doing","a","an","the","and","but","if","or","because","as","until","while","of","at","by","for","with","about","against","between","into","through","during","before","after","above","below","to","from","up","down","in","out","on","off","over","under","again","further","then","once","here","there","when","where","why","how","all","any","both","each","few","more","most","other","some","such","no","nor","not","only","own","same","so","than","too","very","s","t","can","will","just","don","don\'t","should","should\'ve","now","d","ll","m","o","re","ve","y","ain","aren","aren\'t","couldn","couldn\'t","didn","didn\'t","doesn","doesn\'t","hadn","hadn\'t","hasn","hasn\'t","haven","haven\'t","isn","isn\'t","ma","mightn","mightn\'t","mustn","mustn\'t","needn","needn\'t","shan","shan\'t","shouldn","shouldn\'t","wasn","wasn\'t","weren","weren\'t","won","won\'t","wouldn","wouldn\'t"};

    if(stopwords.find(s)!=stopwords.end())
        return true;
    
    return false;
}


//function to remove stop words from the dataset
std::pair<std::vector<std::string>,std::vector<std::string>> Preprocessing::removalOfStopWords(std::pair<std::vector<std::string>,std::vector<std::string>> tokens)
{
    std::vector<std::string> s,m;
    s = tokens.first;
    m = tokens.second;

    for(int i=0;i<s.size();i++)
    {
        if(checkStopWords(s[i]))
        {
            s.erase(s.begin()+i);
        }
    }

    for(int i=0;i<m.size();i++)
    {
        if(checkStopWords(m[i]))
        {
            m.erase(m.begin()+i);
        }
    }   

    tokens.first = s;
    tokens.second = m;

    return tokens;
}

//function to stem words of the subject and message section 


std::vector<std::string> Preprocessing::stemWords(std::pair<std::vector<std::string>,std::vector<std::string>> val)
{
    std::vector<std::string> s,m;
    s = val.first;
    m = val.second;
    //definning two unordered_set named set1 and set2 of string type
    std::unordered_set<std::string> tempSet;
    stemming::english_stem<> StemEnglish;
    for(int i=0;i<s.size();i++)
    {
        //storing the string in a temporary variable
        std::string temp = s[i];
        //converting string to wstring type
        std::wstring word(temp.begin(),temp.end());
        StemEnglish(word);
        std::string temp2(word.begin(),word.end());
        //inserting the stemmed string into the set
        tempSet.insert(temp2);
    }
    for(int i=0;i<m.size();i++)
    {
        //storing the string in a temporary variable
        std::string temp = m[i];
        //converting string to wstring type
        std::wstring word(temp.begin(),temp.end());
        StemEnglish(word);
        std::string temp2(word.begin(),word.end());
        //inserting the stemmed string into the set
        tempSet.insert(temp2);
    }
    std::vector<std::string> vStem;
    std::unordered_set<std::string>::iterator it;
    for(it = tempSet.begin();it!=tempSet.end();it++)
    {
        vStem.push_back(*it);
    }
    return vStem;
}

