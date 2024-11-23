class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int mR = obstacleGrid.size();
        int mC = obstacleGrid[0].size();
        long int map[mR][mC];

        for (int r=0;r<mR;r++){
            for (int c=0;c<mC;c++){
                map[r][c]=0;
            }
        }

        if (!obstacleGrid[mR-1][mC-1]) map[mR-1][mC-1] = 1;

        for (int r=mR-1;r>-1;r--){
            for (int c=mC-1;c>-1;c--){
                if (!obstacleGrid[r][c]){
                    if (r+1 < mR && !obstacleGrid[r+1][c]) {
                        if (r+1 < mR) map[r][c]+=map[r+1][c];
                    }
                    if (c+1 < mC && !obstacleGrid[r][c+1]) {
                        if (c+1 < mC) map[r][c]+=map[r][c+1];
                    }
                }
            //cout << r << c << map[r][c] << endl;
            }
        }

        return map[0][0];
    }
};

/*
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
an m x n integer array grid
move to the bottom-right corner
An obstacle and space are marked 

s 0 0
0 1 0
0 0 f

path = sum of the right and down value.
check whether the cell is obstable or not.

*/