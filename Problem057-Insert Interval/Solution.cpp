/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 580ms
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i,top=0,len = intervals.size();
        vector<Interval> returnColumn(len+1);
        if(intervals.size()==0){
            returnColumn[top++] = newInterval;
            return returnColumn;
        }
        for(i=0;i<len;i++){
            if(intervals[i].start >= newInterval.start){
                if(top==0 || returnColumn[top-1].end < newInterval.start){
                    returnColumn[top++] = newInterval;
                }else{
                    returnColumn[top-1].end = max(returnColumn[top-1].end,newInterval.end);
                }
                break;
            }
            returnColumn[top++] = intervals[i];
        }
        for(;i<len;i++){
            if(returnColumn[top-1].end >= intervals[i].start){
                returnColumn[top-1].end = max(returnColumn[top-1].end,intervals[i].end);
            }else{
                returnColumn[top++] = intervals[i];
            }
        }
        if(returnColumn[top-1].start < newInterval.start){
            if(returnColumn[top-1].end >= newInterval.start){
                returnColumn[top-1].end = max(returnColumn[top-1].end,newInterval.end);
            }else{
                returnColumn[top++] = newInterval;
            }
        }
        returnColumn.erase(returnColumn.begin()+top,returnColumn.end());
        return returnColumn;
    }
};
