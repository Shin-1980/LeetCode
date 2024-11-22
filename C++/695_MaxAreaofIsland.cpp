class Solution {

private:
    int mr;
    int mc;

    int searchIsland(vector<vector<int>>& grid, int r, int c) {
        if (r < 0) return 0;
        else if (r > this->mr - 1) return 0;
        else if (c < 0) return 0;
        else if (c > this->mc - 1) return 0;

        int res = 0;

        if (grid[r][c] == 1) {
            grid[r][c] = 2;
            res = 1;
            res += searchIsland(grid,r-1,c);
            res += searchIsland(grid,r,c-1);
            res += searchIsland(grid,r+1,c);
            res += searchIsland(grid,r,c+1);
        }

        return res;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->mr = grid.size();
        this->mc = grid[0].size();

        int maxArea = 0;

        for (int r=0; r<this->mr; r++) {
            for (int c=0; c<this->mc; c++) {
                maxArea = max(searchIsland(grid, r, c), maxArea);
            }
        }

        return maxArea;
    
    }
};