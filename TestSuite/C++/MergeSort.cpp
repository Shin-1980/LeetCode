#include <iostream>
#include <fstream>

class MergeSort{
public:
    long long numOfInversion;

    MergeSort():
        numOfInversion(0)
    {
        ;    
    }

    std::vector<int> sep(std::vector<int>& arr, long long l, long long r){
        if (l == r) {
            std::vector<int> res(1,arr[l]);
            return res;
        }

        long long m = (r + l) / 2;

        std::vector<int> al = sep(arr, l, m);
        std::vector<int> ar = sep(arr, m+1, r);

        std::vector<int> alr(r-l+1,0);

        //std::cout << l << "," << r << "," << alr.size() << std::endl;

        long long idxl = 0;
        long long idxr = 0;

        for (size_t i=0;i<alr.size();i++){
            if (idxl == al.size()) alr[i] = ar[idxr++];
            else if (idxr == ar.size()) alr[i] = al[idxl++];
            else if(al[idxl] > ar[idxr]) {
                std::cout << al[idxl] << "," << ar[idxr] << ":" << al.size() << "#" << idxl << std::endl;
                alr[i] = ar[idxr];
                
                //(this->numOfInversion)++;
                //std::cout << ar.size() << "," << idxr << std::endl;
                this->numOfInversion += al.size() - idxl;
                idxr++;

            }
            else {
                alr[i] = al[idxl];
                idxl++;
            }
        }

        return alr;
    }

    void cal(){
        std::ifstream readFile("testdata.txt");
        std::string text;

        std::vector<int> arr;

        while(getline (readFile, text)) {
            std::cout << text << std::endl; 
            arr.push_back(std::stoi(text));
        }

        std::vector<int> res = this->sep(arr,0,arr.size()-1);
        std::cout << this->numOfInversion << std::endl;

    }


    void cal_test(){
        std::vector<int> arr;
        
        // 3,2,1,4
        arr.push_back(3);
        arr.push_back(2);
        arr.push_back(1);
        arr.push_back(4);
        
        std::vector<int> res = this->sep(arr,0,arr.size()-1);

        std::cout << this->numOfInversion << std::endl;

    }    
};

int main() {
    MergeSort* mg = new MergeSort();
    mg->cal();
}
