class Solution {
    
void backtrack(vector<int>& nums, vector<bool>& map, vector<int> cur, vector<vector<int>> &res) {

    if (cur.size() == nums.size()) {  // base
        res.push_back(cur);
        return;
    }

    for (int i=0;i<nums.size();i++) {
        if (!map[i]) {
            map[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, map, cur, res);
            map[i] = false;
            cur.pop_back();

        }
    }

    return;
}

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> map;

        for (int i=0;i<nums.size();i++) {
            map.push_back(false);
        }

        vector<int> cur;

        backtrack(nums, map, cur, res);

        return res;
    }
};


