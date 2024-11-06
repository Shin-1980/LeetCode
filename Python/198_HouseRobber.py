class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        sumOdd = 0
        sumEven = 0

        for i in range(len(nums)):
            if i % 2 == 0:
                sumOdd += nums[i]
            else:
                sumEven += nums[i]

        return max(sumOdd, sumEven)

# Algorithm: compare the sum of elements at odd indices with the sum of elements at even indices
# time: O(N)    N is the num of elements
# memory: O(N)