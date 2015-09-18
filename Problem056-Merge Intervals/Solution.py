"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 128ms
"""
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def compare(self,a,b):
        if a.start != b.start:
            return a.start - b.start
        return a.end - b.end
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        returnColumn = []
        if len(intervals) == 0:return returnColumn
        intervals = sorted(intervals,cmp=self.compare)
        returnColumn.append(Interval(intervals[0].start,intervals[0].end))
        top=0
        for i in range(1,len(intervals)):
            if intervals[i].start <= returnColumn[top].end:
                returnColumn[top].end = max(intervals[i].end,returnColumn[top].end)
            else:
                returnColumn.append(Interval(intervals[i].start,intervals[i].end))
                top+=1
        return returnColumn
        