#include<iostream>
#include<vector>
#include<fstream>
#include "14 - NaiveBayes.cpp"
#include "12 - Mathimp.cpp"
#include "13- preprocessing.cpp"
#include<ctime>
using namespace std;

int main()
{
    std::srand (unsigned(std::time(0)));
    std::ifstream in;
    in.open("Tf Idf for cpp.csv");
    NaiveBayes naive = NaiveBayes();
    vector<vector<float>> dataset;
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

        for(std::size_t i=0;i<line.size();i++)
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
        dataset.push_back(row);
        row.clear();
    }

    cout<<"dataset size"<<dataset.size()<<","<<dataset[0].size()<<endl;

    std::srand (unsigned(std::time(0)));
    dataset = algMath::vect_Transpose(dataset); 
    std::random_shuffle (dataset.begin(),dataset.end());
    dataset = algMath::vect_Transpose(dataset); 
    float percentage =70;
    std::vector<std::vector<float>> training_data  = vectorTrainSplit(dataset , percentage);
    std::vector<std::vector<float>> testing_data  = vectorTestSplit(dataset , 100 - percentage);
    
    std::cout<< "testing Data Size is ( " << testing_data.size() << " , "  <<testing_data[0].size()<<" )" <<std::endl;
    
    std::cout<< "training Data Size is ( " << training_data.size() << " , "  <<training_data[0].size()<<" )" <<std::endl;
    naive.fit(training_data);

    std::vector<float> predicitions;
    testing_data = algMath::vect_Transpose(testing_data); 
    for(std::size_t i=0; i<testing_data.size(); i++ )
    {
        cout<<"Predicting..."<<"\r";
        cout.flush();
        auto index = naive.predict(testing_data[i]);
        predicitions.push_back(index);
    }
    testing_data = algMath::vect_Transpose(testing_data); 
    std::cout<<"score is :" << vectMatchScore(testing_data[4],predicitions)<<std::endl;
    return 0;
}
