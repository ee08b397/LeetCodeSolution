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
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a>b?b:a;
}
int cmp(const void* a,const void* b){
    struct Interval* s = (struct Interval*)a;
    struct Interval* t = (struct Interval*)b;
    if(s->start != t->start){
        return s->start - t->start;
    }else{
        return s->end - t->end;
    }
}
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int i,j;
    struct Interval* returnColumn = (struct Interval*)malloc(sizeof(struct Interval)*intervalsSize);
    *returnSize=0;
    if(intervalsSize <= 0)return returnColumn;
    qsort(intervals,intervalsSize,sizeof(struct Interval),cmp);
    returnColumn[*returnSize].start = intervals[0].start;
    returnColumn[*returnSize].end = intervals[0].end;
    returnSize[0]++;
    for(i=1;i<intervalsSize;i++){
        if(intervals[i].start <= returnColumn[*returnSize-1].end){
            returnColumn[*returnSize-1].end = max(returnColumn[*returnSize-1].end,intervals[i].end);
        }else{
            returnColumn[*returnSize].start = intervals[i].start;
            returnColumn[*returnSize].end = intervals[i].end;
            returnSize[0]++;
        }
    }
    return returnColumn;
}
