class Solution {
public:
    bool check(vector<int>& nums) {
        bool isRotate = false;

        for (int i=1;i<nums.size();i++) {
            if (nums[i-1] > nums[i]) {
                if (!isRotate) isRotate = true;
                else return false; 
            }
        }

        if ((nums[0] < nums[nums.size()-1]) && (isRotate)) return false;
        
        return true;
        
    }
};

// 3,4,5,1,2
//   1 1 -4 1
// 1
