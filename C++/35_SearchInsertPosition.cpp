using namespace std;
#include <vector>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;

        if (nums[nums.size()-1] < target) return nums.size();
        
        while (l<r) {
            int m = (r+l)/2;
            if (nums[m]==target) return m;
            else if(nums[m] < target) l = m + 1;
            else r = m;
        }

        return l;
    }
};