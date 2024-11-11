class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int mrow = grid.size();
        int mcol = grid[0].size();

        for (int r=0;r<mrow;r++) {
            for (int c=0;c<mcol;c++) {
                if (grid[r][c] == '1') {
                    count++;
                    markGrid(grid,r,c,mrow,mcol);
                }
            }
        }
        return count;
    }

    void markGrid(vector<vector<char>>& grid, int r, int c, int mrow, int mcol) {
        //cout << r << c << mrow << mcol << std::endl;
        if (grid[r][c] != '1')  return; // base case
        else {
            grid[r][c] = '2'; // already searched
            if (0 <  r) markGrid(grid,r-1,c,mrow,mcol);
            if (0 <  c) markGrid(grid,r,c-1,mrow,mcol);
            if (r < mrow-1) markGrid(grid,r+1,c,mrow,mcol);
            if (c < mcol-1) markGrid(grid,r,c+1,mrow,mcol);
        } 

        return;
    }

};