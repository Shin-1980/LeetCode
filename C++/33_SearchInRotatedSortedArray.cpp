using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int p;
        
        while(l<r) {
            if (nums[l]<nums[r]) {
                p = l;
                break;
            }
            int m = (l+r)/2;
            if (nums[r]<nums[m]) l = m+1;
            else r = m;     
        }

        if (nums[p] <= target && target <= nums[nums.size()-1]) {
            l = p;
            r = nums.size();
        }
        else {
            l = 0;
            r = p;
        }

        cout << p << endl;

        while (l<r) {
            int m = (l+r) / 2;
            if (nums[m]==target) return m;
            else if(nums[m] < target) l=m+1;
            else r = m;
        }

        return -1;
    }
};