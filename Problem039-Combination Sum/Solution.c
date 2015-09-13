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
void  quick_sort(int* candidates,int start,int end){
    if(start >= end)return;
    int temp = candidates[start];
    int i=start,j=end;
    while(i < j){
        while(j > i && candidates[j] >= temp)j--;
        if(j > i){
            candidates[i] = candidates[j];
        }
        while(j > i && candidates[i] < temp)i++;
        if(j > i){
            candidates[j] = candidates[i];
        }
    }
    candidates[i] = temp;
    quick_sort(candidates,start,i-1);
    quick_sort(candidates,i+1,end);
}

void com_Sum(int* candidates,int candidatesSize,int step,int target,int* prefix,int prefixSize,int** returnColumn,int **columnSizes,int* returnSize){
    if(step >= candidatesSize)return;
    if(target <= 0)return;
    int i;
    for(i=step;i<candidatesSize;i++){
        if(target < candidates[i])break;
        else if(target == candidates[i]){
			prefix[prefixSize] = candidates[i];
            returnColumn[*returnSize] = (int*)malloc(sizeof(int)*(prefixSize+1));
            columnSizes[0][*returnSize] = prefixSize+1;
            memcpy(returnColumn[*returnSize],prefix,sizeof(int)*(prefixSize+1));
            returnSize[0]++;
        }else{
            prefix[prefixSize] = candidates[i];
            com_Sum(candidates,candidatesSize,i,target-candidates[i],prefix,prefixSize+1,returnColumn,columnSizes,returnSize);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int i=1,j=1;
	int** returnColumn = (int**)malloc(sizeof(int*)*100000);
	*returnSize=0;
	int* prefix = (int*)malloc(sizeof(int)*100000);
    quick_sort(candidates,0,candidatesSize-1);
    for(i=1;i<candidatesSize;i++){
        if(candidates[i] != candidates[i-1]){
            candidates[j] = candidates[i];
            j++;
        }
    }
    candidatesSize = j;
    columnSizes[0] = (int*)malloc(sizeof(int)*100000);
    com_Sum(candidates,candidatesSize,0,target,prefix,0,returnColumn,columnSizes,returnSize);
    return returnColumn;
}
