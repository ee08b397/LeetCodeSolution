/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 320ms
 */
public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int i,j,k,l;
        if(board.length!=9 || board[0].length!=9)return false;
        int[] map;
        for(i=0;i<9;i++){
            map= new int[10];
            for(j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                if(board[i][j]<'0' || board[i][j]>'9')return false;
                int num=board[i][j]-'0';
                if(map[num]==1)return false;
                map[num]=1;
            }
        }
        for(j=0;j<9;j++){
            map=new int[10];
            for(i=0;i<9;i++){
                if(board[i][j]=='.')continue;
                int num=board[i][j]-'0';
                if(map[num]==1)return false;
                map[num]=1;
            }
        }
        for(i=0;i<9;i+=3){
            for(j=0;j<9;j+=3){
                map=new int[10];
                for(k=i;k<i+3;k++){
                    for(l=j;l<j+3;l++){
                        if(board[k][l]=='.')continue;
                        int num=board[k][l]-'0';
                        if(map[num]==1)return false;
                        map[num]=1;
                    }
                }
            }
        }
        return true;
    }
}