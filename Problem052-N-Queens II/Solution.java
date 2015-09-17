/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 200ms
 */
public class Solution {
    public int totalNQueens(int n) {
        int[] queens = new int[n];
        int[] returnSize = new int[1];
        returnSize[0] = 0;
        DFS(0,n,queens,returnSize);
        return returnSize[0];
    }
    private void DFS(int step,int n,int[] queens,int[] returnSize){
        if(step == n){
            returnSize[0]++;
            return;
        }
        for(int i=0;i<n;i++){
            int j=0;
            for(;j<step;j++){
                int x = Math.abs(step - j);
                int y = Math.abs(i - queens[j]);
                if(x==y || x==0 || y==0)break;
            }
            if(j>=step){
                queens[step] = i;
                DFS(step+1,n,queens,returnSize);
            }
        }
    }
}