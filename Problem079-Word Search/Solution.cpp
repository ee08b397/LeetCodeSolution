/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 32ms
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = row==0?0:board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    board[i][j]=0;
                    if(wordSearch(board,word,1,i,j))return true;
                    board[i][j]=word[0];
                }
            }
        }
        return false;
    }
private:
    bool wordSearch(vector<vector<char>>& board,string word,int index,int x,int y){
        int step[4][2]={-1,0,0,1,1,0,0,-1};
        int row = board.size();
        int col = row==0?0:board[0].size();
        if(index >= word.size())return true;
        for(int i=0;i<4;i++){
            int sx = x+step[i][0];
            int sy = y+step[i][1];
            if(sx<0 || sx>=row)continue;
            if(sy<0 || sy>=col)continue;
            if(board[sx][sy]==word[index]){
                board[sx][sy]=0;
                if(wordSearch(board,word,index+1,sx,sy))return true;
                board[sx][sy]=word[index];
            }
        }
        return false;
    }
};
