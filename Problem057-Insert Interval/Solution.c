/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 572ms
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int min(int a,int b){
    return a>b?b:a;
}
int max(int a,int b){
    return a>b?a:b;
}
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int i;
    *returnSize = 0;
    struct Interval* returnColumn = (struct Interval*)malloc(sizeof(struct Interval)*(intervalsSize+1));
    for(i=0;i<intervalsSize;i++){
        if(intervals[i].start >= newInterval.start){
            if(*returnSize==0 || returnColumn[*returnSize-1].end < newInterval.start){
                returnColumn[*returnSize] = newInterval;
                returnSize[0]++;
            }else{
                returnColumn[*returnSize-1].end = max(returnColumn[*returnSize-1].end,newInterval.end);
            }
            break;
        }
        returnColumn[*returnSize] = intervals[i];
        returnSize[0]++;
    }
    for(;i<intervalsSize;i++){
        if(returnColumn[returnSize[0] - 1].end >= intervals[i].start){
            returnColumn[returnSize[0] - 1].start = min(returnColumn[returnSize[0]-1].start,intervals[i].start);
            returnColumn[returnSize[0] - 1].end = max(returnColumn[returnSize[0]-1].end,intervals[i].end);
        }else{
            returnColumn[*returnSize] = intervals[i];
            returnSize[0]++;
        }
    }
    if(returnColumn[returnSize[0]-1].end < newInterval.start){
        returnColumn[returnSize[0]++] = newInterval;
    }else if(returnColumn[returnSize[0]-1].start <= newInterval.start){
        returnColumn[returnSize[0]-1].end = max(returnColumn[returnSize[0]-1].end,newInterval.end);
    }
    return returnColumn;
}
