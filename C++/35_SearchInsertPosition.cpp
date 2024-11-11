class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idxh = 0;                // head
        int idxt = nums.size()-1;    // tail

        if (nums[idxt] < target) return nums.size();

        while (idxh < idxt) {
            int idxm = (idxh + idxt) / 2;
            cout << idxm << endl;
            if (nums[idxm] == target) return idxm;
            else if (nums[idxm] < target) idxh = idxm + 1;
            else idxt = idxm;
        }

        return idxh;
    }
};