class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        ht = {}     # sub : index
        ht[target - nums[0]] = 0 

        for i in range(1, len(nums)):
            print(ht, i, nums[i])
            if nums[i] in ht:
                return [i, ht[nums[i]]]
            else:
                ht[target - nums[i]] = i

        return [0,0]

# use a hashtable
# time: O(N^2)  N is a number of arraies
# memory: O(N)
# advantage: efficiency        
