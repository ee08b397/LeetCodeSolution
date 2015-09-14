"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 60ms
"""
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        stack = [-1]
        rightmax=0;
        for i in range(len(height)-1,-1,-1):
            if rightmax < height[i]:
                stack.append(i)
                rightmax = height[i]
        leftmax=0
        sum=0
        for i in range(0,len(height)):
            if i == stack[len(stack)-1]:stack.pop()
            if stack[len(stack)-1] == -1:rightmax=-1;
            else:rightmax = height[stack[len(stack)-1]]
            if height[i] < leftmax and height[i] < rightmax:
                sum+=min(leftmax,rightmax) - height[i]
            leftmax = max(leftmax,height[i])
        return sum