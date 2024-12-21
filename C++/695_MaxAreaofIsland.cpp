using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<vector<int>>& grid, int r, int c) {
        int numOfc = 0;

        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;

        if (grid[r][c] == 1) {
            numOfc++;
            grid[r][c] = 2;
            numOfc += search(grid,r-1,c);
            numOfc += search(grid,r+1,c);
            numOfc += search(grid,r,c-1);
            numOfc += search(grid,r,c+1);
        }

        return numOfc;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int numOfc = 0;

        for (size_t r=0;r<grid.size();r++) {
            for (size_t c=0;c<grid[0].size();c++) {
                if (grid[r][c] == 1){
                    numOfc = max(numOfc, search(grid,r,c));
                }
            }
        }
        
        return numOfc;
    }
};