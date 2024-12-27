using namespace std;
#include <vector>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minLen = INT_MAX;
        int sum = 0;

        for(int r=0;r<nums.size();r++) {
            sum += nums[r];
            while (sum >= target) {
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
            }
        }

        if (minLen == INT_MAX) return 0;
        return minLen;
        
    }
};