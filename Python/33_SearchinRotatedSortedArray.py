class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        h = 0
        t = len(nums)-1
        pivot = 0

        if nums[h] == target:
            return h
        elif nums[t] == target:
            return t

        if nums[h] > nums[t]:
            while h<t:
                m = (h+t) // 2
                if nums[m] > nums[m+1]:
                    pivot = m+1
                    break

                if nums[h] > nums[m]:
                    t = m 
                else:
                    h = m             

        if nums[0] == target:
            return 0
        elif nums[pivot] == target:
            return pivot
        elif nums[len(nums)-1] == target:
            return len(nums)-1

        if pivot != 0 and nums[0] <= target <= nums[pivot - 1]:
            h = 0
            t = pivot
        elif nums[pivot] <= target <= nums[len(nums)-1]:
            h = pivot
            t = len(nums)-1
        else:
            return -1

        while h<t:
            m = (h+t) // 2
            if nums[h] == target:
                return h
            elif nums[m] == target:
                return m
            elif nums[t] == target:
                return t
        
            if nums[m] < target:
                h = m+1
            else:
                t = m-1

        return -1


# step1: find pivot
# step2: split array
# step3: find value

