class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
        def calLengthOfLIS(nums: List[int], idx: int, mp: List[int]) -> int:
            if idx == len(nums) - 1:    # base case
                print(idx)
                return 0

            if mp[idx] > -1:
                return mp[idx]

            maxRes = 0

            for i in range(idx+1, len(nums)):
                if nums[idx] < nums[i]:
                    #print(nums[idx], nums[i])
                    maxRes = max(maxRes, calLengthOfLIS(nums, i, mp) + 1)

            mp[idx] = maxRes

            return mp[idx]

        mp = [-1 for _ in range(len(nums))]

        maxRes = 0
        for i in range(0, len(nums)):
            maxRes = max(maxRes, calLengthOfLIS(nums, i, mp) + 1)

        return maxRes
