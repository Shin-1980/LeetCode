class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        endPoint = nums[0]
        res = nums[0]

        for i in range(1,len(nums)):
            endPoint = max(endPoint+nums[i], nums[i])
            res = max(res, endPoint)

        return res

#kadane's algorithm
#nums       -2,1-3,4
#endPoint   -2,1,1,4
#res        -2,1,1,4

