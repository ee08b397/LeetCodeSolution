/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int i,j;
    for(i=0;i<obstacleGridRowSize;i++){
        for(j=0;j<obstacleGridColSize;j++){
            if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=0;
            else if(i==0 && j==0)obstacleGrid[i][j]=1;
            else if(i==0)obstacleGrid[i][j]=obstacleGrid[i][j-1];
            else if(j==0)obstacleGrid[i][j]=obstacleGrid[i-1][j];
            else obstacleGrid[i][j]=obstacleGrid[i][j-1]+obstacleGrid[i-1][j];
        }
    }
    return obstacleGrid[obstacleGridRowSize-1][obstacleGridColSize-1];
}
