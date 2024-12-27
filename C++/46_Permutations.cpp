using namespace std;
#include <vector>

class Solution {

vector<vector<int>> res;

public:
    void rec(vector<int>& nums, vector<int>& cur, vector<bool>& used) {
        if (nums.size() == cur.size()) {
            this->res.push_back(cur);
            return;
        }

        if (nums.size() == cur.size()) return;

        for (int i=0;i<nums.size();i++) {
            if (!used[i]) {
                used[i]=true;
                cur.push_back(nums[i]);
                rec(nums, cur, used);
                used[i]=false;
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        
        rec(nums, cur, used);

        return this->res;
    }
};