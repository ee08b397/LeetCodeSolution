/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 540ms
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
    static bool cmp(const Interval& a,const Interval& b){
        if(a.start != b.start){
            return a.start < b.start;
        }else{
            return a.end < b.end;
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> returnColumn;
        if(intervals.size() <=0)return returnColumn;
        sort(intervals.begin(),intervals.end(),cmp);
        returnColumn.push_back(Interval(intervals[0].start,intervals[0].end));
        int top=0;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i].start <= returnColumn[top].end){
                returnColumn[top].end = max(intervals[i].end,returnColumn[top].end);
            }else{
                returnColumn.push_back(Interval(intervals[i].start,intervals[i].end));
                top++;
            }
        }
        return returnColumn;
    }
};
