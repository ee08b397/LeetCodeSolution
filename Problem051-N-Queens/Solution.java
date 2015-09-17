/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 256ms
 */
public class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> returnColumn = new ArrayList<List<String>>();
        int[] queens = new int[n];
        char[][] column = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                column[i][j] = '.';
            }
        }
        DFS(column,0,n,queens,returnColumn);
        return returnColumn;
    }
    private void DFS(char[][] column,int step,int n,int[] queens,List<List<String>> returnColumn){
        if(step == n){
            List<String> newColumn = new ArrayList<String>();
            for(int i=0;i<n;i++){
                newColumn.add(new String(column[i]));
            }
            returnColumn.add(newColumn);
            return;
        }
        for(int i=0;i<n;i++){
            int j;
            for(j=0;j<step;j++){
                int x = Math.abs(step - j);
                int y = Math.abs(i - queens[j]);
                if(x == y)break;
                if(x==0 || y==0)break;
            }
            if(j>=step){
                queens[step] = i;
                column[i][j] = 'Q';
                DFS(column,step+1,n,queens,returnColumn);
                column[i][j] = '.';
            }
        }
    }
}