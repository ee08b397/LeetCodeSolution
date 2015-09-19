/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 408ms
 */
/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        int i,top=0,len=intervals.size();
        List<Interval> returnColumn = new ArrayList<Interval>();
        if(len==0){
            returnColumn.add(newInterval);
            return returnColumn;
        }
        for(i=0;i<len;i++){
            Interval inter = intervals.get(i);
            if(inter.start >= newInterval.start){
                if(top==0 || returnColumn.get(top-1).end < newInterval.start){
                    returnColumn.add(newInterval);
                    top++;
                }else{
                    Interval ret = returnColumn.get(top-1);
                    ret.end = Math.max(ret.end,newInterval.end);
                    returnColumn.set(top-1,ret);
                }
                break;
            }
            returnColumn.add(inter);
            top++;
        }
        for(;i<len;i++){
            Interval inter = intervals.get(i);
            Interval ret = returnColumn.get(top-1);
            if(ret.end >= inter.start){
                ret.end = Math.max(ret.end,inter.end);
                returnColumn.set(top-1,ret);
            }else{
                returnColumn.add(inter);
                top++;
            }
        }
        Interval ret = returnColumn.get(top-1);
        if(ret.start < newInterval.start){
            if(ret.end >= newInterval.start){
                ret.end = Math.max(ret.end,newInterval.end);
                returnColumn.set(top-1,ret);
            }else{
                returnColumn.add(newInterval);
                top++;
            }
        }
        return returnColumn;
    }
}