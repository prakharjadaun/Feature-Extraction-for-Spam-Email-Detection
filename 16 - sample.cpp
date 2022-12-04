/*
//performing basic operation on stl containers
#include<iostream>
#include<utility>
#include "02 - Preprocessing.cpp"
#include<vector>
#include<sstream>
#include<unordered_set>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    // string a = "helllo there world";
    // string b = "My name is prakhar";

    // pair<string,string> val(a,b);

    // Preprocessing obj;
    // pair<vector<string>,vector<string>> t =  obj.tokenize(val);
    // cout<<"String 1 : "<<endl;
    // for(int i=0;i<t.first.size();i++)
    // {
    //     cout<<t.first[i]<<endl;
    // }

    // cout<<"String 2 : "<<endl;
    // for(int i=0;i<t.second.size();i++)
    // {
    //     cout<<t.second[i]<<endl;
    // }

    // vector<string> s = {"es","coding", "coder", "codering"};
    // for(int i=0;i<s.size();i++)
    // {
    //     if(i==2)
    //     s.erase(s.begin()+i);
    // }  

    // for(int i=0;i<s.size();i++)
    // {
    //     cout<<s[i]<<endl;
    // }  
    // cout<<s.size()<<endl;
    // stemming::english_stem<> StemEnglish;
    // for(int i=0;i<s.size();i++)
    // {
    //     std::string temp = s[i];
    //     std::wstring word(temp.begin(),temp.end());
    //     std::wcout<<L"\n\nOriginal text : "<<word.c_str()<<endl;
    //     StemEnglish(word);
    //     std::wcout<<L"Stemmed text : "<<word.c_str()<<endl;
    //     // cout<<word.c_str()<<endl;
    //     string temp2(word.begin(),word.end());
    //     cout<<temp2<<endl;
    // }   

    unordered_set<string> s1 = {"my","name","is","prakhar"};
    unordered_set<string> s2 = {"his","name","is","Sanidhya"};

    vector<string> s3;
    vector<string>::iterator pend,p;
    pend = set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),s3.begin());

    for(p = s3.begin(); p !=pend;p++)
    {
        cout<<*p<<" ";
    }
}
*/

/*
//creating a sample bag of words code
#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    ofstream out;
    out.open("sample bag.txt");
    string str;

    vector<string> uniq = {"prakrati","sanidhya","prakhar","hello","here","you"};

    for(int i=0;i<uniq.size();i++)
    {
        out<<uniq[i]<<",";
    }
    out<<endl;

    vector<string> v = {"hello","here","prakhar","here","you"};

    // vector<vector<string>> w;
    // w.push_back(v);
    // for(int i=0;i<w.size();i++)
    // {
    //     for(int j=0;j<w[i].size();j++)
    //     {
    //         cout<<w[i][j]<<" ";
    //     }
    // }
    cout<<endl;
    unordered_map<string,int> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }

    for(int k=0;k<uniq.size();k++)
    {
        if(m.find(uniq[k])==m.end())
        {
            out<<0<<",";
        }
        else
        {
            out<<m[uniq[k]]<<",";
        }
    }  
}
*/

/*
//how to use boost library

#include<boost/array.hpp>
#include<iostream>
using namespace std;

int main()
{
    boost::array<int,10> arr = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "*"<< "\n";
    } 
}
*/

/*
//how to use the eigen library
#include <iostream>
#include <Eigen/Dense>
 
int main()
{
  Eigen::Matrix2d a;
  a << 1, 2,
       3, 4;
  Eigen::Vector3d v(1,2,3);
  std::cout << "a * 2.5 =\n" << a * 2.5 << std::endl;
  std::cout << "0.1 * v =\n" << 0.1 * v << std::endl;
  std::cout << "Doing v *= 2;" << std::endl;
  v *= 2;
  std::cout << "Now v =\n" << v << std::endl;
}
*/

// 
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
    //opening the processed data.txt file  
    std::ifstream in;
    in.open("train.csv");

    vector<vector<float>> train;
    vector<float> row;
    int index=0;
    string temp,line;
    float temp2;

    while(std::getline(in,line))
    {
        std::cout<<index+1<<"\r";
        std::cout.flush();
        index++;
        temp="";

        for(int i=0;i<line.size();i++)
        {
            if(line[i]!=',')
            {
                temp = temp + line[i];
            }
            else
            {
                temp2 = std::stof(temp);
                row.push_back(temp2);
                temp="";
            }
        }
        train.push_back(row);
        row.clear();
    }


    cout<<train.size()<<endl;
    cout<<train[0].size()<<endl;

}