/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 * 
 * Solution Using time 392ms
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
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> returnColumn = new ArrayList<Interval>();
        if(intervals.size() <= 0)return returnColumn;
        Collections.sort(intervals,new Comparator(){
            @Override
            public int compare(Object s,Object t){
                Interval a = (Interval)s;
                Interval b = (Interval)t;
                if(a.start != b.start){
                    return a.start - b.start;
                }else{
                    return a.end - b.end;
                }
            }
        });
        returnColumn.add(new Interval(intervals.get(0).start,intervals.get(0).end));
        int top=0;
        for(int i=1;i<intervals.size();i++){
            Interval val = intervals.get(i);
            Interval ret = returnColumn.get(top);
            if(val.start <= ret.end){
                ret.end = Math.max(ret.end,val.end);
                returnColumn.set(top,ret);
            }else{
                returnColumn.add(new Interval(val.start,val.end));
                top++;
            }
        }
        return returnColumn;
    }
}