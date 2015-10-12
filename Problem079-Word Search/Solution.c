/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
bool wordSearch(char** board,int row,int col,char* word,int x,int y){
    int step[4][2]={-1,0,0,1,1,0,0,-1};
    int i,sx,sy;
    if(word[0]==0)return true;
    for(i=0;i<4;i++){
        sx=x+step[i][0];
        sy=y+step[i][1];
        if(sx<0 || sx >=row)continue;
        if(sy<0 || sy >=col)continue;
        if(board[sx][sy]==word[0]){
            board[sx][sy]=0;
            if(wordSearch(board,row,col,word+1,sx,sy))return true;
            board[sx][sy]=word[0];
        }
    }
    return false;
}
bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    int i,j;
    for(i=0;i<boardRowSize;i++){
        for(j=0;j<boardColSize;j++){
            if(board[i][j]==word[0]){
                board[i][j]=0;
                if(wordSearch(board,boardRowSize,boardColSize,word+1,i,j))return true;
                board[i][j]=word[0];
            }
        }
    }
    return false;
}
