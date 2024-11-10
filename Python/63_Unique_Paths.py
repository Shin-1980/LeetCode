class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """

        def isObs(obstacleGrid, row, col):
            if obstacleGrid[row][col] == 1:
                return True
            return False

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        memo = [[0 for _ in range(m)] for _ in range(n)]
        memo[m-1][n-1] = 1

        for row in range(m-1,-1,-1):
            for col in range(n-1,-1,-1):
                if isObs(obstacleGrid,row,col) == False:
                    if row < m-1:
                        memo[row][col] += memo[row+1][col]
                    if col < n-1:
                        memo[row][col] += memo[row][col+1]

        return memo[0][0]            

# algorithm: memoization
# unique paths can be calculated from the bottom-right
# must check if the cell is not an obstable
        