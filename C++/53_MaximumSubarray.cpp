using namespace std;
#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int total = nums[0];

        for (auto num:nums){
            sum = max(num, num + sum);
            total = max(sum, total);
        }

        return total;
    }
};

/*
 curT = max(num, curT+nums)
 maxT = max(maxT, curT)
*/
