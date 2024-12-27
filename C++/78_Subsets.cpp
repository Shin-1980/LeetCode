using namespace std;
#include <vector>

class Solution {
vector<vector<int>> res;

public:
    void rec(vector<int>& nums, vector<int>& cur, int idx) {
        if (idx == nums.size()) {
            this->res.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        rec(nums,cur,idx+1);
        cur.pop_back();
        rec(nums,cur,idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        rec(nums,cur,0);

        return this->res;
    }
};