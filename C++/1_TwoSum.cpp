#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ht;

        for(int i=0;i<nums.size();i++) {
            int comp = target - nums[i];
            if (ht.count(comp)) return {ht[comp], i};
            else ht[nums[i]] = i; 
        }

        return {};
    }
};
