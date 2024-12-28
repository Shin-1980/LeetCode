using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

enum PivotType {
  eFirst,
  eLast,
  eMedian
};

class Solution {

int median(vector<int>& arr,int low, int high) {
    int mid = (high + low) / 2;

    if (arr[low] > arr[mid] != arr[low] > arr[high]) return low;
    else if(arr[mid] > arr[low] != arr[mid] > arr[high]) return mid;
    else return high;
}

public:
    int partition(vector<int>& arr, int low, int high, PivotType type) {
        
        switch (type) {
            case eFirst:
                break;
            case eLast:
                swap(arr[low], arr[high]);
                break;
            case eMedian:
                int medianIndex = median(arr, low, high);
                swap(arr[low], arr[medianIndex]);
                break;
            defaule:
                break;
        }
        //int pivot = arr[high];
        //int mid = (low+high) / 2;
        //int pivot = arr[mid];
        
        int pivot = arr[low];

        int i = low + 1;

        for (int j = low + 1;j <= high; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        
        swap(arr[low], arr[i-1]);
        return i - 1;

    }

    void quickSort(vector<int>& arr, int low, int high, int& swapCount, PivotType type) {
        if (low < high) {
            swapCount += high - low;
            int pi = partition(arr, low, high, type);

            quickSort(arr, low, pi - 1, swapCount, type);
            quickSort(arr, pi + 1, high, swapCount, type);
        }
    }


};

void quickSort_test(){
    vector<int> arr;    
    arr.push_back(10);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(5);
    
    Solution* sl = new Solution();
    
    int swapCount = 0;
    sl->quickSort(arr, 0, arr.size()-1, swapCount, eFirst);

    for (auto element:arr) {
        cout << element << ",";
    }
    cout << endl;
    cout << "Count:" << swapCount << endl;
}

void quickSort_PivotWithFirst() {
    
    std::ifstream readFile("quicksort.txt");
    std::string text;

    std::vector<int> arr;

    while(getline (readFile, text)) {
        arr.push_back(std::stoi(text));
    }

    Solution* sl = new Solution();
    int swapCount = 0;
    sl->quickSort(arr, 0, arr.size()-1, swapCount, eFirst);

    cout << "Count:" << swapCount << endl;

}

void quickSort_PivotWithLast() {
    
    std::ifstream readFile("quicksort.txt");
    std::string text;

    std::vector<int> arr;

    while(getline (readFile, text)) {
        arr.push_back(std::stoi(text));
    }

    Solution* sl = new Solution();
    int swapCount = 0;
    sl->quickSort(arr, 0, arr.size()-1, swapCount, eLast);

    cout << "Count:" << swapCount << endl;

}

void quickSort_PivotWithMedian() {
    
    std::ifstream readFile("quicksort.txt");
    std::string text;

    std::vector<int> arr;

    while(getline (readFile, text)) {
        arr.push_back(std::stoi(text));
    }

    Solution* sl = new Solution();
    int swapCount = 0;
    sl->quickSort(arr, 0, arr.size()-1, swapCount, eMedian);

    cout << "Count:" << swapCount << endl;

}


int main() {

    quickSort_test();
    quickSort_PivotWithFirst();
    quickSort_PivotWithLast();
    quickSort_PivotWithMedian();

}