class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        memo = [0 for i in range(len(prices)+1)]
        ret = 0

        for i in range(len(prices)-1,-1,-1):
            ret = max(ret, memo[i+1]-prices[i])
            memo[i] = max(prices[i], memo[i+1])

        return ret

# apply memoization to this solution
# cash max value backward
# time: O(N)  N is the number of the array
# memory: O(N)  the array and cash
