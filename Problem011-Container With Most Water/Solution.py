"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 152ms
"""

class Solution:
    # @param {integer[]} height
    # @return {integer}
    def maxArea(self, height):
        Max=-1;l=0;r=len(height)-1
        while l<r:
            area=(height[l] if height[l]<height[r] else height[r])*(r-l)
            Max=Max if Max>area else area
            if height[l]<height[r]:
                k=l
                while l<r and height[l]<=height[k]:l+=1
            else:
                k=r
                while l<r and height[r]<=height[k]:r-=1
        return Max