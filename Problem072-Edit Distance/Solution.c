/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
int min(int a,int b){
    return a>b?b:a;
}
int minDistance(char* word1, char* word2) {
    int len1=0,len2=0,i,j;
    int** dp;
    while(word1[len1])len1++;
    while(word2[len2])len2++;
    if(len1==0)return len2;
    else if(len2==0)return len1;
    dp = (int**)malloc(sizeof(int*)*len1);
    for(i=0;i<len1;i++)dp[i] = (int*)malloc(sizeof(int)*len2);
    for(i=0;i<len1;i++){
        for(j=0;j<len2;j++){
            if(word1[i]==word2[j]){
                if(i==0 && j==0)dp[i][j]=0;
                else if(i==0)dp[i][j]=j;
                else if(j==0)dp[i][j]=i;
                else dp[i][j]=dp[i-1][j-1];
            }else{
                if(i==0 && j==0)dp[i][j]=1;
                else if(i==0)dp[i][j]=dp[i][j-1]+1;
                else if(j==0)dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
    }
    return dp[len1-1][len2-1];
}
