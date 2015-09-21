/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 24ms
 */
int min(int a,int b){
    return a>b?b:a;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int i,j;
    for(i=0;i<gridRowSize;i++){
        for(j=0;j<gridColSize;j++){
            if(i==0 && j==0)continue;
            else if(i==0)grid[i][j]+=grid[i][j-1];
            else if(j==0)grid[i][j]+=grid[i-1][j];
            else grid[i][j]+=min(grid[i][j-1],grid[i-1][j]);
        }
    }
    return grid[gridRowSize-1][gridColSize-1];
}
