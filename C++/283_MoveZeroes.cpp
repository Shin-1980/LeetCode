using namespace std;
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int count = 0;

        for (auto num:nums){
            if (num != 0) {
                nums[count] = num;
                count++;
            }
        }

        for (int i=count;i<nums.size();i++){
            nums[i] = 0;
        }        
    }
};
