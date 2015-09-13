"""
 @SEU(master);@ZZULI(bachelor)
 author:CuiXuan
 email:873059043@qq.com
 If you find any errors, please let me know.
 If you have any better solution, please let me know.

 Solution Using time 1842ms
"""

class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[][]}
    def fourSum(self, nums, target):
        length=len(nums)
        res=[]
        if length<4:return res
        nums=sorted(nums)
        for i in range(length-3):
            if i>0 and nums[i]==nums[i-1]:continue
            for j in range(i+1,length-2):
                if j>i+1 and nums[j]==nums[j-1]:continue
                begin=j+1;end=length-1
                while begin < end:
                    sum=nums[i]+nums[j]+nums[begin]+nums[end]
                    if sum==target:
                        temp=[nums[i],nums[j],nums[begin],nums[end]]
                        res.append(temp)
                        begin+=1;end-=1
                        while begin<end and nums[begin]==nums[begin-1]:begin+=1
                        while begin<end and nums[end]==nums[end+1]:end-=1
                    elif sum>target:
                        end-=1
                        while begin<end and nums[end]==nums[end+1]:end-=1
                    else:
                        begin+=1
                        while begin<end and nums[begin]==nums[begin-1]:begin+=1
        return res