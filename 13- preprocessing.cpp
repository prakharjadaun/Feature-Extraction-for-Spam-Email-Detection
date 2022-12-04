#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "12 - Mathimp.cpp"
#pragma once
std::vector<std::vector<float>> splitByClass(std::vector<std::vector<float>> &dataset, float data_class);
std::vector<std::vector<float>> vectorTrainSplit(const std::vector<std::vector<float>> &vect, float percent);
std::vector<std::vector<float>> vectorTestSplit(std::vector<std::vector<float>> &vect, float percent);
float vectMatchScore(const std::vector<float> &labels, const std::vector<float> &predictions);

std::vector<std::vector<float>> splitByClass(std::vector<std::vector<float>> &dataset, float data_class)
{
   std::vector<std::vector<float>> temp_out;
   std::vector<std::vector<float>> out_Vector;
   std::vector<float> temp;
   int counter = 0;
   for (int i = 0; i < dataset[0].size(); i++)
   {

      if (dataset[dataset.size()-1][i] == (int)data_class)
      {
         for (int j = 0; j < dataset.size(); j++)
         {
            temp.push_back(dataset[j][i]);
         }
         temp_out.push_back(temp);
         temp.clear();
      }
   }

   out_Vector = algMath::vect_Transpose(temp_out);

   return out_Vector;
}

std::vector<std::vector<float>> vectorTrainSplit(const std::vector<std::vector<float>> &vect, float percent)
{
   std::vector<std::vector<float>> temp_out;
   std::vector<std::vector<float>> input = vect;
   int size = vect[0].size() * percent / 100;
   // dealing with data as vectors is easier than separating features in vectors
   input = algMath::vect_Transpose(input);
   for (auto temp = input.begin(); temp != input.begin() + size; temp++)
   {
      temp_out.push_back(*temp);
   }
   return algMath::vect_Transpose(temp_out);
}

std::vector<std::vector<float>> vectorTestSplit(std::vector<std::vector<float>> &vect, float percent)
{
   std::vector<std::vector<float>> temp_out;
   std::vector<std::vector<float>> input = vect;
   int sindex = vect[0].size() * (100 - percent) / 100;

   // dealing with data as vectors is easier than separating features in vectors
   input = algMath::vect_Transpose(input);
   for (auto temp = input.begin() + sindex; temp != input.end(); temp++)
   {
      temp_out.push_back(*temp);
   }
   return algMath::vect_Transpose(temp_out);
}

float vectMatchScore(const std::vector<float> &labels, const std::vector<float> &predictions)
{
   float result = 0;
   int index = 0;
   std::for_each(labels.begin(), labels.end(), [&](float label)
                 { 
        if(label == predictions[index])
        {
            result++;
        }
        index++; });
   return float(100 * result / labels.size());
}