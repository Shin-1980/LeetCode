class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        memo = [[0 for _ in range(n)] for _ in range(m)]

        memo[m-1][n-1] = 1

        for row in range(m-1,-1,-1):
            for col in range(n-1,-1,-1):
                if row < m-1:
                    memo[row][col] += memo[row+1][col]
                if col < n-1:
                    memo[row][col] += memo[row][col+1]
        
        return memo[0][0]

# algorithm: memoization
# calculate num of path from the bottom-right 
# each cell is calculated by two values of right and down cell 