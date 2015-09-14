/*
 * @SEU(master);@ZZULI(bachelor)
 * author:CuiXuan
 * email:873059043@qq.com
 * If you find any errors, please let me know.
 * If you have any better solution, please let me know.
 *
 * Solution Using time 4ms
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=0,tmp;
        for(i=0;i<nums.size();i++){
            if(nums[i] >0 && nums[i] <= nums.size()){
                if(nums[nums[i]-1] == nums[i])continue;
                tmp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
                i--;
            }
        }
        for(i=0;i<nums.size();i++){
            if(nums[i] != i+1)return i+1;
        }
        return i+1;
    }
};
