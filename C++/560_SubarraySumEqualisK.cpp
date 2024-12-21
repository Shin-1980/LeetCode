using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        int sum=0;

        unordered_map<int, int> prefix;

        for (auto& num: nums){
            sum += num;

            if (sum == k) counter++;

            if (prefix.find(sum - k) !=　prefix.end()) {
                counter += prefix[sum - k];
            }

            prefix[sum]++;
        }
        
        return counter;
        
    }
};
