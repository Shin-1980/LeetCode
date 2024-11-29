class Solution(object):


    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        memo = [-1 for _ in range(len(nums))]

        print(memo)

        def bt(nums, n, memo):
            if n < 0: return 0
            if memo[n] != -1: return memo[n]

            pick = nums[n] + bt(nums,n-2,memo)
            notPick = bt(nums,n-1,memo)

            memo[n] = max(pick, notPick)

            return memo[n]

        return bt(nums,len(nums)-1,memo)