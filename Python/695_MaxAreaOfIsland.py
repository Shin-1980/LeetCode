class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        maxr = len(grid)
        maxc = len(grid[0])

        memo = [[0 for i in range(maxc)] for j in range(maxr)]

        for r in range(maxr):
            for c in range(maxc):
                memo[r][c] = grid[r][c]

        print(memo)
        
        def rf(grid, r, c, maxr, maxc):
            if grid[r][c] == 1:
                grid[r][c] = 2
                size = 1
                print(size)
                if r > 0:
                    size += rf(grid,r-1,c,maxr,maxc)
                if c > 0:
                    size += rf(grid,r,c-1,maxr,maxc)
                if r < maxr-1:
                    size += rf(grid,r+1,c,maxr,maxc)
                if c < maxc-1:
                    size += rf(grid,r,c+1,maxr,maxc)
            else:
                size = 0

            return size

        size = 0

        for r in range(maxr):
            for c in range(maxc):
                if memo[r][c] == 1:
                    size = max(size, rf(memo,r,c,maxr,maxc))

        return size


# algorithm is memoization
# time: O(M*N)
# memory: O(M*N)