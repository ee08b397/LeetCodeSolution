class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer[]}
    def twoSum(self, nums, target):
        map={};
        for i in range(0,len(nums)):
            if map.has_key(target-nums[i]):
                return map[target-nums[i]],i+1
            map[nums[i]]=i+1
        return 0,0