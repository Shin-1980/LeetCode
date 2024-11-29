class Solution {

    int backtruck(vector<int>& nums, int n, vector<int>& memo) {
        if (n < 0) return 0;
        if (memo[n] != -1) return memo[n];
        
        int pick = nums[n] + backtruck(nums, n-2, memo);
        int notPick = backtruck(nums, n-1, memo);
        memo[n] = max(pick, notPick);
            
        return memo[n];
    }

public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return backtruck(nums, nums.size()-1, memo);
    }
};
