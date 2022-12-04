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

    void createVocabList()
    {
        cout<<"Creating vocab list"<<endl;
        std::set<std::string> vocabListSet;
        for (std::vector<std::string> document : rawDataSet)
        {
            for (std::string word : document)
                vocabListSet.insert(word);
        }
        cout<<"Vocab size :"<<vocabListSet.size()<<endl;
        std::copy(vocabListSet.begin(), vocabListSet.end(), std::back_inserter(vocabList));
    }

    std::vector<double> bagOfWords2VecMN(std::vector<std::string> &inputSet)
    {
        std::vector<double> returnVec(vocabList.size(), 0);
        for (std::string word : inputSet)
        {
            size_t idx = std::find(vocabList.begin(), vocabList.end(), word) - vocabList.begin();
            if (idx == vocabList.size())
                cout << "word: " << word << "not found" << endl;
            else
                returnVec.at(idx) += 1;
        }
        return returnVec;
    }

    void vec2mat()
    {
        cout << "Converting text to vector..." << endl;
        int cnt=0;
        for (auto it = rawDataSet.begin(); it != rawDataSet.end(); it++)
        {
            cnt++;
            cout << cnt << "\r";
            std::cout.flush();
            dataMat.push_back(bagOfWords2VecMN(*it));
            numOfTerms.push_back(it->size());
            it->clear();
        }
        cout << endl;
        ncol = dataMat[0].size();
        nrow = dataMat.size();
        rawDataSet.clear(); // release memory
    }

     std::vector<double> vec_sum(const std::vector<double> &a,
                                const std::vector<double> &b)
    {
        assert(a.size() == b.size());
        std::vector<double> result;
        result.reserve(a.size());
        std::transform(a.begin(), a.end(), b.begin(),
                       std::back_inserter(result), std::plus<double>());
        return result;
    }

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

    
    void getMat()
    {
        cout << "Total " << rawDataSet.size() << " patents." << endl;
        cout << "Processing..." << endl;
        createVocabList();
        vec2mat();
        cout << "Calculating TF-IDF weight matrix..." << endl;
        std::vector<std::vector<double>> dataMat2(dataMat);
        std::vector<double> termCount;
        termCount.resize(ncol);

        for (unsigned int i = 0; i != nrow; i++)
        {
            for (unsigned int j = 0; j != ncol; j++)
            {
                if (dataMat2[i][j] > 1) // only keep 1 and 0
                    dataMat2[i][j] = 1;
            }
            termCount = vec_sum(termCount, dataMat2[i]); // no. of doc. each term appears
        }
        dataMat2.clear(); // release

        std::vector<double> row_vec;
        for (unsigned int i = 0; i != nrow; i++)
        {
            cout << "\r" << (i + 1);
            std::cout.flush();
            for (unsigned int j = 0; j != ncol; j++)
            {
                double tf = dataMat[i][j] / numOfTerms[i];
                double idf = log((double)nrow / (termCount[j]));
                row_vec.push_back(tf * idf); // TF-IDF equation
            }
            weightMat.push_back(row_vec);
            row_vec.clear();
        }
        nrow = weightMat.size();
        cout << endl;
    }

    void saveMat(std::string filename)
    {
        cout << "Saving weight matrix to " << filename << "..." << endl;
        std::ofstream outfile;
        outfile.open(filename, std::ios_base::app);
        for (auto it = weightMat.begin(); it != weightMat.end(); it++)
        {
            std::ostringstream ss;
            for (auto it2 = it->begin(); it2 != it->end(); it2++)
            {
                ss << *it2 << ",";
            }
            outfile << ss.str().substr(0, ss.str().size() - 1) << endl;
            ss.clear();
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


