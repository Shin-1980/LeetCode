#include<iostream>

class Solution {

int backTruck(std::vector<int>& nums, int n, std::vector<int>& memo) {

    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];

    int pick = nums[n] + backTruck(nums, n-2, memo);
    int notPick = backTruck(nums, n-1, memo);
    memo[n] = std::max(pick, notPick);

    return memo[n];
}

public:
    int houseRobber(std::vector<int> nums) {
        std::vector<int> memo(nums.size(),-1);
        return backTruck(nums, nums.size()-1,memo);
    }
};

bool testCase1() {

    Solution* sl = new Solution();

    std::vector<int> nums;
    nums.push_back(100);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(100);
    // 2 + 4
    int ans = 200;

    //std::cout << nums.size() << std::endl;
    int res = sl->houseRobber(nums);

    if (ans == res) return true;

    return false; 
}

int main() {
    int count = 0;

    count++;
    if (testCase1()) std::cout << "PATH" << count << std::endl;
    else std::cout << "ERROR" << count << std::endl;

}