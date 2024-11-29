#include <vector>

class Solution {
private:

    std::vector<std::vector<char>> map;
    int maxR;
    int maxC;

    void search(int r, int c) {
        if (map[r][c] == '1') {
            map[r][c] = '2';
            if (r > 0) search(r-1,c);
            if (c > 0) search(r,c-1);
            if (r < maxR-1) search(r+1,c);
            if (c < maxC-1) search(r,c+1);
        }
   }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        maxR = size(grid);
        maxC = size(grid[0]);
        map = grid;

        for (int r=0;r<maxR;r++){
            for (int c=0;c<maxC;c++){
                map[r][c] = grid[r][c];
            }
        }

        int count = 0;

        for (int r=0;r<maxR;r++){
            for (int c=0;c<maxC;c++){
                if (map[r][c] == '1'){
                    count++;
                    search(r,c);
                }
            }
        }

        return count;
    }
};