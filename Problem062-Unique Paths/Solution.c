/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
int uniquePaths(int m, int n) {
    int** dp = (int**)malloc(sizeof(int*)*m);
    int i,j;
    for(i=0;i<m;i++){
        dp[i] = (int*)malloc(sizeof(int)*n);
        for(j=0;j<n;j++){
            if(i==0 && j==0)dp[i][j]=1;
            else if(i==0)dp[i][j]=dp[i][j-1];
            else if(j==0)dp[i][j]=dp[i-1][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}
