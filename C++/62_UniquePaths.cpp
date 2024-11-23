class Solution {
public:
    int uniquePaths(int m, int n) {
        int map[m][n];
        for (int r=0;r<m;r++) map[r][n-1] = 1;
        for (int c=0;c<n;c++) map[m-1][c] = 1;

        for (int r=m-2;r>-1;r--){
            for (int c=n-2;c>-1;c--){
                map[r][c] = map[r+1][c] + map[r][c+1];
            }
        }

        return map[0][0];
    }
};

/*
return the number of possible unique paths that the robot can take to reach the bottom-right corner.

s 3 1
3 2 1
1 1 f

s = 6    

*/