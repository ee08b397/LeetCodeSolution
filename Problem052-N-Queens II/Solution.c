/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
void DFS(int step,int n,int* queens,int* returnSize){
    if(step == n){
        (*returnSize)++;
        return;
    }
    int i,j,x,y;
    for(i=0;i<n;i++){
        for(j=0;j<step;j++){
            x = abs(step - j);
            y = abs(i - queens[j]);
            if(x == y)break;
            if(x==0 || y==0)break;
        }
        if(j>=step){
            queens[step] = i;
            DFS(step+1,n,queens,returnSize);
        }
    }
}
int totalNQueens(int n) {
    int* returnSize = (int*)malloc(sizeof(int));
    (*returnSize) = 0;
    int* queens = (int*)malloc(sizeof(int)*n);
    DFS(0,n,queens,returnSize);
    return *returnSize;
}
