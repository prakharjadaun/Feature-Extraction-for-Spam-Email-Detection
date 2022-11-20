#include<iostream>
#include<vector>
#include<unordered_map>
#include "06 - FeatureExtraction.cpp"
#include<fstream>

int main()
{
    //opening the processed data.txt file  
    std::ifstream in;
    in.open("03 - Processed data.txt");
    int index=0;
    //definning the two string objects
    std::string temp,line;
    std::vector<std::string> row;

    //storing the processed data into vector<vector<string>>
    std::vector<std::vector<std::string>> processedData;

    while(std::getline(in,line))
    {
        std::cout<<index+1<<std::endl;
        index++;
        temp="";

        for(int i=0;i<line.size();i++)
        {
            if(line[i]=',')
            {
                temp = temp + line[i];
            }
            else
            {
                row.push_back(temp);
                temp="";
            }
        }
        processedData.push_back(row);
        row.clear();
    }

    // std::getline(in,line);
    // std::cout<<line<<std::endl;
    // temp="";
    // for(int i=0;i<line.size();i++)
    // {
    //     if(line[i]!=',')
    //     temp+= line[i];
    //     else
    //     {
    //         row.push_back(temp);
    //         temp="";
    //     }
    // }
    // for(auto z : row)
    // {
    //     std::cout<<z<<" ";
    // }
    // std::cout<<std::endl;

    //4196 rows has been read
    // std::cout<<processedData.size()<<std::endl;

    //creating an object of the FeatureExtraction class
    FeatureExtraction fe;
    //calling the
    fe.bagOfWords(processedData);

    in.close();

}