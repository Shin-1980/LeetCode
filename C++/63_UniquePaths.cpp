using namespace std;
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rMax = obstacleGrid.size();
        int cMax = obstacleGrid[0].size();
        long long grid[rMax][cMax];

        for (int r=0;r<rMax;r++){
            for (int c=0;c<cMax;c++) grid[r][c] = 0;
        }

        if (obstacleGrid[0][0] == 1 || obstacleGrid[rMax-1][cMax-1] == 1) return 0;

        grid[rMax-1][cMax-1] = 1;

        for(int r=rMax-1;r>-1;r--){
            for(int c=cMax-1;c>-1;c--){
                if (!obstacleGrid[r][c]) {
                    if (r+1 < rMax && !obstacleGrid[r+1][c]) grid[r][c] += grid[r+1][c];
                    if (c+1 < cMax && !obstacleGrid[r][c+1]) grid[r][c] += grid[r][c+1];
                }
            }
        }
        
        return grid[0][0];
    }
};