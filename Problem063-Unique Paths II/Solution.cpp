/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row,col;
        row = obstacleGrid.size();
        if(row==0 || obstacleGrid[0].size()==0)return 0;
        col = obstacleGrid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
                else if(i==0 && j==0)obstacleGrid[i][j]=1;
                else if(i==0)obstacleGrid[i][j]=obstacleGrid[i][j-1];
                else if(j==0)obstacleGrid[i][j]=obstacleGrid[i-1][j];
                else obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
            }
        }
        return obstacleGrid[row-1][col-1];
    }
};
