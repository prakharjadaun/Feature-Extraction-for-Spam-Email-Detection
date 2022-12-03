#include<bits/stdc++.h>
#include<Eigen/Sparse>
using namespace std;
class tfIdf
{
   private:
    // std::vector<std::string> patentsList;             // all patents in order
    std::vector<std::vector<double>> dataMat;         // converted bag of words matrix
    unsigned int nrow;                                // matrix row number
    unsigned int ncol;                                // matrix column number
    std::vector<std::vector<double>> weightMat;       // tfidf weight matrix
    std::vector<std::vector<std::string>> rawDataSet; // raw data
    std::vector<std::string> vocabList;               // all terms
    // std::map<std::string, int> h_hot;                 // hot num
    std::vector<int> numOfTerms;                      // used in tf calculation
    // std::vector<std::string> stopWords;               // list of common words to ignore

public:
    unsigned int recAmount;
    unsigned int finishCount;

    void loadData()
    {
        cout << "Loading data..." << endl;
        ifstream in("Data for Tf Idf.csv");
        string tmp;
        std::vector<std::string> row;
        std::string line,temp;
        int index=0;
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
                    row.push_back(temp);
                    temp="";
                }
            }
            rawDataSet.push_back(row);
            row.clear();
        }
    }

};

int main()
{
    tfIdf patents;
    // patents.loadStopWords();
    patents.loadData();
    patents.recAmount = 4;
    patents.getMat();
    patents.saveMat("tfidf_matrix.txt");
    // patents.calSimi(0, 15);
}


