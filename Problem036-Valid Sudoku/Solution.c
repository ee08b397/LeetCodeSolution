/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int map[10],i,j,k,l,num;
    if(boardRowSize!=9 || boardColSize!=9)return false;
    for(i=0;i<9;i++){
        memset(map,0,sizeof(map));
        for(j=0;j<9;j++){
            if(board[i][j]=='.')continue;
            if(board[i][j]<'0' || board[i][j]>'9')return false;
            num=board[i][j]-'0';
            if(map[num]!=0)return false;
            map[num]=1;
        }
    }
    for(j=0;j<9;j++){
        memset(map,0,sizeof(map));
        for(i=0;i<9;i++){
            if(board[i][j]=='.')continue;
            num=board[i][j]-'0';
            if(map[num]!=0)return false;
            map[num]=1;
        }
    }
    for(i=0;i<9;i+=3){
        for(j=0;j<9;j+=3){
            memset(map,0,sizeof(map));
            for(k=i;k<i+3;k++){
                for(l=j;l<j+3;l++){
                    if(board[k][l]=='.')continue;
                    num=board[k][l]-'0';
                    if(map[num]!=0)return false;
                    map[num]=1;
                }
            }
        }
    }
    return true;
}
