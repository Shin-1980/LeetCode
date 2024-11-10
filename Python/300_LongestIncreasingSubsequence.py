class Solution(object):

    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def bt(nums, idx, curv, lgth, memo):
            if idx == len(nums):    # base 
                return lgth
            elif memo[idx] != 0:
                return memo[idx]
            else:
                mlgth = 0
                for i in range(idx,len(nums)):
                    if curv < nums[i]:
                        mlgth = max(mlgth, bt(nums,i+1,nums[i],lgth+1,memo))
                    
                memo[i] = mlgth

            return mlgth

        memo = [0 for _ in range(len(nums))]

        lgth = 0
        for i in range(len(nums)):
            lgth = max(lgth, bt(nums,i+1,nums[i],1,memo))
        
        return lgth
        
# 0,1,0,3,2,3
# 0,1,3
# 0(4),1(3),2(2),3(1)

# Backtracking algorithm
# time O(N^2)   N is number of nums
# memory O(N) 
# + memoization