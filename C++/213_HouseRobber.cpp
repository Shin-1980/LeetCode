using namespace std;
#include <vector>

class Solution {
public:
    int backtruck(vector<int>& nums, int cur, bool isFirst, vector<int>& memo) {
        if (cur >= nums.size()) return 0;
        if (cur == nums.size()-1 && isFirst) return 0;

        if (memo[cur] != -1) return memo[cur];

        memo[cur] = max(nums[cur]+backtruck(nums,cur+2,isFirst,memo), backtruck(nums,cur+1,isFirst,memo));

        return memo[cur];
    }

    int rob(vector<int>& nums) {
        vector<int> memo1(nums.size(),-1);
        vector<int> memo2(nums.size(),-1);

        return max(nums[0]+backtruck(nums,2,true,memo1), backtruck(nums,1,false,memo2));
    }
};
