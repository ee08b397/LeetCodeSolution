/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 12ms
 */
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void DFS(int* nums,int numsSize,int step,int* prefix,int* visited,int** returnColumn,int* returnSize){
    if(step >= numsSize){
        returnColumn[*returnSize] = (int*)malloc(sizeof(int)*numsSize);
        memcpy(returnColumn[*returnSize],prefix,sizeof(int)*numsSize);
        returnSize[0]++;
        return;
    }
    int i;
    for(i=0;i<numsSize;i++){
        if(visited[i])continue;
        if(i>0 && nums[i] == nums[i-1] && visited[i-1]==0)continue;
        visited[i] = 1;
        prefix[step] = nums[i];
        DFS(nums,numsSize,step+1,prefix,visited,returnColumn,returnSize);
        visited[i]=0;
    }
}
int cmp(const void *a,const void *b){
    return*(int*)a - *(int*)b;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int** returnColumn = (int**)malloc(sizeof(int*)*100000);
    int* visited = (int*)malloc(sizeof(int)*numsSize);
    int* prefix = (int*)malloc(sizeof(int)*numsSize);
    int i;
    for(i=0;i<numsSize;i++){
        visited[i]=0;
    }
    *returnSize=0;
    DFS(nums,numsSize,0,prefix,visited,returnColumn,returnSize);
    return returnColumn;
}
