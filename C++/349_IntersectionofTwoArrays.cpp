using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ht1;
        unordered_set<int> ht2;

        for (auto& num:nums1) ht1.insert(num);
        for (auto& num:nums2) ht2.insert(num);

        vector<int> ans;

        for (auto& h1:ht1){
            if (ht2.count(h1)) ans.push_back(h1);
        }
        
        return ans;

    }
};