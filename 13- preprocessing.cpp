#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include "12 - Mathimp.cpp"
#pragma once
extern std::vector<std::vector<float>> Read_Iris_Dataset(void);
std::vector<std::vector<float>> split_by_class( std::vector<std::vector<float>> &dataset ,float data_class );
std::vector<std::vector<float>> vector_Train_Split(const std::vector<std::vector<float>> &vect , float percent);
std::vector<std::vector<float>> vector_Test_Split(std::vector<std::vector<float>> &vect , float percent);
float Vect_match_Score (const std::vector<float> &labels, const std::vector<float> &predictions );

// std::vector<std::vector<float>> Read_Iris_Dataset(void)
// {
//   std::ifstream myfile("iris.data");
//   std::string line;
//   std::vector<std::vector<float>> Iris_Dataset;
//   std::vector<float> temp_sepal_len;
//   std::vector<float> temp_sepal_wid;
//   std::vector<float> temp_petal_len;
//   std::vector<float> temp_petal_wid;
//   std::vector<float> temp_iris_class;

//   float sepal_len_f,sepal_wid_f,petal_len_f,petal_wid_f;
//   float iris_class_f;

//   std::string temp_string;
//    int count =0;
//    if (myfile.is_open())
//   {
//      std::cout<< "file opened successfully"<<std::endl;
//       while (std::getline(myfile, line)) {
//          std::replace(line.begin(), line.end(), '-', '_');
//          std::replace(line.begin(), line.end(), ',', ' ');
         
//          std::istringstream iss(line);
//          count++;
         
//          iss >> sepal_len_f>>sepal_wid_f >> petal_len_f >>petal_wid_f >> temp_string;
//          temp_sepal_len.push_back(sepal_len_f);
//          temp_sepal_wid.push_back(sepal_wid_f);
//          temp_petal_len.push_back(petal_len_f);
//          temp_petal_wid.push_back(petal_wid_f);
//          if(temp_string.compare("Iris_setosa") == 0)
//          {
//             iris_class_f = Iris_setosa;
//          }
//          else if (temp_string.compare("Iris_versicolor") ==0)
//          {
//             iris_class_f = Iris_versicolor;
//          }
//          else if (temp_string.compare("Iris_virginica") == 0)
//          {
//             iris_class_f = Iris_virginica;
//          }else 
//          {
//             iris_class_f = Iris_unkown;
//          }
//          temp_iris_class.push_back(iris_class_f);
//       }
//       Iris_Dataset.push_back(temp_sepal_len);
//       Iris_Dataset.push_back(temp_sepal_wid);
//       Iris_Dataset.push_back(temp_petal_len);
//       Iris_Dataset.push_back(temp_petal_wid);
//       Iris_Dataset.push_back(temp_iris_class);  

//   }
//   else 
//   {
//      std::cout << "Unable to open file"<<std::endl;;
//   }
//   return Iris_Dataset;
// }

std::vector<std::vector<float>> split_by_class( std::vector<std::vector<float>>& dataset ,float data_class )
{
   std::vector< std::vector<float> > temp_out;
   std::vector< std::vector<float> > out_Vector;
   std::vector<float> temp;
   int counter = 0;
   std::for_each( dataset[4].begin(), dataset[4].end(), [&](float & item_class)
   { 
      if(item_class == data_class )
      {
         std::vector<float> temp;
         temp.push_back(dataset[0][counter]);
         temp.push_back(dataset[1][counter]);
         temp.push_back(dataset[2][counter]);
         temp.push_back(dataset[3][counter]);
         temp.push_back(dataset[4][counter]);
         temp_out.push_back(temp);
      }      
      counter++;
   });
   out_Vector = alg_math::vect_Transpose(temp_out);
   return out_Vector;
}

std::vector<std::vector<float>> vector_Train_Split(const std::vector<std::vector<float>> &vect , float percent)
{
   std::vector< std::vector<float>> temp_out;
   std::vector<std::vector<float>> input = vect;
   int size = vect[0].size() * percent/100;
   // dealing with data as vectors is easier than separating features in vectors
   input = alg_math::vect_Transpose(input);
   for (auto temp =input.begin() ; temp != input.begin()+ size; temp++ )
   {
      temp_out.push_back(*temp);
   }
   return alg_math::vect_Transpose(temp_out);
}


std::vector<std::vector<float>> vector_Test_Split( std::vector<std::vector<float>> &vect , float percent)
{
   std::vector< std::vector<float>> temp_out;
   std::vector<std::vector<float>> input = vect;
   int sindex = vect[0].size() * (100 - percent)/100;
   
   // dealing with data as vectors is easier than separating features in vectors
   input = alg_math::vect_Transpose(input);
   for (auto temp =input.begin()+ sindex ; temp != input.end(); temp++ )
   {
      temp_out.push_back(*temp);
   }
   return alg_math::vect_Transpose(temp_out);
}

float Vect_match_Score (const std::vector<float> &labels, const std::vector<float> &predictions )
{
    float result=0; 
    int index=0;
    std::for_each(labels.begin(), labels.end(), [&](float label)
    { 
        if(label == predictions[index])
        {
            result++;
        }
        index++; 
    });
    return float(100*result/labels.size());
}