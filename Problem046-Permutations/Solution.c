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
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(int* nums,int numsSize,int step,int* prefix,int prefixSize,int** returnColumn,int* returnSize){
    if(step >= numsSize)return;
    if(step == numsSize-1){
        prefix[prefixSize] = nums[step];
        returnColumn[*returnSize] = (int*)malloc(sizeof(int)*numsSize);
        memcpy(returnColumn[*returnSize],prefix,sizeof(int)*numsSize);
        (*returnSize)++;
        return;
    }
    int i,tmp;
    for(i=step;i<numsSize;i++){
        if(i>step){
            tmp = nums[i];
            nums[i] = nums[step];
            nums[step] = tmp;
        }
        prefix[prefixSize] = nums[step];
        DFS(nums,numsSize,step+1,prefix,prefixSize+1,returnColumn,returnSize);
        if(i>step){
            tmp = nums[i];
            nums[i] = nums[step];
            nums[step] = tmp;
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize) {
    int** returnColumn = (int**)malloc(sizeof(int*)*100000);
    int* prefix = (int*)malloc(sizeof(int)*numsSize);
    *returnSize = 0;
    DFS(nums,numsSize,0,prefix,0,returnColumn,returnSize);
    return returnColumn;
}
