using namespace std;
#include <vector>

class Solution {
public:
    int lis(vector<int>& nums, int idx, vector<int>& ht){
        if (idx==0) return 1;
        if (ht[idx] != -1) return ht[idx];

        int mx=1;
        for(int pre=0;pre<idx;pre++){
            if (nums[pre] < nums[idx]) {
                mx = max(mx, lis(nums, pre, ht)+1);
            }
        }

        ht[idx] = mx;

        return ht[idx];
    }

    int lengthOfLIS(vector<int>& nums) {

        vector<int> ht(nums.size(),-1);
        int mx = 1;

        for(int i=0;i<nums.size();i++){
            mx = max(mx, lis(nums, i, ht));
        }

        return mx;
    }
};