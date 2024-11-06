class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        ih = 0  # index of head
        it = len(nums) - 1  # index of tail

        if target > nums[len(nums) - 1]:
            return len(nums)


        while ih < it:
            im = (it - ih) // 2 + ih
            if target == nums[im]:
                return im
            elif target < nums[im]:
                it = im
            else:
                ih = im + 1

        return it

        