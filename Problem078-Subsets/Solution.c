/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 0ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void getSubset(int** returnColumn,int* tmp,int step,int index,int* nums,int numsSize,int k,int** columnSizes,int* returnSize){
    int i;
    if(step==k){
        columnSizes[0][*returnSize]=k;
        returnColumn[*returnSize] = (int*)malloc(sizeof(int)*k);
        memcpy(returnColumn[*returnSize],tmp,sizeof(int)*k);
        returnSize[0]++;
        return;
    }
    for(i=index+1;i<=numsSize-k+step;i++){
        tmp[step]=nums[i];
        getSubset(returnColumn,tmp,step+1,i,nums,numsSize,k,columnSizes,returnSize);
    }
}
int cmp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    int** returnColumn = (int**)malloc(sizeof(int*)*(1<<numsSize));
    int* tmp = (int*)malloc(sizeof(int)*numsSize);
    columnSizes[0]=(int*)malloc(sizeof(int)*(1<<numsSize));
    *returnSize=0;
    int i=0;
    qsort(nums,numsSize,sizeof(nums[0]),cmp);
    for(i=0;i<=numsSize;i++){
        getSubset(returnColumn,tmp,0,-1,nums,numsSize,i,columnSizes,returnSize);
    }
    return returnColumn;
}
