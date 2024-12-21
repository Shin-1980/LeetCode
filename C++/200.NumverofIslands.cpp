#include <vector>

using namespace std;

class Solution {
public:
    void search(std::vector<std::vector<char>>& grid, size_t r, size_t c){
        if (r > 0 && grid[r-1][c] == '1') {
            grid[r-1][c] = '2';
            search(grid, r-1, c);
        }
        if (c > 0 && grid[r][c-1] == '1') {
            grid[r][c-1] = '2';
            search(grid, r, c-1);
        }
        if (r+1 < grid.size() && grid[r+1][c] == '1') {
            grid[r+1][c] = '2';
            search(grid, r+1, c);
        }
        if (c+1 < grid[0].size() && grid[r][c+1] == '1') {
            grid[r][c+1] = '2';
            search(grid, r, c+1);
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int num = 0;

        for (size_t r=0;r<grid.size();r++) {
            for (size_t c=0;c<grid[0].size();c++) {
                if (grid[r][c] == '1') {
                    num++;
                    search(grid,r,c);
                }
            }
        }

        return num;
    }
};