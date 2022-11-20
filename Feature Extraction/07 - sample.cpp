// #include<iostream>
// #include<utility>
// #include "Preprocessing.cpp"
// #include<vector>
// #include<sstream>
// #include<unordered_set>
// #include<algorithm>
// // #include "C:\Users\Prakhar Jadaun\Desktop\Study\5th sem\Project\Main\Final Analysis\Processing in CPP\OleanderStemmingLibrary-master\include\olestem\stemming\english_stem.h"
// #include<string>
// using namespace std;
// int main()
// {
//     // string a = "helllo there world";
//     // string b = "My name is prakhar";

//     // pair<string,string> val(a,b);

//     // Preprocessing obj;
//     // pair<vector<string>,vector<string>> t =  obj.tokenize(val);
//     // cout<<"String 1 : "<<endl;
//     // for(int i=0;i<t.first.size();i++)
//     // {
//     //     cout<<t.first[i]<<endl;
//     // }

//     // cout<<"String 2 : "<<endl;
//     // for(int i=0;i<t.second.size();i++)
//     // {
//     //     cout<<t.second[i]<<endl;
//     // }

//     // vector<string> s = {"es","coding", "coder", "codering"};
//     // for(int i=0;i<s.size();i++)
//     // {
//     //     if(i==2)
//     //     s.erase(s.begin()+i);
//     // }  

//     // for(int i=0;i<s.size();i++)
//     // {
//     //     cout<<s[i]<<endl;
//     // }  
//     // cout<<s.size()<<endl;
//     // stemming::english_stem<> StemEnglish;
//     // for(int i=0;i<s.size();i++)
//     // {
//     //     std::string temp = s[i];
//     //     std::wstring word(temp.begin(),temp.end());
//     //     std::wcout<<L"\n\nOriginal text : "<<word.c_str()<<endl;
//     //     StemEnglish(word);
//     //     std::wcout<<L"Stemmed text : "<<word.c_str()<<endl;
//     //     // cout<<word.c_str()<<endl;
//     //     string temp2(word.begin(),word.end());
//     //     cout<<temp2<<endl;
//     // }   

//     unordered_set<string> s1 = {"my","name","is","prakhar"};
//     unordered_set<string> s2 = {"his","name","is","Sanidhya"};

//     vector<string> s3;
//     vector<string>::iterator pend,p;
//     pend = set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),s3.begin());

//     for(p = s3.begin(); p !=pend;p++)
//     {
//         cout<<*p<<" ";
//     }
// }

// //     stringstream ss; 
   
// //    // a variable named str, that is of string data type
// //    string str = "97";
   
// //    // a variable named num, that is of int data type
// //    int num;
   
   
// //    //extract the string from the str variable (input the string in the stream)
// //    ss << str;
   
// //    // place the converted value to the int variable
// //    ss >> num;
   
// //    //print to the consloe
// //    cout << (char)num << endl; // prints the intiger value 7


// // static char scanChar(string str)
// // {
// //     stringstream ss;
// //     int num;

// //     ss<<str;
// //     ss>>num;

// //     return (char)num;
// // }

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
    ifstream in;
    in.open("unique words.txt");
    // vector<string> v = {"hello","here","prakhar"};
    string str;
    while(in>>str)
    {   
        cout<<str<<" ";
    }
    in.close();
}