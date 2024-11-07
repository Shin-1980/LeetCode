class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """

        maxr = len(grid)
        maxc = len(grid[0])

        memo = [[0 for j in range(maxc)] for i in range(maxr)]

        for r in range(maxr):
            for c in range(maxc):
                memo[r][c] = grid[r][c]

        print(memo)

        def rf(grid, r, c, maxr, maxc):
            if grid[r][c] == '1':
                grid[r][c] = '2'
                if r > 0:
                    rf(grid, r-1, c, maxr, maxc)
                if c > 0:
                    rf(grid, r, c-1, maxr, maxc)
                if r < maxr-1:
                    rf(grid, r+1, c, maxr, maxc)
                if c < maxc-1:
                    rf(grid, r, c+1, maxr, maxc)
            return

        count = 0

        for r in range(maxr):
            for c in range(maxc):
                if memo[r][c] == '1':
                    count += 1
                    rf(memo,r,c,maxr,maxc)
        
        return count


# Algorithm: Dynamic programming
# marked the island that was found previous
# time: O(M*N)
# memory: O(M*N)
        