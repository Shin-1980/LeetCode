class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ht = {}     # val:index

        for i, num in enumerate(nums):
            complement = target - num 
            if complement in ht:
                return [i, ht[complement]]
            else:
                ht[num] = i

        return []


#return indices of the two numbers such that they add up to target.
# - exactly one solution
# - You can return the answer in any order.