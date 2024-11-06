class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        cash = [0 for i in range(len(nums)+1)]
        
        for i in range(len(nums)-1,-1,-1):
            val = nums[i] + cash[i+1]
            if val > 0:
                cash[i] = val
            else:
                cash[i] = nums[i]

        return max(cash)

# apply memoization to the solution
# Advantage: to skip duplicated caluculation
# time: O(N)    N is the number of the array
# memory: O(N)  needs array and cash 
        