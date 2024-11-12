class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        h = 0
        t = len(nums)-1

        while nums[h] > nums[t]:
            m = (h + t ) // 2
            if nums[m] > nums[m+1]:
                return nums[m+1]

            if nums[h] > nums[m]:
                t = m
            else:
                h = m

        return nums[0]
        
# if head < tail no rotation
# head > tail: head > middle or middle > tail