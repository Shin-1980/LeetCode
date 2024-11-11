class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> memo;
        vector<int> res;

        int idx = 0;
        for (auto num: nums) {
            //cout << memo.count(target - num) << std::endl;

            if (memo.count(target - num)) {
                return {memo[target - num], idx};
            }
            else {
                memo[num] = idx;
            }
            idx++;
        }

        return {};
        
    }
};