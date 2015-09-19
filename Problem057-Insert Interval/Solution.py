"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 84ms
"""
# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        i=0;length=len(intervals);top=0
        returnColumn = []
        if length==0:
            returnColumn.append(newInterval)
            return returnColumn
        while i<length:
            if intervals[i].start >= newInterval.start:
                if top==0 or returnColumn[top-1].end < newInterval.start:
                    returnColumn.append(newInterval)
                    top+=1
                else:
                    returnColumn[top-1].end = max(returnColumn[top-1].end,newInterval.end)
                break
            returnColumn.append(intervals[i])
            top+=1
            i+=1
        while i<length:
            if returnColumn[top-1].end >= intervals[i].start:
                returnColumn[top-1].end = max(returnColumn[top-1].end,intervals[i].end)
            else:
                returnColumn.append(intervals[i])
                top+=1
            i+=1
        if returnColumn[top-1].start < newInterval.start:
            if returnColumn[top-1].end >= newInterval.start:
                returnColumn[top-1].end = max(returnColumn[top-1].end,newInterval.end)
            else:
                returnColumn.append(newInterval)
                top+=1
        return returnColumn