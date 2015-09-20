/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for(int i=0;i<m;i++){
            dp[i] = vector<int>(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=dp[i][j-1];
                else if(j==0)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
