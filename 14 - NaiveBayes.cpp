#include <vector>
#include "12 - Mathimp.cpp"
#include "13- preprocessing.cpp"
#include <algorithm>
#include <ctime>
using namespace std;
#pragma once
typedef struct class_summary 
{  
    std::vector<std::vector<float>> Mean_Stdev;
    float class_prob;

} class_summary; 

class_summary calculateClassSummary(std::vector<std::vector<float>> dataset, float class_label);
float prob_By_Summary(const std::vector<float> &test_data ,const class_summary &summary );

class NaiveBayes
{
    private:
    std::vector<class_summary> Summary;
    std::vector<float> unique_label;
    
    public:
    void fit(std::vector<std::vector<float>> dataset);
    int  predict(const  std::vector<float>& test_data);
};


void NaiveBayes::fit(std::vector<std::vector<float>> training_data )
{
    unique_label = training_data[training_data.size()-1];
    std::sort(unique_label.begin(),unique_label.end());
    unique_label.erase(std::unique(unique_label.begin(),unique_label.end()),unique_label.end());
    cout<<"Unique label  : "<<unique_label.size()<<endl;
    for (auto row = unique_label.begin(); row != unique_label.end(); row++)
    {
       Summary.push_back(calculateClassSummary(training_data, *row));
    }
    cout<<"Summary"<<endl;
}


int NaiveBayes::predict(const  std::vector<float>& test_data)
{
    std::vector<float> out;
    for (auto row = unique_label.begin(); row != unique_label.end(); row++)
    {
       out.push_back( prob_By_Summary(test_data ,Summary[*row] ));
    }
    int maxElementIndex = std::max_element(out.begin(),out.end()) - out.begin();
    return maxElementIndex;
}


class_summary calculateClassSummary (std::vector<std::vector<float>> dataset, float class_label )
{
    auto class_data = splitByClass(dataset,class_label);

    class_summary summary;
    std::vector<float> temp;
    cout<<"For label "<<class_label<<" : "<<class_data.size()<<","<<class_data[0].size()<<endl;
    for (auto row = class_data.begin(); row != class_data.end(); row++)
    {
        temp.clear();
        temp.push_back(algMath::Math_Mean(*row));
        temp.push_back(algMath::Math_Var(*row));
        summary.Mean_Stdev.push_back(temp);
    }
    summary.class_prob = float(class_data[0].size())/ dataset[0].size();
    return summary;
}

float prob_By_Summary(const std::vector<float> &test_data ,const class_summary &summary )
{
    int index =0;
    float prob = 1;
    for (auto row = summary.Mean_Stdev.begin(); row != summary.Mean_Stdev.end()-1; row++)
    {
        prob *= algMath::calc_prob(test_data[index],(*row)[0],(*row)[1]);
        index++;
    }
    /* multiplying by the class probability*/
    prob *= summary.class_prob;
    return prob;
}

