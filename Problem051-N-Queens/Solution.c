/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 8ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(char** Column,int step,int n,int** queens,char*** returnColumn,int* returnSize){
    int i,j,x,y;
    if(step == n){
        returnColumn[*returnSize] = (char**)malloc(sizeof(char*)*n);
        for(i=0;i<n;i++){
            returnColumn[*returnSize][i] = (char*)malloc(sizeof(char)*(n+1));
            strcpy(returnColumn[*returnSize][i],Column[i]);
        }
        (*returnSize)++;
        return;
    }
    for(i=0;i<n;i++){
        for(j=0;j<step;j++){
            x = abs(queens[j][0] - step);
            y = abs(queens[j][1] - i);
            if(x == y)break;
            if(x == 0 || y ==0)break;
        }
        if(j>=step){
            queens[step][0] = step;
            queens[step][1] = i;
            Column[step][i] ='Q';
            DFS(Column,step+1,n,queens,returnColumn,returnSize);
            Column[step][i] = '.';
        }
    }
}
char*** solveNQueens(int n, int* returnSize) {
    char*** returnColumn = (char***)malloc(sizeof(char**)*100000);
    int** queens = (int**)malloc(sizeof(int*)*n);
    *returnSize=0;
    char** Column = (char**)malloc(sizeof(char*)*n);
    int i,j;
    for(i=0;i<n;i++){
        Column[i] = (char*)malloc(sizeof(char)*(n+1));
        queens[i] = (int*)malloc(sizeof(int)*2);
        for(j=0;j<n;j++){
            Column[i][j] = '.';
        }
        Column[i][j]=0;
    }
    DFS(Column,0,n,queens,returnColumn,returnSize);
    return returnColumn;
}
