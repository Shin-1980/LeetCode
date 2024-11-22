class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curT = 0;
        int maxT = 0;

        for (auto num: nums) {
            curT = max(num, curT+num);
            maxT = max(curT, maxT);
        }
        
        return maxT;
    }
};

/*
 curT = max(num, curT+nums)
 maxT = max(maxT, curT)
*/
