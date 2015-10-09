/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 20ms
 */
public class Solution {
    public int minDistance(String word1, String word2) {
        int len1=word1.length(),len2=word2.length();
        if(len1==0 || len2==0)return len1+len2;
        int[][] dp = new int[len1][len2];
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                if(word1.charAt(i)==word2.charAt(j)){
                    if(i==0 && j==0)dp[i][j]=0;
                    else if(i==0)dp[i][j]=j;
                    else if(j==0)dp[i][j]=i;
                    else dp[i][j]=dp[i-1][j-1];
                }else{
                    if(i==0 && j==0)dp[i][j]=1;
                    else if(i==0)dp[i][j]=dp[i][j-1]+1;
                    else if(j==0)dp[i][j]=dp[i-1][j]+1;
                    else dp[i][j]=Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[len1-1][len2-1];
    }
}