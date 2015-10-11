/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void getcombine(int** returnColumn,int* tmp,int step,int n,int k,int** columnSizes,int* returnSize){
    int i;
    if(step==k){
        columnSizes[0][*returnSize]=k;
        returnColumn[*returnSize]=(int*)malloc(sizeof(int)*k);
        memcpy(returnColumn[*returnSize],tmp,sizeof(int)*k);
        returnSize[0]++;
        return;
    }
    if(step<=0)i=1;
    else i=tmp[step-1]+1;
    for(;i<=n;i++){
        tmp[step]=i;
        getcombine(returnColumn,tmp,step+1,n,k,columnSizes,returnSize);
    }
}
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int** returnColumn = (int**)malloc(sizeof(int*)*100000);
    int* tmp = (int*)malloc(sizeof(int)*k);
    *returnSize=0;
    columnSizes[0] = (int*)malloc(sizeof(int)*100000);
    getcombine(returnColumn,tmp,0,n,k,columnSizes,returnSize);
    return returnColumn;
}
