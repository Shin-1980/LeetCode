using namespace std;
#include <vector>

class Solution {
public:
    int backtruc(vector<int>& nums, int cur, vector<int>& memo){
        if(cur >= nums.size()) return 0;
        if (memo[cur] != -1) return memo[cur];

        memo[cur] = max(nums[cur] + backtruc(nums, cur+2, memo),  backtruc(nums, cur+1, memo));
        return memo[cur];
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);

        return rec(nums, 0, memo);        
    }
};
