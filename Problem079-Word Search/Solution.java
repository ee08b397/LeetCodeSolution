/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 21ms
 */
public class Solution {
    public boolean exist(char[][] board, String word) {
        int row = board.length;
        int col = row==0?0:board[0].length;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word.charAt(0)){
                    board[i][j]=0;
                    if(wordSearch(board,word,1,i,j))return true;
                    board[i][j]=word.charAt(0);
                }
            }
        }
        return false;
    }
    private boolean wordSearch(char[][] board,String word,int index,int x,int y){
        int[][] step={{-1,0},{0,1},{1,0},{0,-1}};
        int row = board.length;
        int col = row==0?0:board[0].length;
        if(index >= word.length())return true;
        for(int i=0;i<4;i++){
            int sx = x+step[i][0];
            int sy = y+step[i][1];
            if(sx<0 || sx>=row)continue;
            if(sy<0 || sy>=col)continue;
            if(board[sx][sy]==word.charAt(index)){
                board[sx][sy]=0;
                if(wordSearch(board,word,index+1,sx,sy))return true;
                board[sx][sy]=word.charAt(index);
            }
        }
        return false;
    }
}