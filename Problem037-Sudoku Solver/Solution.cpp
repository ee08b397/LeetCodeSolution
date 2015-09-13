/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 24ms
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        SudoKu(board,0,0);
    }
private:
    bool SudoKu(vector<vector<char>>& board,int i,int j){
        if(i==8 && j==9)return true;
        if(j==9){
            i++;j=0;
        }
        if(board[i][j]!='.'){
            if(SudoKu(board,i,j+1))return true;
        }else{
            int* map=getValidNum(board,i,j);
            for(int k=1;k<10;k++){
                if(map[k]==0){
                    board[i][j]=k+'0';
                    if(SudoKu(board,i,j+1))return true;
                    board[i][j]='.';
                }
            }
        }
        return false;
    }
    int* getValidNum(vector<vector<char>>& board,int i,int j){
        int* map=(int*)malloc(sizeof(int)*10);
        memset(map,0,sizeof(int)*10);
        for(int k=0;k<9;k++){
            if(board[i][k]!='.')map[board[i][k]-'0']=1;
            if(board[k][j]!='.')map[board[k][j]-'0']=1;
        }
        for(int k=3*(i/3);k<3*(i/3)+3;k++){
            for(int l=3*(j/3);l<3*(j/3)+3;l++){
                if(board[k][l]!='.')map[board[k][l]-'0']=1;
            }
        }
        return map;
    }
};
