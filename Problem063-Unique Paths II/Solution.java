/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 280ms
 */
public class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int row,col;
        row = obstacleGrid.length;
        col = obstacleGrid[0].length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
                else if(i==0 && j==0)obstacleGrid[i][j]=1;
                else if(i==0)obstacleGrid[i][j]=obstacleGrid[i][j-1];
                else if(j==0)obstacleGrid[i][j]=obstacleGrid[i-1][j];
                else obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[row-1][col-1];
    }
}