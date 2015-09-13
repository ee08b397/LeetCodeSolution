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
void quick_sort(int* candidates,int start,int end){
    if(start >= end)return;
    int i=start,j=end,temp = candidates[start];
    while(i < j){
        while(i < j && candidates[j] >= temp)j--;
        if(i < j){
            candidates[i] = candidates[j];
        }
        while(i < j && candidates[i] < temp)i++;
        if(i < j){
            candidates[j] = candidates[i];
        }
    }
    candidates[i] = temp;
    quick_sort(candidates,start,i-1);
    quick_sort(candidates,i+1,end);
}
void DFS(int* candidates,int candidatesSize,int step,int target,int* prefix,int prefixSize,int** columnSizes,int* returnSize,int** returnColumn){
    if(step >= candidatesSize)return;
    if(target <=0 )return;
    int i;
    for(i=step;i<candidatesSize;i++){
        if(i>step && candidates[i] == candidates[i-1])continue;
        if(candidates[i] > target)return;
        else if(candidates[i] == target){
            returnColumn[*returnSize] = (int*)malloc(sizeof(int)*(prefixSize+1));
            prefix[prefixSize] = candidates[i];
            memcpy(returnColumn[*returnSize],prefix,sizeof(int)*(prefixSize+1));
            columnSizes[0][*returnSize] = prefixSize+1;
            (*returnSize)++;
            break;
        }else{
            prefix[prefixSize] = candidates[i];
            DFS(candidates,candidatesSize,i+1,target-candidates[i],prefix,prefixSize+1,columnSizes,returnSize,returnColumn);
        }
    }
}
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    quick_sort(candidates,0,candidatesSize-1);
    int** returnColumn = (int**)malloc(sizeof(int*)*100000);
    int* prefix = (int*)malloc(sizeof(int)*100000);
    columnSizes[0] = (int*)malloc(sizeof(int)*100000);
    returnSize[0] = 0;
    DFS(candidates,candidatesSize,0,target,prefix,0,columnSizes,returnSize,returnColumn);
    return returnColumn;
}
