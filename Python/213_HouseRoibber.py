class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        sum1 = sum2 = 0
        
        for i in range(len(nums)):
            if i % 2 == 0:
                sum1 += nums[i]
            else:
                sum2 += nums[i]

        if len(nums) % 2 == 1:
            sum1 = max(sum1-nums[0], sum1-nums[len(nums)-1])

        return max(sum1,sum2)

# the num of houses is odd, two cases are considered without head and without tail
