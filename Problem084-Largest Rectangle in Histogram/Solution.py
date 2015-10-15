"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 88ms
"""
class Solution(object):
    def largestRectangleArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        stack = [0 for i in range(len(height))]
        max=0;top=0
        for i in range(len(height)):
            while top>0 and height[stack[top-1]]>height[i]:
                index = stack[top-1]
                top-=1
                area = (i if top<1 else i-stack[top-1]-1)*height[index]
                max = max if max>area else area
            stack[top]=i
            top+=1
        while top>0:
            index = stack[top-1]
            top-=1
            area = (len(height) if top<1 else len(height)-stack[top-1]-1)*height[index]
            max = max if max>area else area
        return max